// Part of Cosmos by OpenGenus Foundation
public static int[] two_sum(int[] arr, int target){
  if(nums == null || nums.length < 2) return new int[] {0, 0}; 
  
  HashMap<Integer, Integer> map = new HashMap<Integer, Integer>(); 
  for(int i = 0; i < arr.length; i++){
    if(map.containsKey(nums[i])){
      return new int[] {map.get(nums[i]), i); 
    }
    else{
      map.put(target-nums[i], i); 
    }
  }
  return new int[]{0,0};
} 

public static void main(String[] args){
  int[] arr1 = {3, 5, 7, 0, -3, -2, -3}; 
  int[] arr2 = {3, 5, 0, -3, -2, -3}; 
  
  System.out.println(two_sum(arr1, 4)); 
  System.out.println(two_sum(arr2, 4)); 
}
