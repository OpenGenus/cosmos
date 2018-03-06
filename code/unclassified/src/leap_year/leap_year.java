public class LeapYear {
	public static boolean isLeapYear(int year) {
		if(year % 4 == 0)
			return true;
		if(year % 400 == 0)
			return true;
		if(year % 100 == 0)
			return false;
		
		return false;
	}
	public static void main(String []args) {
		Scanner in = new Scanner(new InputStreamReader(System.in));
		System.out.println("Enter starting year");
		int startyear = in.nextInt();
		System.out.println("Enter ending year");
		int endyear = in.nextInt();
		for(int i = startyear; i <= endyear; ++i) {
			if(isLeapYear(i))
				System.out.println(i);
		}
		in.close();
	}
}
