import java.util.*;

public class HillClimbing {

	public static double findMinimum(BiFunction<Double, Double, Double> f) {
		double curX = 0;
		double curY = 0;
		double curF = f.apply(curX, curY);
		for (double step = 1e6; step > 1e-7; ) {
			double bestF = curF;
			double bestX = curX;
			double bestY = curY;
			boolean find = false;
			for (int i = 0; i < 6; i++) {
				double a = 2 * Math.PI * i / 6;
				double nextX = curX + step * Math.cos(a);
				double nextY = curY + step * Math.sin(a);
				double nextF = f.apply(nextX, nextY);
				if (bestF > nextF) {
					bestF = nextF;
					bestX = nextX;
					bestY = nextY;
					find = true;
				}
			}
			if (!find) {
				step /= 2;
			} else {
				curX = bestX;
				curY = bestY;
				curF = bestF;
			}
		}
		System.out.println(curX + " " + curY);
		return curF;
	}

	public static void main(String[] args) {
		System.out.println(findMinimum((x, y) -> (x - 2) * (x - 2) + (y - 3) * (y - 3)));
	}
}
