using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 * Part of cosmos from OpenGenus Foundation
 * */
namespace fcfs
{
    /// <summary>
    /// Class FCFS will take two inputs, process
    /// </summary>
    class FCFS
    {
        int[] processes;  // to store process id
        int[] bursts;  // to store process
        int[] ta;      // to store turn arround time
        int[] wt;      // to store awating time
        public FCFS(int[] processes,int[] bursts)
        {
            this.processes = processes;
            this.bursts = bursts;
            ta = get_ta();
            wt = get_wt();
        }

        /// <summary>
        /// Private method to get an array of turn arround time
        /// </summary>
        /// <returns></returns>
        int[] get_ta()
        {
            int[] temp = new int[bursts.Length];
            temp[0] = bursts[0];
            for (int i = 1; i < bursts.Length; i++)
            {
                temp[i] = temp[i - 1] + bursts[i];
            }
            return temp;
        }
        /// <summary>
        /// Private Method to get an array of waiting time
        /// </summary>
        /// <returns></returns>
        int[] get_wt()
        {
            int[] temp = new int[bursts.Length];
            temp[0] = 0;
            for (int i = 1; i < bursts.Length; i++)
            {
                temp[i] = temp[i - 1] + bursts[i];
            }
            return temp;
        }
        /// <summary>
        /// Method returning average waiting time
        /// </summary>
        /// <returns></returns>
        public int get_avg_wt()
        {
            return Convert.ToInt32(wt.Average());
        }
        /// <summary>
        /// Method returning average turn arround time
        /// </summary>
        /// <returns></returns>
        public int get_avg_ta()
        {
            return Convert.ToInt32(ta.Average());
        }

        /// <summary>
        /// Method to print all process_id -> burst_time -> waiting_time -> turn_arround
        /// </summary>
        public void print_process()
        {
            Console.WriteLine("FORMAT : process_id -> burst_time -> waiting_time -> turn_arround");
           for(int i = 0; i < processes.Length; i++)
            {
                Console.WriteLine("{0} -> {1} -> {2} -> {3}", processes[i], bursts[i], wt[i], ta[i]);
            }
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            // int array to store process ids
            int[] processes = { 1, 2, 3 };
            // int array to store burst times
            int[] burts = { 10, 5, 8 };

            FCFS fcfs = new FCFS(processes, burts);
            fcfs.print_process();
            Console.WriteLine("Average Waiting time : {0}",fcfs.get_avg_wt());
            Console.WriteLine("Average Turn Arround time : {0}", fcfs.get_avg_ta());

            Console.ReadKey();
        }
    }
}
