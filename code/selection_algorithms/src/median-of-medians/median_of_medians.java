import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

 class Solution {
  public static void main(String[] args) {
   Solution s = new Solution();
   List<Integer> a = Arrays.asList(87, 3, 11, 17, 22, 16, 39, 8, 31, 55,
                                   29, 93, 77, 65, 99, 90, 81, 2, 20, 53, 62, 5, 88, 33, 44, 6);
   System.out.println(s.findKthElement(a, 18));
   Collections.sort(a);
   System.out.println(a);
   System.out.println(a.get(18));
  }

 public int findKthElement(List<Integer> a, int k) {
  if (a.size() < 10) {
   Collections.sort(a);
   return a.get(k);
  }
  ArrayList<Integer> medians = new ArrayList<Integer>();
  for (int i = 0; i < a.size() - a.size() % 5; i = i + 5)
   medians.add(getMedian(a.subList(i, i + 5)));
  int v = getMedian(medians);
  ArrayList<Integer> left = getPartition(a, v, true);
  ArrayList<Integer> right = getPartition(a, v, false);
  return (left.size() + 1 == k) ? v : (left.size() > k) ? findKthElement(
   left, k) : findKthElement(right, k - left.size());
 }

 public int getMedian(List<Integer> a) {
  Collections.sort(a);
  return a.get(a.size() / 2);
 }
  
 public ArrayList<Integer> getPartition(List<Integer> a, int v,
                                        boolean isLessThan) {
  ArrayList<Integer> res = new ArrayList<Integer>();
  for (int val : a)
   if (isLessThan && val < v)
    res.add(val);
  else if (!isLessThan && val >= v)
   res.add(val);
  return res;
 }
 }
