// Part of Cosmos by OpenGenus Foundation

public class russian_peasant {

    // russian peasant algorithm
    public static int multiply (int a, int b) {    
        int result = 0;
        while (b > 0) {
            if (b % 2 == 1)
                result += a;
            a *= 2;
            b /= 2;
        }
        return result;
    }
  
    // Usage example
    public static void main (String [] args) {
        System.out.println (multiply(12,13));
    }

}
