import java.util.*;
/*
*
*  https://leetcode.com/problems/group-anagrams/
*
* Solution Description:
* The approach is if two srings are anagram of each other than there sorted versions wil
* be same or equal.
* Here we will take a hashmap where key will be of string type and values are list of
* strings. 
* key will contains the every unique sorted version of strings and value will contain list
* of their corresponding anagrams.
* Finally the list of all values in hashmap will be our output.
*
* Time Complexity: O(NKlogK)  //K is a maximum length of string
*
*/

public class GroupAnagrams {
    public static void main(String args[]){
            Scanner sc = new Scanner(System.in);
            int length = sc.nextInt(); 
            String[] strs = new String[length]; 
            for (int i = 0; i < length; i++)
            {
                String userInput = sc.next(); 
                strs[i] = userInput;
            }
            System.out.println(groupAnagrams(strs));
    }
    public static List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,List<String>>map = new HashMap<>();
       for (String s : strs)
        {
            char s1[] =  s.toCharArray();
         System.out.println(s1);
            Arrays.sort(s1); // sorting string to check if its sorted version is present in map.
            
            String sorted = String.valueOf(s1);
             System.out.println(sorted.trim());
            if(!map.containsKey(sorted))
            {
               map.put(sorted,new ArrayList<>()); 
            }
            map.get(sorted).add(s); // creating new list in a value
            
        }
       return new ArrayList<List<String>>(map.values()); // list of all values of map.
    }
}