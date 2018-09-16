/**
 * Schedule for running MLFQ simulations and genarating data
 * https://github.com/Spensaur-K/mlfq-viz
 */

/**
 * Config to create a job
 */
interface JobConfig {
   id: number;
   createTime: number;
   flags: {}[];
   runTime: number;
   ioFreq: number;
   ioLength: number;
}

/**
 * A single job in the simulation
 */
class Job {
   // Usage determined fields
   flags: {}[];
   // Values the job is created with
   init: {
      // unique job id
      id: number;
      // Time when job was created
      createTime: number;
      // Total time job needs to spend on CPU to finish
      runTime: number;
      // Period of cycles that a job will perform IO
      ioFreq: number;
      // How long this job performs IO for
      ioLength: number;
   };
   // values collected once turing the jobs lifetime
   perf: {
      // Time it took from when job was created to be scheduled
      responseTime: number;
      // total time from when job was created till it finished
      turnaroundTime: number;
   };
   // values that vary as the job runs
   running: {
      // Which queue job is in
      priority: number;
      // Time job has spent on the CPU
      serviceTime: number;
      // Whether the job has finished yet
      isFinished: boolean;
      // Value that starts = to time quantum and deplets as job is run
      // Forces a context switch and resets when it reaches 0
      quantumLeft: number;
      // Amount of time quantum a job has when it is first assigned a new time quantum
      quantumFull: number;
      // Total time a job has waited for in queue
      totalWaitingTime: number;
      // Current time job has waited in queue, resets on cpu
      waitingTime: number;
      // Amount of ticks left to complete io, 0 if job isn't performing io
      ioLeft: number;
      // Cycles until job performs IO
      ioFreqLeft: number;
      // Average priority over job's lifetime
      avgPriority: number;
   };

   /**
    * Lowers the job's priority and reset its time quantum
    * @param priority to set as
    * @param quantum to use
    */
   lowerPriority(priority: number, quantum: number) {
      this.running.quantumLeft = quantum;
      this.running.quantumFull = quantum;
      this.running.priority = priority;
   }
   /**
    * Boost the job's priority and reset its time quantum
    * @param quantum to use
    */
   setQuantum(quantum: number) {
      this.running.quantumLeft = quantum;
      this.running.quantumFull = quantum;
      this.running.priority = 0;
   }

   /**
    * Reset a job's time quantum to full without changing priority
    */
   resetTQ() {
      this.running.quantumLeft = this.running.quantumFull;
   }

   /**
    * Increment the job's waiting time and recalculate it's average priority
    */
   wait() {
      const oldSum = this.running.avgPriority * this.running.totalWaitingTime;
      this.running.totalWaitingTime++;
      this.running.waitingTime++;
      this.running.avgPriority = (oldSum + this.running.priority) / this.running.totalWaitingTime;
   }

   /**
    * Simulate this job on the CPU
    * May start IO
    * @param globalTick number of ticks since the simulation started
    */
   doWork(globalTick: number) {
      this.running.waitingTime = 0;
      if (this.perf.responseTime === -1)
         this.perf.responseTime = globalTick - this.init.createTime;
      this.running.serviceTime++;
      this.running.quantumLeft--;
      if (this.running.serviceTime < 0 ||
         this.running.quantumLeft < 0 ||
         this.running.ioLeft > 0) {
         throw new Error("Job was not meant to be run");
      }
      if (this.running.serviceTime === this.init.runTime) {
         this.perf.turnaroundTime = globalTick - this.init.createTime + 1;
      } else if (this.running.serviceTime > this.init.runTime) {
         throw new Error("job missed finish");
      } else if (!this.quantumExpired()) {
         this.maybeStartIO();
      }
   }
   /**
    * Return whether jobs time quantum has run out
    */
   quantumExpired() {
      return this.running.quantumLeft === 0;
   }

   /**
    * Check if the job is finished
    */
   isFinished(): boolean {
      if (this.perf.turnaroundTime !== -1) {
         this.running.isFinished = true;
      }
      return this.running.isFinished;
   }
   /**
    * Simulate this job doing IO
    * @throws if job has no IO left
    */
   doIO() {
      if (!this.doingIO())
         throw new Error("job not doing IO");
      this.running.ioLeft--;
   }
   /**
    * Checks if job should start now, throws if it missed its start
    * @param globalTick number of ticks since the simulation started
    */
   shouldStart(globalTick: number): boolean {
      if (this.init.createTime === globalTick) {
         return true;
      }
      if (this.init.createTime < globalTick) {
         throw new Error("Job missed start");
      }
      return false;
   }
   /**
    * Sometimes starts performing IO (uses IO freq)
    */
   private maybeStartIO() {
      this.running.ioFreqLeft--;
      if (this.running.ioFreqLeft <= 0) {
         this.running.ioLeft = this.init.ioLength;
         this.running.ioFreqLeft = this.init.ioFreq;
      }
   }
   /**
    * Returns whether job is performing IO
    */
   doingIO(): boolean {
      return this.running.ioLeft > 0;
   }
   constructor({ createTime, runTime, ioFreq, ioLength, id, flags }: JobConfig) {
      this.flags = flags;
      this.init = {
         id,
         createTime,
         runTime,
         ioFreq,
         ioLength
      };
      this.perf = {
         responseTime: -1,
         turnaroundTime: -1
      };
      this.running = {
         priority: 0,
         isFinished: false,
         serviceTime: 0,
         quantumLeft: 0,
         quantumFull: 0,
         ioLeft: 0,
         ioFreqLeft: ioFreq,
         totalWaitingTime: 0,
         waitingTime: 0,
         avgPriority: 0
      };
   }
}

/**
 * Config for Scheduler
 */
interface Configuration {
   timeQuantums: number[];
   resetTQsOnIO: boolean;
   boostTime: number;
   speed: number;
   generation: {
      ioFrequencyRange: [number, number];
      ioLengthRange: [number, number];
      jobRuntimeRange: [number, number];
      numJobsRange: [number, number];
      jobCreateTimeRange: [number, number];
      // usage determined flags added to all jobs in generation
      flags: {}[] | void;
   }[];
}


interface Queue {
   timeQuantum: number;
   priority: number;
   jobs: Job[];
}

/**
 * MLFQ Simulator
 */
export default class Scheduler {
   // How many priority levels
   numQueues: number;
   // How often to boost job priorities
   boostTime: number;
   boostLeft: number;
   queues: Queue[];
   cpuJob: Job | undefined;

   private config: Configuration;

   // jobs that have not yet entered a queue
   private futureJobs: Job[];

   // jobs that have been completed
   private finishedJobs: Job[];

   // jobs doing io
   private ioJobs: Job[];

   // How often, in real ms, to tick the scheduler
   private speed: number;
   public running: boolean;
   private tickIntervalId: number;

   // How many ticks the scheduler has performed
   public globalTick: number;

   /**
    * Create a scheduler with a queue for each given time quantum
    * and a global boost time
    */
   constructor(config: Configuration) {
      this.finishedJobs = [];
      this.futureJobs = [];
      this.cpuJob = undefined;
      this.ioJobs = [];
      this.speed = config.speed;
      this.numQueues = config.timeQuantums.length;
      this.queues = config.timeQuantums.map((q, i) => ({
         timeQuantum: q,
         jobs: [],
         priority: i
      }));
      this.configure(config);
      this.globalTick = 1;
   }

   /**
    * Reinitialize queues after queue num change
    */
   reshapeQueues() {
      throw new Error("Not Implemented Yet");
   }

   /**
    * Runs the scheduler
    */
   play(update: { (data: Scheduler): void }) {
      if (this.running)
         throw new Error("Scheduler is already running!");
      const tick = () => {
         this.tickIntervalId = setTimeout(tick, this.speed);
         if (!this.processJobs()) {
               clearTimeout(this.tickIntervalId);
               this.tickIntervalId = setTimeout(tick, 0);
         }
         update(this);
      };
      this.tickIntervalId = setTimeout(tick, 0);
   }

   /**
    * Plays only the next step of simulation
    */
   playNext(update: { (data: Scheduler): void }) {
      if (this.running)
         throw new Error("Scheduler is already running!");
      this.processJobs();
      update(this);
   }

   /**
    * Returns whether simulation is finished
    */
   get simulationFinished(): boolean {
      if (this.futureJobs.length || this.ioJobs.length || this.cpuJob)
         return false;
      for (const queue of this.queues) {
         if (queue.jobs.length)
            return false;
      }
      return true;
   }

   /**
    * Boost all jobs
    */
   boostJobs() {
      this.queues[0].jobs = Array.prototype.concat(
         ...this.queues.map(q => q.jobs)
      );
      for (let i = 1; i < this.queues.length; i++) {
         this.queues[i].jobs = [];
      }
      for (const job of this.allJobs) {
         if (!job.isFinished()) {
            job.setQuantum(this.queues[0].timeQuantum);
         }
      }
   }
   /**
    * Configure the schedule
    */
   configure(config: Configuration) {
      const { timeQuantums, boostTime } = config;
      this.config = config;
      this.boostTime = boostTime;
      this.boostLeft = boostTime;
      // reset the queues if numbers changed
      if (this.numQueues !== config.timeQuantums.length) {
         this.boostJobs();
         const firstQueue = this.queues[0].jobs;
         this.queues = config.timeQuantums.map((q, i) => ({ timeQuantum: q, jobs: [], priority: i }));
         this.queues[0].jobs = firstQueue;
      }
      this.numQueues = timeQuantums.length;
   }

   /**
    * Put jobs that have finished IO back in their queues
    * @returns whether any jobs finished IO
    */
   finishIO(): boolean {
      let didFinish = false;
      for (let i = this.ioJobs.length - 1; i >= 0; i--) {
         const job = this.ioJobs[i];
         if (!job.doingIO()) {
            this.ioJobs.splice(i, 1);
            this.queues[job.running.priority].jobs.push(job);
            didFinish = true;
         }
      }
      return didFinish;
   }

   /**
    * performs IO for all IO jobs
    */
   doIO() {
      for (const job of this.ioJobs) {
         job.doIO();
      }
   }

   /**
    * Stop the scheduler
    */
   stop() {
      this.running = false;
      clearTimeout(this.tickIntervalId);
      this.tickIntervalId = -1;
   }

   /**
    * Add futureJobs to queue 1
    * @param globalTick scheduler tick
    */
   startJobs(globalTick: number) {
      for (let i = this.futureJobs.length - 1; i >= 0; i--) {
         const job = this.futureJobs[i];
         if (job.shouldStart(globalTick)) {
            this.futureJobs.splice(i, 1);
            job.setQuantum(this.queues[0].timeQuantum);
            this.queues[0].jobs.push(job);
         }
      }
   }

   /**
    * Get all the jobs in the scheduler
    * @return a new array containing every job
    */
   get allJobs(): Job[] {
      const sorted = (this.cpuJob ? [this.cpuJob] : ([] as Job[])).concat(
         ...this.ioJobs,
         ...this.futureJobs,
         ...this.finishedJobs,
         ...this.queues.map(q => q.jobs))
         .sort((a, b) => {
            return a.init.id > b.init.id ? 1 : -1;
         });
      return sorted;
   }

   /**
    * Process the jobs in the scheduler
    * @returns whether any state changed that should be animated
    */
   processJobs(): boolean {
      let stateChanged = false;
      if (!this.simulationFinished) {
         this.boostLeft--;
         if (this.boostLeft <= 0) {
            this.boostJobs();
            this.boostLeft = this.boostTime;
         }
         this.doIO();
         stateChanged = stateChanged || this.finishIO();
         this.startJobs(this.globalTick);
         stateChanged = stateChanged || this.processCpuJob();
         stateChanged = stateChanged || this.initCpuJob();
         this.waitJobs();
         this.globalTick++;
      }
      if (this.simulationFinished) {
         this.stop();
      }
      return stateChanged;
   }

   /**
    * Increment the waiting timer of all jobs that are waiting in
    * a queue
    */
   waitJobs() {
      for (const queue of this.queues) {
         for (const job of queue.jobs) {
            if (job !== this.cpuJob) {
               job.wait();
            }
         }
      }
   }

   /**
    * Loads the next job onto the CPU
    * unless there's one already there
    * @return whether a new job was loaded
    */
   initCpuJob(): boolean {
      if (!this.cpuJob) {
         this.cpuJob = this.popNextJob();
         return this.cpuJob != undefined;
      }
      return false;
   }

   /**
    * Process a single job on the cpu
    * @returns whether CPU state changed
    */
   processCpuJob(): boolean {
      let stateChanged = false;
      if (this.cpuJob) {
         this.cpuJob.doWork(this.globalTick);
         if (this.cpuJob.isFinished()) {
            this.finishedJobs.push(this.cpuJob);
            this.cpuJob = undefined;
            stateChanged = true;
         }
         else if (this.cpuJob.quantumExpired()) {
            const lastQueue = this.numQueues - 1;
            const lowerPriority = this.cpuJob.running.priority === (lastQueue) ? lastQueue : this.cpuJob.running.priority + 1;
            this.cpuJob.lowerPriority(lowerPriority, this.queues[lowerPriority].timeQuantum);
            this.queues[this.cpuJob.running.priority].jobs.push(this.cpuJob);
            this.cpuJob = undefined;
            stateChanged = true;
         }
         else if (this.cpuJob.doingIO()) {
            if (this.config.resetTQsOnIO) {
               this.cpuJob.resetTQ();
            }
            this.ioJobs.push(this.cpuJob);
            this.cpuJob = undefined;
            stateChanged = true;
         } else {
            this.cpuJob = this.cpuJob;
         }
      } else {
         // IDLE
      }
      return stateChanged;
   }

   /**
    * Generate jobs based on the scheduler's config
    */
   generateJobs() {
      this.futureJobs = [];
      let id = 1;
      this.config.generation.forEach(generate => {
         const {
            numJobsRange,
            jobCreateTimeRange,
            ioFrequencyRange,
            ioLengthRange,
            jobRuntimeRange,
            flags
         } = generate;
         function ran([lower, upper]: number[]) {
            const diff = upper - lower;
            return lower + (Math.random() * diff);
         }
         const numJobs = ran(numJobsRange);
         for (let i = 0; i <= numJobs; i++) {
            this.futureJobs.push(new Job({
               id: id++,
               flags: flags || [],
               createTime: ran(jobCreateTimeRange),
               runTime: ran(jobRuntimeRange),
               ioFreq: ran(ioFrequencyRange),
               ioLength: ran(ioLengthRange),
            }));
         }
      });
   }

   /**
    * Removes the job the should be run next from it's queue
    * return undefined if theyre no jobs to run
    */
   private popNextJob(): Job | undefined {
      for (const queue of this.queues) {
         if (queue.jobs.length > 0) {
            return queue.jobs.shift();
         }
      }
   }
}
