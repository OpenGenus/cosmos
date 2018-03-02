import java.util.*;
 
public class Leap_Year {

	int year1, year2;
	Scanner sc;
	// getting value of the years from user
	void getVal() {
		
		sc = new Scanner(System.in);
 
		System.out.println("Finding leap years between two years");
		
		System.out.println("\nEnter the first year : ");
		year1 = Integer.parseInt(sc.nextLine());
		
		System.out.println("Enter the second  : ");
		year2 = Integer.parseInt(sc.nextLine());
	}
	// Printing no of leap year between two years
	void checkLeapYear() {

		System.out.println();
				System.out.println("No of leap years betwwen "+ year1 +" and "+year2+" are : ");		
		for(int i=year1; i<=year2; i++) {
			
			if(i%400 == 0 || i%4 == 0) {
				
				System.out.println(i);			
			}
		}
	}
}
 
class MainClass {
	
	public static void main(String str[]) {
		
		Leap_Year obj = new Leap_Year();
		
		obj.getVal();
		obj.checkLeapYear();
	}
}