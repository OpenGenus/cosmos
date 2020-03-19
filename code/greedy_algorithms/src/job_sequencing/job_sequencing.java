import java.util.*; 
 
class DisjointSet 
{ 
	int parent[]; 

	DisjointSet(int n) 
	{ 
		parent = new int[n + 1]; 

		for (int i = 0; i <= n; i++) 
			parent[i] = i; 
	} 

	int find(int s) 
	{ 
		if (s == parent[s]) 
			return s; 
		return parent[s] = find(parent[s]); 
	} 
 
	void merge(int u, int v) 
	{ 
		parent[v] = u; 
	} 
} 

class Job implements Comparator<Job> 
{ 
	// Each job has a unique-id, profit and deadline 
	char id; 
	int deadline, profit; 

	// Constructors 
	public Job() { } 
	public Job(char id,int deadline,int profit) 
	{ 
		this.id = id; 
		this.deadline = deadline; 
		this.profit = profit; 
	} 

	public static int findMaxDeadline(ArrayList<Job> arr) 
	{ 
		int ans = Integer.MIN_VALUE; 
		for (Job temp : arr) 
			ans = Math.max(temp.deadline, ans); 
		return ans; 
	} 

	public static void printJobScheduling(ArrayList<Job> arr) 
	{ 
		Collections.sort(arr, new Job()); 
		int maxDeadline = findMaxDeadline(arr); 
		DisjointSet dsu = new DisjointSet(maxDeadline); 

		for (Job temp : arr) 
		{ 
			int availableSlot = dsu.find(temp.deadline); 

			if (availableSlot > 0) 
			{ 
				dsu.merge(dsu.find(availableSlot - 1), 
								availableSlot); 
				System.out.print(temp.id + " "); 
			} 
		} 
		System.out.println(); 
	} 
	public int compare(Job j1, Job j2) 
	{ 
		return j1.profit > j2.profit? -1: 1; 
	} 
} 

class Main 
{ 
	public static void main(String args[]) 
	{ 
		ArrayList<Job> arr=new ArrayList<Job>(); 
		arr.add(new Job('a',2,100)); 
		arr.add(new Job('b',1,19)); 
		arr.add(new Job('c',2,27)); 
		arr.add(new Job('d',1,25)); 
		arr.add(new Job('e',3,15)); 
		System.out.println("Following jobs need to be "+ 
						"executed for maximum profit"); 
		Job.printJobScheduling(arr); 
	} 
} 
