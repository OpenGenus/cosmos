package cosmos;

//Part of Cosmos by OpenGenus Foundation
public class IntegralRectangle {

	public static void main(String[] args) {
		
		double a = 0.0;
		double b = 1.0;
		int step = 1000;

		IntegralFunction integralFunction = (x) -> x * x * x; // a∫b x^3 dx
		double sum = calculateIntegral(a, b, step, integralFunction);
		System.out.println("Approximate integral value = " + sum); // exact answer = 0.25
	}

	public static double calculateIntegral(
		double a, 
		double b, 
		int numOfRectangles, 
		IntegralFunction function) {
			
		double widthOfRectangle = (b - a) / numOfRectangles; // Compute width
		double sum = 0.0; // Clear running sum
		
		for(int i = 1; i <= numOfRectangles; i++) {
			double xOfRectangle = a + (i - 1) * widthOfRectangle; // Use xOfRectangle to simplify formula...
			double heightOfRectangle = function.valueAt(xOfRectangle); // Height of rectangle is value of function at that point
			sum += (widthOfRectangle * heightOfRectangle);
		}

		return sum;
	}

	public interface IntegralFunction {
		public double valueAt(double value);
	}
}
