/*
 * Given a string, find the rank of the string amongst its permutations sorted lexicographically. 
 Assuming that no characters are repeated.
 */
 

import java.util.*;
public class Rank {
    public static int findRank(String A) {
        int length = A.length();
        long strFactorial = factorial(length);
        long rank = 1;
        for(int i = 0; i < length; i++){
            strFactorial /= length - i;
            rank += findSmallerInRight(A, i, length - 1) * strFactorial;
        }
        System.out.println("Rank : "+ Integer.MAX_VALUE);
        rank %= 1000000007;
        return (int)rank;
    }
    
    public static long factorial(int n){
        return n <= 1? 1: (n * factorial(n - 1));
    }
    public static int findSmallerInRight(String A, int low, int high){
        int countRight = 0;
        for(int i = low + 1; i <= high; i++){
            if(A.charAt(i) < A.charAt(low))
                countRight++;
        }
        return countRight;
    }
    
    
    // contains count of smaller characters in whole string
    public static void populateAndIncreaseCount (int[] count, char[] str)
    {
        int i;
        
        for( i = 0; str[i] >= 'a' && str[i] <= 'z' ; ++i )
            ++count[ str[i] ];
        
        for( i = 1; i < 256; ++i )
            count[i] += count[i-1];
    }
    
// Removes a character ch from count[] array
// constructed by populateAndIncreaseCount()
    public static void updatecount (int[] count, char ch)
    {
        int i;
        for( i = ch; i < 256; ++i )
            --count[i];
    }
    
// A function to find rank of a string in all permutations
// of characters
    public static int findRank (char[] str)
    {
        int len = str.length;
        long mul = factorial(len);
        int rank = 1, i;
        int[] count = new int[256];  // all elements of count[] are initialized with 0
        
        // Populate the count array such that count[i] contains count of 
        // characters which are present in str and are smaller than i
        populateAndIncreaseCount( count, str );
        
        for (i = 0; i < len; ++i)
        {
            mul /= len - i;
            
            // count number of chars smaller than str[i]
            // fron str[i+1] to str[len-1]
            rank += count[ str[i] - 1] * mul;
            
            // Reduce count of characters greater than str[i]
            updatecount (count, str[i]);
        }
        
        return rank;
    }
    
    public static void main(String[] args) {
        String A = "aab";
        System.out.println(findRank(A.toCharArray()));
    }
}