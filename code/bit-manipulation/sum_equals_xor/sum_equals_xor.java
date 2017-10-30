/*
 * Given a positive integer n, find count of positive integers i such that 0 <= i <= n and n+i = n^i
 * Part of Cosmos by OpenGenus Foundation
 * More info: http://www.geeksforgeeks.org/equal-sum-xor/
 * 
 * */

import java.util.*;

public class sum_equals_xor {
  public static void main (String[] args) {
    System.out.println(solve(12));
  }
  
  public static long solve(long n) {
    long unset_binary_rep_n = 0;
    while(n > 0) {
      if((n & 1) == 0) 
        unset_binary_rep_n++;
      n = n >> 1;
    }
    unset_binary_rep_n = (long) Math.pow(2,unset_binary_rep_n);
    return unset_binary_rep_n;
  }
}