/* Part of Cosmos by OpenGenus Foundation */


import java.util.Scanner;              //To take the input the scanner class has to be imported.
public class erathosthenes{

	public void sieve (int n) { 
	boolean checkPrime[] = new boolean [n+1];       //checkPrime array to mark the elements whether they are prime or not. 
	int a=2;
		for(int i=0; i<n; i++){         //initialises all elements of checkPrime to true
			checkPrime[i] = true;
		}
		for(int i=a ; i*i<=n ; i++){           //outer for loop is to check whether a particular element has been marked, if no then it is taken
			if(checkPrime[i] == true){
				for(int j=i*2 ; j<=n ; j=j+i){  // inner for loop marks the multiples of the element selected by the outer for loop
					checkPrime[j] = false;
				}
			}
		}
		for(int i=2 ; i<=n ; i++){
			if(checkPrime[i] == true)
				System.out.println(i+" ");
		}
	}
	public static void main(String [] args){

		System.out.println("Enter the upperBound:");
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		erathosthenes ee = new erathosthenes();
		ee.sieve(n);
	}

}