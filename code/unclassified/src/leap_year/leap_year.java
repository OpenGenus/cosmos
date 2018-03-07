import java.io.InputStreamReader;
import java.util.Scanner;

class LeapYear {
	public static boolean isLeapYear(int year) {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
	public static void main(String []args) {
		Scanner in = new Scanner(new InputStreamReader(System.in));
		System.out.println("Enter the starting year: ");
		int startyear = in.nextInt();
		System.out.println("Enter the ending year: ");
		int endyear = in.nextInt();
		for(int i = startyear; i <= endyear; ++i)
			if(isLeapYear(i))
				System.out.println(i);
		in.close();
	}
}
