#include <iostream>
#include <vector>
using namespace std;

class SVMModel {
public:
    vector<double> weights;
    double bias;

    SVMModel(int numFeatures) : weights(numFeatures, 0), bias(0) {}
};

class SVM {
private:
    static const double LEARNING_RATE;
    static const int MAX_ITERATIONS;

public:
    static SVMModel train(const vector<vector<double>>& features, const vector<int>& labels) {
        int numFeatures = features[0].size();
        SVMModel model(numFeatures);

        for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
            for (size_t i = 0; i < features.size(); i++) {
                const vector<double>& x = features[i];
                int y = labels[i];

                double prediction = predict(model.weights, x, model.bias);
                double hingeLoss = max(0.0, 1 - y * prediction);

                // Update weights and bias using gradient descent
                if (hingeLoss > 0) {
                    for (int j = 0; j < numFeatures; j++) {
                        model.weights[j] -= LEARNING_RATE * (-y * x[j]);
                    }
                    model.bias -= LEARNING_RATE * (-y);
                }
            }
        }

        return model;
    }

    static double predict(const vector<double>& weights, const vector<double>& x, double bias) {
        double result = bias;
        for (size_t i = 0; i < weights.size(); i++) {
            result += weights[i] * x[i];
        }
        return result;
    }
};

const double SVM::LEARNING_RATE = 0.01;
const int SVM::MAX_ITERATIONS = 1000;

int main() {
    vector<vector<double>> features = {{1, 2}, {2, 3}, {3, 4}};
    // Add more training examples as needed

    vector<int> labels = {1, 1, -1};
    // Add corresponding labels for each training example

    SVMModel model = SVM::train(features, labels);

    // Test the trained model
    vector<double> testExample = {4, 5};
    double prediction = SVM::predict(model.weights, testExample, model.bias);
    cout << "Prediction: " << prediction << endl;

    return 0;
}
