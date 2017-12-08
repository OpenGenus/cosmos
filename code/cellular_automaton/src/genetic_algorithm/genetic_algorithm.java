import javax.swing.*;
import java.awt.*;
import java.util.*;

public class GeneticAlgorithm extends JFrame {
	Random rnd = new Random(1);
	int n = rnd.nextInt(300) + 250;

	int generation;
	double[] x = new double[n];
	double[] y = new double[n];
	int[] bestState;

	{
		for (int i = 0; i < n; i++) {
			x[i] = rnd.nextDouble();
			y[i] = rnd.nextDouble();
		}
	}

	public void geneticAlgorithm() {
		bestState = new int[n];
		for (int i = 0; i < n; i++)
			bestState[i] = i;
		final int populationLimit = 100;
		final Population population = new Population(populationLimit);
		final int n = x.length;
		for (int i = 0; i < populationLimit; i++)
			population.chromosomes.add(new Chromosome(optimize(getRandomPermutation(n))));

		final double mutationRate = 0.3;
		final int generations = 10_000;

		for (generation = 0; generation < generations; generation++) {
			int i = 0;
			while (population.chromosomes.size() < population.populationLimit) {
				int i1 = rnd.nextInt(population.chromosomes.size());
				int i2 = (i1 + 1 + rnd.nextInt(population.chromosomes.size() - 1)) % population.chromosomes.size();

				Chromosome parent1 = population.chromosomes.get(i1);
				Chromosome parent2 = population.chromosomes.get(i2);

				int[][] pair = crossOver(parent1.p, parent2.p);

				if (rnd.nextDouble() < mutationRate) {
					mutate(pair[0]);
					mutate(pair[1]);
				}

				population.chromosomes.add(new Chromosome(optimize(pair[0])));
				population.chromosomes.add(new Chromosome(optimize(pair[1])));
			}
			population.nextGeneration();
			bestState = population.chromosomes.get(0).p;
			repaint();
		}
	}

	int[][] crossOver(int[] p1, int[] p2) {
		int n = p1.length;
		int i1 = rnd.nextInt(n);
		int i2 = (i1 + 1 + rnd.nextInt(n - 1)) % n;

		int[] n1 = p1.clone();
		int[] n2 = p2.clone();

		boolean[] used1 = new boolean[n];
		boolean[] used2 = new boolean[n];

		for (int i = i1; ; i = (i + 1) % n) {
			n1[i] = p2[i];
			used1[n1[i]] = true;
			n2[i] = p1[i];
			used2[n2[i]] = true;
			if (i == i2) {
				break;
			}
		}

		for (int i = (i2 + 1) % n; i != i1; i = (i + 1) % n) {
			if (used1[n1[i]]) {
				n1[i] = -1;
			} else {
				used1[n1[i]] = true;
			}
			if (used2[n2[i]]) {
				n2[i] = -1;
			} else {
				used2[n2[i]] = true;
			}
		}

		int pos1 = 0;
		int pos2 = 0;
		for (int i = 0; i < n; i++) {
			if (n1[i] == -1) {
				while (used1[pos1])
					++pos1;
				n1[i] = pos1++;
			}
			if (n2[i] == -1) {
				while (used2[pos2])
					++pos2;
				n2[i] = pos2++;
			}
		}
		return new int[][]{n1, n2};
	}

	void mutate(int[] p) {
		int n = p.length;
		int i = rnd.nextInt(n);
		int j = (i + 1 + rnd.nextInt(n - 1)) % n;
		reverse(p, i, j);
	}

	// http://en.wikipedia.org/wiki/2-opt
	static void reverse(int[] p, int i, int j) {
		int n = p.length;
		// reverse order from i to j
		while (i != j) {
			int t = p[j];
			p[j] = p[i];
			p[i] = t;
			i = (i + 1) % n;
			if (i == j) break;
			j = (j - 1 + n) % n;
		}
	}

	double eval(int[] state) {
		double res = 0;
		for (int i = 0, j = state.length - 1; i < state.length; j = i++)
			res += dist(x[state[i]], y[state[i]], x[state[j]], y[state[j]]);
		return res;
	}

	static double dist(double x1, double y1, double x2, double y2) {
		double dx = x1 - x2;
		double dy = y1 - y2;
		return Math.sqrt(dx * dx + dy * dy);
	}

	int[] getRandomPermutation(int n) {
		int[] res = new int[n];
		for (int i = 0; i < n; i++) {
			int j = rnd.nextInt(i + 1);
			res[i] = res[j];
			res[j] = i;
		}
		return res;
	}

	// try all 2-opt moves
	int[] optimize(int[] p) {
		int[] res = p.clone();
		for (boolean improved = true; improved; ) {
			improved = false;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i == j || (j + 1) % n == i) continue;
					int i1 = (i - 1 + n) % n;
					int j1 = (j + 1) % n;
					double delta = dist(x[res[i1]], y[res[i1]], x[res[j]], y[res[j]])
							+ dist(x[res[i]], y[res[i]], x[res[j1]], y[res[j1]])
							- dist(x[res[i1]], y[res[i1]], x[res[i]], y[res[i]])
							- dist(x[res[j]], y[res[j]], x[res[j1]], y[res[j1]]);
					if (delta < -1e-9) {
						reverse(res, i, j);
						improved = true;
					}
				}
			}
		}
		return res;
	}

	class Chromosome implements Comparable<Chromosome> {
		final int[] p;
		private double cost = Double.NaN;

		public Chromosome(int[] p) {
			this.p = p;
		}

		public double getCost() {
			return Double.isNaN(cost) ? cost = eval(p) : cost;
		}

		@Override
		public int compareTo(Chromosome o) {
			return Double.compare(getCost(), o.getCost());
		}
	}

	static class Population {
		List<Chromosome> chromosomes = new ArrayList<>();
		final int populationLimit;

		public Population(int populationLimit) {
			this.populationLimit = populationLimit;
		}

		public void nextGeneration() {
			Collections.sort(chromosomes);
			chromosomes = new ArrayList<>(chromosomes.subList(0, (chromosomes.size() + 1) / 2));
		}
	}

	// visualization code
	public GeneticAlgorithm() {
		setContentPane(new JPanel() {
			protected void paintComponent(Graphics g) {
				super.paintComponent(g);
				((Graphics2D) g).setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
				((Graphics2D) g).setStroke(new BasicStroke(3));
				g.setColor(Color.BLUE);
				int w = getWidth() - 5;
				int h = getHeight() - 30;
				for (int i = 0, j = n - 1; i < n; j = i++)
					g.drawLine((int) (x[bestState[i]] * w), (int) ((1 - y[bestState[i]]) * h),
							(int) (x[bestState[j]] * w), (int) ((1 - y[bestState[j]]) * h));
				g.setColor(Color.RED);
				for (int i = 0; i < n; i++)
					g.drawOval((int) (x[i] * w) - 1, (int) ((1 - y[i]) * h) - 1, 3, 3);
				g.setColor(Color.BLACK);
				g.drawString(String.format("length: %.3f", eval(bestState)), 5, h + 20);
				g.drawString(String.format("generation: %d", generation), 150, h + 20);
			}
		});
		setSize(new Dimension(600, 600));
		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		setVisible(true);
		new Thread(this::geneticAlgorithm).start();
	}

	public static void main(String[] args) {
		new GeneticAlgorithm();
	}
}
