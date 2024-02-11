package naive_bayes;

import java.util.HashMap;
import java.util.Map;

public class NaiveBayes {
    private Map<String, double[]> featureProbabilities; // Probability of features given a class
    private Map<String, Double> classProbabilities; // Probability of each class

    public NaiveBayes() {
        this.featureProbabilities = new HashMap<>();
        this.classProbabilities = new HashMap<>();
    }

    public void train(double[][] data, String[] labels) {
        // Count class occurrences
        Map<String, Integer> classCounts = new HashMap<>();
        for (String label : labels) {
            classCounts.put(label, classCounts.getOrDefault(label, 0) + 1);
        }

        // Calculate class probabilities
        for (Map.Entry<String, Integer> entry : classCounts.entrySet()) {
            classProbabilities.put(entry.getKey(), (double) entry.getValue() / labels.length);
        }

        // Initialize feature probabilities for each class
        for (String className : classProbabilities.keySet()) {
            featureProbabilities.put(className, new double[data[0].length]);
        }

        // Calculate probabilities of features given a class
        for (int i = 0; i < data.length; i++) {
            String label = labels[i];
            for (int j = 0; j < data[i].length; j++) {
                if (data[i][j] == 1) {
                    featureProbabilities.get(label)[j] += 1;
                }
            }
        }

        // Normalize feature probabilities
        for (Map.Entry<String, double[]> entry : featureProbabilities.entrySet()) {
            String className = entry.getKey();
            double[] probs = entry.getValue();
            for (int i = 0; i < probs.length; i++) {
                probs[i] /= classCounts.get(className);
            }
        }
    }

    public String predict(double[] features) {
        String bestClass = null;
        double bestLogProb = Double.NEGATIVE_INFINITY;

        for (Map.Entry<String, Double> classEntry : classProbabilities.entrySet()) {
            String className = classEntry.getKey();
            double classProb = classEntry.getValue();
            double logProb = Math.log(classProb); // Use log probability to avoid underflow

            for (int i = 0; i < features.length; i++) {
                double featureProb = featureProbabilities.get(className)[i];
                logProb += features[i] == 1 ? Math.log(featureProb) : Math.log(1 - featureProb);
            }

            if (logProb > bestLogProb) {
                bestLogProb = logProb;
                bestClass = className;
            }
        }

        return bestClass;
    }

    public static void main(String[] args) {
        NaiveBayes nb = new NaiveBayes();

        // Example training data and labels
        double[][] data = {
                {1, 0},
                {0, 1},
                {0, 0},
                {1, 1}
        };
        String[] labels = {"Yes", "No", "No", "Yes"};

        // Train the classifier
        nb.train(data, labels);

        // Test the classifier
        double[] testPoint = {1, 0};
        String predictedClass = nb.predict(testPoint);
        System.out.println("Predicted class: " + predictedClass);
    }
}
