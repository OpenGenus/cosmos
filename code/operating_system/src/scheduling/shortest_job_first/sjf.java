import java.util.*;

public class sjf{
	public static void main(String args[])
	{
		System.out.println("Hey! We will solve a scheduling problem using Shortest Job Find (SJF) algorithm.");
		Scanner scan = new Scanner(System.in);
		System.out.println("How many processors are there? ");
		int num = scan.nextInt();

		int prs[] = new int[num]; // ID for the processors
		int arr_t[] = new int[num]; // Arrival time
		int bur_t[] = new int[num]; // Burst time
		int com_t[] = new int[num]; // Complete time
		int tar_t[] = new int[num]; // Turn Around time
		int wait_t[] = new int[num];  // Waiting time

		int flag[] = new int[num];  // Checks if processor is completed or not
		int st = 0, tot = 0;
		float avg_wait_t = 0, avg_tar_t = 0;
 
		for(int i=0; i<num; i++)
		{
			System.out.print("\nEnter processor No." + (i+1) + " Arrival Time: ");
			arr_t[i] = scan.nextInt();
			System.out.print("\nEnter processor No." + (i+1) + " Burst Time: ");
			bur_t[i] = scan.nextInt();
			prs[i] = i+1;
			flag[i] = 0;
		}

		boolean a = true;
		while(a)
		{
			int c = num, min = 999;
			if (tot == num) // If total number of processors are completed while loop will be terminated
				a = false;
			
			for (int i=0; i<num; i++)
			{
				/*
				 * If i'th process arrival time <= system time and its flag=0 and burst<min then
				 * That process will be executed first 
				 */ 
				if ((flag[i] == 0) && (arr_t[i] <= st) && (bur_t[i]<min))
				{
					min=bur_t[i];
					c=i;
				}
			}
			
			/* If c==n means c value can not updated because no process arrival time < system time so we increase the system time */
			if (c==num) 
				st++;
			else
			{
				com_t[c]=st+bur_t[c];
				tar_t[c]=com_t[c]-arr_t[c];
				wait_t[c]=tar_t[c]-bur_t[c];
				st+=bur_t[c];
				flag[c]=1;
				tot++;
			}
		}
		
		System.out.println("\nProc. Arrival Burst Complete TurnAr Waiting");
		for(int i=0; i<num; i++)
		{
			avg_wait_t += wait_t[i];
			avg_tar_t += tar_t[i];
			System.out.println(prs[i] + "\t" + arr_t[i] + "\t" + bur_t[i] + "\t" + com_t[i] + "\t" + tar_t[i] + "\t" + wait_t[i]);
		}
		System.out.println("Average Turnaround time is: "+ (float)(avg_tar_t / num));
		System.out.println("Average Waiting time is: "+ (float)(avg_wait_t / num));
		scan.close();
	}
}