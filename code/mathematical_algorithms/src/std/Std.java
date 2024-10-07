// Part of Cosmos by OpenGenus Foundation

public class Std {
	public static void main(String[] args) {
		double[] values = {12, 65, 91, 52, 18, 72};
		System.out.println(calculateStd(values)); // 28.41
	}

	public static double calculateStd(double[] values) {
		return Math.sqrt(calculateVariance(values));
	}

	public static double calculateVariance(double[] values) {
		double average = 0;
		double squareAverage = 0;

		for (double value : values) {
			average += value;
			squareAverage += value * value;
		}

		average /= values.length;
		squareAverage /= values.length;

		return squareAverage - average * average;
	}
}
