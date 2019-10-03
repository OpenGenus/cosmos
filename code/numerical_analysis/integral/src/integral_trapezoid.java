package cosmos;

public class IntegralTrapezoidal {
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
		int numofTrapezoids, 
		IntegralFunction function) {
			
		double h = (b - a) / numofTrapezoids; // Compute width
		double area = (function.valueAt(a) + function.valueAt(b)) / 2.0;

		for(int i = 1; i < numofTrapezoids; i++) {
			double y = a + i * h;
			area += function.valueAt(y);
		}
		
		area *= h;
		return area;
	}

	public interface IntegralFunction {
		public double valueAt(double value);
	}
}
