import java.util.Arrays;
import java.util.Comparator;

class Job {
    char id;
    int deadline, profit;

    public Job(char id, int deadline, int profit) {
        this.id = id;
        this.deadline = deadline;
        this.profit = profit;
    }
}

public class job_sequencing {

    public static void printJobSequence(Job[] jobs) {
        // Sort jobs based on decreasing order of profit
        Arrays.sort(jobs, Comparator.comparingInt(j -> -j.profit));

        int n = jobs.length;
        int[] result = new int[n];
        boolean[] slot = new boolean[n]; // Time slots

        // Iterate through all given jobs and select the maximum profit job
        for (int i = 0; i < n; i++) {
            // Find a free slot for this job
            for (int j = Math.min(n, jobs[i].deadline) - 1; j >= 0; j--) {
                if (!slot[j]) {
                    result[j] = i; // Add this job to result
                    slot[j] = true; // Mark this slot as occupied
                    break;
                }
            }
        }

        // Print the result
        System.out.println("Job Sequence:");
        for (int i = 0; i < n; i++) {
            if (slot[i]) {
                System.out.println(jobs[result[i]].id + " ");
            }
        }
    }

    public static void main(String[] args) {
        Job[] jobs = {
                new Job('a', 2, 100),
                new Job('b', 1, 19),
                new Job('c', 2, 27),
                new Job('d', 1, 25),
                new Job('e', 3, 15)
        };

        System.out.println("Original Jobs:");
        for (Job job : jobs) {
            System.out.println("Job ID: " + job.id + ", Deadline: " + job.deadline + ", Profit: " + job.profit);
        }

        printJobSequence(jobs);
    }
}
