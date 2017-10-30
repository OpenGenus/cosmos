import java.util.*;
// Part of Cosmos by OpenGenus Foundation
class Gcd_Lcm_Calc{
	public void determineLCM(int a, int b) {
		int num1, num2, lcm = 0;
		if (a > b) {
			num1 = a;
			num2 = b;
		} else {
			num1 = b;
			num2 = a;
		}
		for (int i = 1; i <= num2; i++) {
			if ((num1 * i) % num2 == 0) {
				lcm = num1 * i;
                    		System.out.println("LCM = " + lcm);
                    		break;
			}
		}
	}
	public int determineGCD(int a, int b) {
    		while (b > 0)
    		{
        		int r = a % b;
        		a = b;
        		b = r;
    		}
    		return a;
	}
	public static void main(String[] args) {
		Gcd_Lcm_Calc obj = new Gcd_Lcm_Calc();
		System.out.println("Enter two nos: ");
		Scanner s1 = new Scanner(System.in);
		int a = s1.nextInt();
		int b = s1.nextInt();
		obj.determineLCM(a, b);
		int gcd = obj.determineGCD(a, b);
		System.out.println("GCD = " + gcd);
	}
}
