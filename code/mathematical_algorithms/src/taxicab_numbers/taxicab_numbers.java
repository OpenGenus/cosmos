
public class taxicab_numbers{
    public static void main(String[] args){
        taxicab(10);
    }

    public static void taxicab(int n){
        
        int answer = 1; //potential answer
        int amountFound = 1; // The number of cube additions found per answer
        int pairCount = 0; // the pairs of cube additions
        
        while( (pairCount) < n){
            //resetting amount counter fir every new potential answer there is
        	amountFound = 0;
        	//Going through all the values to the potential answer seeing if it has 2 pairs.
            for(int x = 1; x < Math.pow(answer,((double)1)/3); x++){
                for(int y = x + 1; y < Math.pow(answer,((double)1)/3); y++){
                    if (((double)Math.pow(x,3) + (double)Math.pow(y,3)) == (double)answer){
                        amountFound++;
                        //^ means that an answer has been found so the one below this \/ checks if it was a pair or not.
                        if (amountFound == 2){
            	            pairCount ++;
                            System.out.println((pairCount) + " " + answer);
                        }
                    }
                }
            }
            //increasing the potential answer by one
            answer++;
        }
    }
}
