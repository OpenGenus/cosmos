import java.util.*;
class maxdiff{
public static void main (String[] args) throws java.lang.Exception
	{
		Scanner s = new Scanner(System.in);
		int t = 0;
		if(s.hasNextInt()){
			t = s.nextInt();}
		
		while(t-->0){
			int n =0; 
			int k = 0;
			if(s.hasNextInt()){
				n = s.nextInt();
			}
			if(s.hasNextInt()){
				k = s.nextInt();
			}
			int[] weights = new int[n];
			for(int i = 0;i<n;i++){
				weights[i] = s.nextInt();
			}
			Arrays.sort(weights);
			int sum1 = 0;
			int sum2 = 0;
			int i = 0;
			if(k>n-k){
				k = n-k;
			}
			for( i=0;i<k;i++){
		        sum1+=weights[i];}
		    for(;i<n;i++){
		        sum2+=weights[i];}
			System.out.println(sum2-sum1);
		}
	
	}}