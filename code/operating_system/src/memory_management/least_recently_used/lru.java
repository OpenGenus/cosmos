import java.util.*;
import java.util.ArrayList;
import java.util.LinkedList;

class lru 
{ 
	// Method to find page faults using indexes 
	static int pageFaults(int pages[], int capacity) 
	{
	    int faults=0,index=0;
            LinkedList<Integer> q = new LinkedList<>();
            for(int i=0;i<pages.length;i++){
                if(!q.contains(pages[i])){
                    faults++;
                    if(q.size()<capacity){
                        q.add(pages[i]);
                    }
                    else{
                        q.remove(0);
                        q.add(pages[i]);
                    }
                }
                else{
                    for(int k=0;k<capacity;k++){
                        if(pages[i]==q.get(k)){
                            q.remove(k);
                            q.add(pages[i]);
                            break;
                        }
                    }
                }
            }
            return faults;
	} 
	
	// Driver Method to test your algorithm with a simple example
	public static void main(String args[]) 
	{
		/*
		 * The pages[] array holds the reference string for all
		 * page requests.
		 */
        System.out.println("How many page requests are there? (Number of characters of the reference string) ");
        Scanner scan = new Scanner(System.in);
        int num = scan.nextInt();
		int pages[] = new int[num];
        for(int i=0; i<num; i++){
            System.out.print("Enter page request No." + (i+1)+": ");
            pages[i] = scan.nextInt();
        }
		
		// This is the number of available page frames
        System.out.print("\nHow many available page frames are there? ");
		int memoryCapacity = scan.nextInt(); 
		
		int faults = pageFaults(pages, memoryCapacity);
		System.out.println("Number of faults: "+faults);
	} 
} 
