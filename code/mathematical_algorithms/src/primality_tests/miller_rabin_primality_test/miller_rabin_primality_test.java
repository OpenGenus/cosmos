import java.util.Random;
import java.lang.Math;

//Miller-Rabin primality test
//
//n: Tested number
//k: Number of iterations
//preconditions: n must be an odd number > 3

public class MillerRabinPrimalityTest {

	public static boolean test(int n,int k){

		int[] result = factors(n-1);
		int r = result[0];
		int d = result[1];

		while(k != 0){

			int power = 1; //Power declaration and initial assignment
			boolean notPrime = false;
			
			Random rand = new Random();
			int randomNum = rand.nextInt(n-1) + 2;
	
			int x = (int)Math.pow(randomNum,d) % n;
	
			if(x == 1 || x == n-1){
			
				notPrime = true;
			}

		

			while (power < r){

				x = (int)Math.pow(randomNum,((int)Math.pow(2,power)*d)) % n;

				if(x == n-1){
				
					notPrime = true;
					break;

				}	

				power = power + 1;

			}

			k = k-1;

			if(!notPrime){
				return false;
			}
		}

	return true;
	
	}
	

public static int[] factors(int n){ //Write n as 2^s * d
	
	int[] result = new int[2];
	int r = 1;
	
	while((n % (int)Math.pow(2,r) != 0) || (n / (int)Math.pow(2,r) % 2) == 0){

		r = r+1;

	
	}
	result[0] = r;
	result[1] = n / (int)Math.pow(2,r);
	
	return result;
	}

public static void main(String[] args){

	boolean test = test(13,5);
	System.out.println(test);

	}	


}
