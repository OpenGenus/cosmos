//author Yatharth Shah

#ifndef ML_LINEARREGRESSION_H
#define ML_LINEARREGRESSION_H

class LinearRegression {

public:

    // First feature
    double *x;

    // Target feature
    double *y;

    // Number of training examples
    int m;

    // The theta coefficients
    double *theta;

    /**
     * Create a new instance from the given data set.
     */
    LinearRegression(double x[], double y[], int m);

    /**
     * Train the model with the supplied parameters.
     *
     * @param alpha         The learning rate, e.g. 0.01.
     * @param iterations    The number of gradient descent steps to do.
     */
    void train(double alpha, int iterations);

    /**
     * Try to predict y, given an x.
     */
    double predict(double x);

private:

    /**
     * Compute the cost J.
     */
    static double compute_cost(double x[], double y[], double theta[], int m);

    /**
     * Compute the hypothesis.
     */
    static double h(double x, double theta[]);

    /**
     * Calculate the target feature from the other ones.
     */
    static double *calculate_predictions(double x[], double theta[], int m);

    /**
     * Performs gradient descent to learn theta by taking num_items gradient steps with learning rate alpha.
     */
    static double *gradient_descent(double x[], double y[], double alpha, int iters, double *J, int m);

};


#endif //ML_LINEARREGRESSION_H
