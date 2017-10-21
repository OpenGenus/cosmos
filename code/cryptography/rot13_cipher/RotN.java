// Part of Cosmos by OpenGenus Foundation
public class RotN {

    public static void main(String[] args) {
        String test = "test";
		
        System.out.println(rot(test, 13)); // prints 'grfg'
        System.out.println(rot(test, 26)); // prints 'test'
    }
    
    public static String rot(String str, int n) {
        n = Math.max(0, n);
        
        StringBuilder sb = new StringBuilder();
    
        for (char c : str.toCharArray()) {
            if ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ".indexOf(c) < 0)
                sb.append(c);
            else {
                int b = c - 'a';
                int m = (b + n) % 26;
                sb.append((char) (m + 'a'));
            }
        }
        
        return sb.toString();
    }
}
