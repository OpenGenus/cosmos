
public class taxicab_numbers{
    public static void main(String[] args){
        taxicab(10);
    }

    public static void taxicab(int n){
        
        int answer = 1;
        int amountFound = 1;
        int pairCount = 0;
        while( (pairCount) < n){

        	amountFound = 0;
        	
            for(int x = 1; x < Math.pow(answer,((double)1)/3); x++){
                for(int y = x + 1; y < Math.pow(answer,((double)1)/3); y++){
                    if (((double)Math.pow(x,3) + (double)Math.pow(y,3)) == (double)answer){
                        amountFound++;
                        if (amountFound == 2){
            	            pairCount ++;
                            System.out.println((pairCount) + " " + answer);
                        }
                    }
                }
            }
            answer++;
        }
    }
}