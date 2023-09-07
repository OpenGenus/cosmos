import java.util.Scanner;

public class egyptianFraction {

	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		int nr = scn.nextInt();			//inputing the numerator
		int dr = scn.nextInt();			//inputing the denominator
		
		System.out.println("Egyptian fraction representation of " + nr + "/" + dr + " is ");
		
		//recursive call
		egyptFrac(nr, dr);                       
	}

	public static void egyptFrac(int nr, int dr) {

		
		//if either dr or nr is zero then nr/dr is the answer
		if (nr == 0 || dr == 0)					
			return;			

		//if dr divides nr then the given number is not a fraction
		if (nr % dr == 0) {
			System.out.println(nr / dr);
			return;
		}


		//if nr divides dr then it can directly be written in 1/n form
		if (dr % nr == 0) {
			System.out.println("1/" + dr / nr + " + ");
			return;
		}

		
		if (nr > dr) {
			System.out.println(nr / dr);
			egyptFrac(nr % dr, dr);
			return;
		}


		//this code runs when dr>nr and dr%nr!=0 
		int n = dr / nr + 1;
		System.out.println("1/" + n + " + ");

		egyptFrac(nr * n - dr, dr * n);
	}

}
