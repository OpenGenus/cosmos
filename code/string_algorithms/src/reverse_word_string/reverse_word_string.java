import java.util.regex.Pattern; 
public class reverseWordString { 
  
    static String reverseString(String str) 
    { 
  
        // Specify the search pattern 
        Pattern pattern = Pattern.compile("\\s"); 
  
        // split the String str with a pattern 
        String[] temp = pattern.split(str); 
        String result = ""; 
  
        // Iterate over the temp array and store 
        // the string in reverse order. 
        for (int i = 0; i < temp.length; i++) { 
            if (i == temp.length - 1) 
                result = temp[i] + result; 
            else
                result = " " + temp[i] + result; 
        } 
        return result; 
    } 
  
    // Driver methods to test above method 
    public static void main(String[] args) 
    { 
        String s1 = "The universe of algorithm and data structures"; 
        System.out.println(reverseString(s1)); 
  
        String s2 = "I love Java Programming"; 
        System.out.println(reverseString(s2)); 
    } 
} 
