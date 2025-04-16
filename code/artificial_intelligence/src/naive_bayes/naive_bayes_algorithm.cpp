// ### Naive Bayes Classifier Implementation

// This PR adds an implementation of the Naive Bayes classifier with the following features:
// - Training with Laplace smoothing.
// - Prediction based on log-probabilities.
// - Data input from CSV or manual user input.
// - Model parameters and predictions are displayed.

// ### Time Complexity:
// - **fit()**: O(n * m) - where `n` is the number of training samples, and `m` is the number of features.
// - **predict()**: O(t * m * k) - where `t` is the number of test samples, `m` is the number of features, and `k` is the number of classes.
// - **load_data_from_csv()**: O(n * m) - where `n` is the number of data samples, and `m` is the number of features.
// - **interactive_input()**: O(n * m) - where `n` is the number of samples, and `m` is the number of features.

// ### Space Complexity:
// - **fit()**: O(k * m) - where `k` is the number of classes, and `m` is the number of features.
// - **predict()**: O(t) - where `t` is the number of test samples.
// - **Data Storage**: O(n * m) for training data, O(t * m) for test data.
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class NaiveBayes {
private:
    double laplace_smoothing;
    vector<int> classes;
    map<int, int> class_indices;
    vector<double> class_priors;
    map<int, map<int, int>> feature_counts; 
    map<int, int> class_counts;  
    map<int, int> feature_sums;  
    int num_features;

    vector<double> split_string(const string& s, char delimiter) {
        vector<double> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(stod(token));
        }
        return tokens;
    }

public:
    NaiveBayes(double smoothing = 1.0) : laplace_smoothing(smoothing), num_features(0) {}

    void fit(const vector<vector<double>>& X, const vector<int>& y) {
        // Get unique sorted classes
        set<int> unique_classes(y.begin(), y.end());
        classes.assign(unique_classes.begin(), unique_classes.end());
        sort(classes.begin(), classes.end());


        for (size_t i = 0; i < classes.size(); ++i) {
            class_indices[classes[i]] = i;
        }

        class_counts.clear();
        feature_counts.clear();
        feature_sums.clear();

        vector<int> counts(classes.size(), 0);
        for (int label : y) {
            counts[class_indices[label]]++;
        }

        class_priors.resize(classes.size());
        for (size_t i = 0; i < classes.size(); ++i) {
            class_priors[i] = static_cast<double>(counts[i]) / y.size();
        }

        num_features = X[0].size();  // Number of features in the data
        for (size_t i = 0; i < y.size(); ++i) {
            int label = y[i];
            class_counts[label]++;

            for (size_t j = 0; j < num_features; ++j) {
                int feature_value = static_cast<int>(X[i][j]);  // Assuming features are discrete
                feature_counts[label][feature_value]++;
                feature_sums[label]++;
            }
        }
    }

    vector<int> predict(const vector<vector<double>>& X) {
        vector<int> predictions;
        for (const auto& sample : X) {
            vector<double> log_probs;
            for (int cls : classes) {
                int idx = class_indices[cls];
                
                double log_prob = log(class_priors[idx]);
                
                for (size_t j = 0; j < sample.size(); ++j) {
                    int feature_value = static_cast<int>(sample[j]);
                    
                    int feature_count = feature_counts[cls][feature_value];
                    int total_feature_count = feature_sums[cls];
                    
                    // Apply Laplace smoothing
                    double feature_prob = (feature_count + laplace_smoothing) / (total_feature_count + laplace_smoothing * num_features);
                    log_prob += log(feature_prob);
                }

                log_probs.push_back(log_prob);
            }

            auto max_it = max_element(log_probs.begin(), log_probs.end());
            int pred_class = classes[distance(log_probs.begin(), max_it)];
            predictions.push_back(pred_class);
        }
        return predictions;
    }

    void load_data_from_csv(const string& filename, vector<vector<double>>& X, vector<int>& y, bool has_header = false) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        string line;
        if (has_header) {
            getline(file, line); // Skip header
        }

        while (getline(file, line)) {
            vector<double> values = split_string(line, ',');
            if (values.size() < 2) {
                cerr << "Invalid data format in line: " << line << endl;
                continue;
            }

            // Last value is the class label
            y.push_back(static_cast<int>(values.back()));
            values.pop_back();
            X.push_back(values);
        }
    }

    void interactive_input(vector<vector<double>>& X, vector<int>& y) {
        cout << "Enter number of samples: ";
        int num_samples;
        cin >> num_samples;

        cout << "Enter number of features: ";
        int num_features;
        cin >> num_features;

        cout << "Enter data (features followed by class label for each sample):" << endl;
        for (int i = 0; i < num_samples; ++i) {
            cout << "Sample " << i + 1 << ": ";
            vector<double> sample;
            for (int j = 0; j < num_features; ++j) {
                double value;
                cin >> value;
                sample.push_back(value);
            }
            int label;
            cin >> label;
            X.push_back(sample);
            y.push_back(label);
        }
    }

    void print_model() {
        cout << "\nTrained Model Parameters:\n";
        cout << "Classes: ";
        for (int cls : classes) {
            cout << cls << " ";
        }
        cout << "\n\n";

        for (int cls : classes) {
            cout << "Class " << cls << ":\n";
            cout << "  Prior probability: " << class_priors[class_indices[cls]] << "\n";
            cout << "  Feature counts: ";
            for (const auto& feature_count : feature_counts[cls]) {
                cout << feature_count.first << ": " << feature_count.second << " ";
            }
            cout << "\n\n";
        }
    }
};

int main() {
    NaiveBayes nb;
    vector<vector<double>> X_train;
    vector<int> y_train;
    vector<vector<double>> X_test;

    cout << "NAIVE BAYES CLASSIFIER\n";
    cout << "======================\n\n";

    int choice;
    cout << "Choose input method:\n";
    cout << "1. Load from CSV file\n";
    cout << "2. Enter data manually\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        string filename;
        cout << "Enter training data filename: ";
        cin >> filename;
        nb.load_data_from_csv(filename, X_train, y_train);
    } else {
        nb.interactive_input(X_train, y_train);
    }

    // Train the model
    nb.fit(X_train, y_train);
    nb.print_model();

    // Prediction phase
    cout << "\nPREDICTION PHASE\n";
    cout << "Enter test data input method:\n";
    cout << "1. Load from CSV file\n";
    cout << "2. Enter data manually\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        string filename;
        cout << "Enter test data filename: ";
        cin >> filename;
        vector<int> dummy_labels;
        nb.load_data_from_csv(filename, X_test, dummy_labels);
    } else {
        cout << "Enter number of test samples: ";
        int num_samples;
        cin >> num_samples;

        if (num_samples > 0 && X_train.size() > 0) {
            cout << "Enter " << X_train[0].size() << " features for each sample:\n";
            for (int i = 0; i < num_samples; ++i) {
                cout << "Test sample " << i + 1 << ": ";
                vector<double> sample;
                for (size_t j = 0; j < X_train[0].size(); ++j) {
                    double value;
                    cin >> value;
                    sample.push_back(value);
                }
                X_test.push_back(sample);
            }
        }
    }

    if (!X_test.empty()) {
        vector<int> predictions = nb.predict(X_test);
        cout << "\nPredictions:\n";
        for (size_t i = 0; i < predictions.size(); ++i) {
            cout << "Test sample " << i + 1 << ": " << predictions[i] << endl;
        }
    } else {
        cout << "No test data provided.\n";
    }

    return 0;
}
