public class problem_004 {
      public static void main( String[] args) {
                    
                    int lar = 0;
                    
                    // Nested loop to iterate for every three digit number
                    for(int i = 100; i <= 999; ++i) {
                        for(int j = 100; j <= 999; ++j) {
                                   int prod = i * j;
                                   int temp = prod;
                                   int sum = 0;
                                   
                                   // Loop to reverse the number 
                                   while (temp > 0) { 
                                        int rem = temp % 10;
                                        sum = (sum * 10) + rem;
                                        temp /= 10;
                                   }
                                  
                                   // Statement to check the palindrome condition and store the largest value
                                   if ((prod == sum) && (prod > lar))
                                        lar = prod;
                        }
                    }
                    
                    System.out.println("The largest palindrome made from the product of two 3-digit numbers is " + lar);
      }   
}
