import java.util.*;
    /*
     *
     * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
     *
     * Solution Description:
     * 	"Binary Search Approach"
     *      - Since array is sorted we can apply Binary Search but since array is rotated, we cannot apply Binary search directly.
     *      - There would be a point in array, elements left to that point are greater than first element and elements right to that point are lesser than first element. we have to find that point.
     *      Algorithm:
     * 	1. Find the mid element of the array.
     * 	2. If mid element > first element of array then we have to search for the inflection point on the right of mid.
     * 	3. If mid element < first element of array then we have to search for the inflection point on the left of mid.
     * 	4. We stop our search when we find the inflection point, when either of the two conditions is satisfied:
     *       (i) nums[mid] > nums[mid + 1] Hence, mid+1 is the smallest, return nums[mid+1].
     *       (ii) nums[mid - 1] > nums[mid] Hence, mid is the smallest, return nums[mid].
     *
     *     Time Complexity: O(logN)
     *
     */
    public class FindMinimumInRotatedSortedArray {
        public static void main(String args[]){
            Scanner sc = new Scanner(System.in);
            int T = sc.nextInt();
            int[]arr = new int[T];
            for (int i = 0; i < T; i++)
            {
                arr[i] = sc.nextInt();
            }
            int result = findMin(arr);
            System.out.println(result);
            return;
        }
        public static int findMin(int[] nums) {
            // If the array has just one element,then it is the minimum element then return that element.
            if (nums.length == 1) {
                return nums[0];
            }

            // initializing left and right pointers.
            int left = 0, right = nums.length - 1;

            // if the last element is greater than the first element then there is no rotation.
            // Hence the smallest element is first element, return first element.
            if (nums[right] > nums[0]) {
                return nums[0];
            }

            // Binary search
            while(right >= left) {
                // Find the mid element
                int mid = left + (right - left) / 2;

                // if the mid element is greater than its next element, i.e. mid+1 element, which means this point is the inflection point and mid+1 element is the smallest.
                // return mid+1 element.
                if (nums[mid] > nums[mid + 1]) {
                    return nums[mid + 1];
                }

                // if the mid element is lesser than its previous element.i.e. mid-1 element, which means this is the inflection point and mid element is the smallest.
                // return mid element.
                if (nums[mid - 1] > nums[mid]) {
                    return nums[mid];
                }

                // if the mid elements value is greater than the 0th element this means
                // the least value is still somewhere to the right as we are still dealing with elements
                // greater than nums[0]
                if (nums[mid] > nums[0]) {
                    left = mid + 1;
                }
                else {
                    // if nums[0] is greater than the mid value then this means the smallest value is somewhere to
                    // the left
                    right = mid - 1;
                }
            }
            return -1;
        }
    }

