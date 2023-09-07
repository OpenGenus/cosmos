import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        
        getPalindromicPart(str,"");
    }
    
    public static void getPalindromicPart(String str, String psf){
        if(str.length()==0){
            System.out.println(psf);
            return;
        }
        for(int i=1; i<=str.length(); i++){
            String s1 = str.substring(0,i);
            String s2 = str.substring(i);
            if(isPalindrome(s1)==true){
                getPalindromicPart(s2,psf+s1+" ");
            }
        }
    }
    
    public static boolean isPalindrome(String str){
        int left = 0;
        int right = str.length()-1;
        while(left<=right){
            if(str.charAt(left)!=str.charAt(right)){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}