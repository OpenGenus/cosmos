import java.util.*;

class Job {
    char id;
    int deadline;
    int profit;

    public Job(char id, int deadline, int profit) {
        this.id = id;
        this.deadline = deadline;
        this.profit = profit;
    }
}

public class JobSequencing {
    public static void main(String[] args) {
        List<Job> jobs = new ArrayList<>();
        jobs.add(new Job('a', 2, 100));
        jobs.add(new Job('b', 1, 19));
        jobs.add(new Job('c', 2, 27));
        jobs.add(new Job('d', 1, 25));
        jobs.add(new Job('e', 3, 15));

        // Sort the jobs in decreasing order of profit
        jobs.sort((j1, j2) -> Integer.compare(j2.profit, j1.profit));

        int maxDeadline = 0;
        for (Job job : jobs) {
            if (job.deadline > maxDeadline) {
                maxDeadline = job.deadline;
            }
        }

        char[] result = new char[maxDeadline];
        Arrays.fill(result, ' ');

        int totalProfit = 0;

        for (Job job : jobs) {
            for (int i = job.deadline - 1; i >= 0; i--) {
                if (result[i] == ' ') {
                    result[i] = job.id;
                    totalProfit += job.profit;
                    break;
                }
            }
        }

        System.out.println("Maximized Profit: " + totalProfit);
        System.out.println("Job Sequence: " + new String(result));
    }
}
