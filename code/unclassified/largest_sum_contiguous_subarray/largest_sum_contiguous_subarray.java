/*
Problem Statement: 
Finding the largest sum contiguous subarray.
[-2, -3, 4, -1, -2, 1, 5, -3]

Subarray having largest sum is [4, -1, -2, 1, 5]
Sum is 7.

[1, 12, -5, -6, 50, 3, -30, 25]

Subarray having largest sum is [1, 12, -5, -6, 50, 3]
Sum is 55.


Explanation: 


arr = [1, 12, -5, -6, 50, 3, -30, 25]

max_element_of_array = arr[0]
sum_of_each_element = arr[0]

for each element of array

	i=1
	sum_of_each_element = max(arr[i], sum_of_each_element+arr[i])
	max_element_of_array = max(sum_of_each_element, max_element_of_array)

	sum_of_each_element = max(12, (1+12)) => 13
	max_of_element_of_array = max(1, 13) => 13

	i=2
	sum_of_each_element = max(-5, (13-5)) => 8
	max_of_element_of_array = max(13, 8) => 13

	i=3
	sum_of_each_element = max(-6, (8-6)) => 2
	max_of_element_of_array = max(13, 2) => 13

	i=4
	sum_of_each_element = max(50, (50+2)) => 52
	max_of_element_of_array = max(13, 52) => 52

	i=5
	sum_of_each_element = max(3, (52+3)) => 55
	max_of_element_of_array = max(52, 55) => 55

	i=6
	sum_of_each_element = max(-30, (55-30)) => 25
	max_of_element_of_array = max(25, 55) => 55

	i=7
	sum_of_each_element = max(25, (25+25)) => 50
	max_of_element_of_array = max(55, 50) => 55

	Maximum is 55.

*/

import java.util.*;
public class largest_sum_contiguous_subarray {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int arr_size = in.nextInt();
		int arr[] = new int[arr_size];
		for(int i=0; i<arr_size; i++) {
			arr[i] = in.nextInt();
		}
		int current_sum = arr[0];
		int maximum_so_far = arr[0];

		for(int i=1; i<arr_size; i++) {
			current_sum = Math.max(arr[i], arr[i] + current_sum);
			maximum_so_far = Math.max(current_sum, maximum_so_far);
		}
		System.out.println("Maximum sum "+maximum_so_far);
	}
}