    public class problem_004 {

      public static void main( String[] args) {

               int prod,temp,sum,rem,lar = 0,i,j;

               for( i = 100; i <= 999; i++) {

                  for( j = 100; j <= 999; j++) {
                            prod = i * j;
                            temp = prod;
                            sum = 0;

                            while (temp > 0) { 
                                rem = temp % 10;
                                sum = ( sum * 10) + rem;
                                temp /= 10;
                            }
                           
                           if (( prod == sum ) && ( prod > lar ))
                                lar = prod;
                  }
                  
               }
               
               System.out.println("The largest palindrome made from the product of two 3-digit numbers is " + lar);
               
      }   
      
}
