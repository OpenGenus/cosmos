        public class problem_005 {

            public static void main( String[] args ) {

                    int lcm = 1 , i;

                    for ( i = 2; i <= 20; i++ ) {
                              if ( lcm % i == 0 ) {
                                  continue;
                              }

                              else {
                                  lcm++;
                                  i = 2;
                              }
                      }

                      System.out.println(lcm);
            }
        }
