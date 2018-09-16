/* Part of Cosmos by OpenGenus Foundation */

import java.util.ArrayList;

public class PigeonHoleSort {

	public static void pigeonholeSort(int[] arr, int n) {
		//initialize
		int min = arr[0];
		int max = arr[0];
		int range = 0;
		//find min/max
		for(int i = 1;i<n;i++) {
			if(arr[i]>max)
				max = arr[i];
			else if(arr[i]<min)
				min = arr[i];
		}
		
		range = max-min+1;
		ArrayList<Integer>[] holes = new ArrayList[range];
		//initialize all arraylists
		for(int i = 0;i<range;i++) {
			holes[i] = new ArrayList<Integer>();
		}
		
		//adding the pigeonholes
		for(int i = 0; i < n;i++) {
			holes[arr[i]-min].add(arr[i]);
		}
		//rearranging array
		int index = 0;
		for(int i = 0;i<range;i++) {
			for(int num : holes[i]) {
				arr[index++] = num;
			}
		}
	}
	
	public static void main(String args[]) {
        	int arr[] = {3, 5, 8, 5};
        	pigeonholeSort(arr, arr.length);
        	
        	for(int num : arr) {
        		System.out.println(num);
        	}
    	}
}
