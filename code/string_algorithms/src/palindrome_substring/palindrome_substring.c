import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
   Scanner scn=new Scanner(System.in);
       String str=scn.nextLine();
        subseq(str);
    }
    public static boolean ispallindrome(String str){
        int left=0;int right=str.length()-1;
        while(left<=right){
            if(str.charAt(left)!=str.charAt(right)){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    public static void subseq(String str){
        int count=0;
        for(int i=0;i<str.length();i++){
            for(int j=i+1;j<=str.length();j++){
                String ss=str.substring(i,j);
                boolean pallindrome=ispallindrome(ss);
                if(pallindrome){
                System.out.println(ss);
                    count++;
                }
            }
        }
        System.out.print(count);
    }
}