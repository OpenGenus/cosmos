package exponent;

public class Exponent {

	public static void main(String[] args) {
		double x = 4;
		double y = 2;
		double z = 2006;
		
		double result = compute(x, y, z);
		
		System.out.println(result);
	}

	private static double compute(double x, double y, double z) {
		double yz = 1;
		// repeated squaring for y^z
		while (z > 0) {
			if (z % 2 == 1) {
				yz *= y;
			}
			z /= 2; // divide exponent by 2
			y *= y; // square the base
		}
		double yz_result = yz;

		double xy = 1;
		// repeated squaring for x ^ yz_result
		while (yz_result > 0) {
			if (yz_result % 2 == 1) {
				xy *= x;
			}
			yz_result /= 2; // divide exponent by 2
			x *= x; // square the base
		}

		return xy;
	}

}
