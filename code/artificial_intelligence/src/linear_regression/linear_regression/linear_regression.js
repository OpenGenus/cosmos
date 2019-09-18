/**
* Author: Daniel Hernández (https://github.com/DHDaniel)

* Description: Multivariate linear regression that uses the normal equation
* as an optimizer. The normal equation is fine to use
* when n, the number of features being worked with, is
* less than 10,000. Beyond that, it is best to use
* other methods like gradient descent.

* Requirements:
* - mathjs (install using npm)
*/

// this is installed using npm: `npm install mathjs`
const math = require("mathjs");

/**
 * Solves the normal equation and returns the optimum thetas for
 * the model hypothesis.
 * @param {mathjs.matrix} X - a matrix of m x n (rows x columns), where m is the number of records and n is the number of features. It is common practice to add a leading 1 to each row m, in order to account for the y-intercept in regression.
 * @param {mathjs.matrix} y - a vector of m x 1 (rows x columns), where m is the number of records. Contains the labeled values for each corresponding X row.
 * @returns {mathjs.matrix} A n x 1 matrix containing the optimal thetas.
 */
const normalEqn = function normalEqn(X, y) {
  // computing the equation theta = (X^T * X)^-1 * X^T * y
  var thetas = math.multiply(math.transpose(X), X);
  thetas = math.multiply(math.inv(thetas), math.transpose(X));
  thetas = math.multiply(thetas, y);
  // returning a vector containing thetas for hypothesis
  return thetas;
};

/**
 * Trains and returns a function that serves as a model for predicting values y based on an input X
 * @param {mathjs.matrix} X - a matrix of m x n (rows x columns), where m is the number of records and n is the number of features. It is common practice to add a leading 1 to each row m, in order to account for the y-intercept in regression.
 * @param {mathjs.matrix} y - a vector of m x 1 (rows x columns), where m is the number of records. Contains the labeled values for each corresponding X row.
 * @returns {function} A function that accepts a matrix X, and returns predictions for each row.
 */
const train = function train(X, y) {
  // getting optimal thetas using normal equation
  var thetas = normalEqn(X, y);
  // creating a model that accepts
  const model = function(X) {
    // create predictions by multiplying theta^T * X, creating a model that looks like (theta_1 * x_1) + (theta_2 * x_2) + (theta_3 * x_3) etc.
    return math.multiply(math.transpose(thetas), X);
  };
  return model;
};

/* TESTS */

// test values for X and y
var Xmatrix = math.matrix([[2, 1, 3], [7, 1, 9], [1, 8, 1], [3, 7, 4]]);
var ylabels = math.matrix([[2], [5], [5], [6]]);

// should show thetas (in the _data part of object) to be 0.008385744234748138, 0.5681341719077577, 0.4863731656184376
console.log(normalEqn(Xmatrix, ylabels));

// test values #2
Xmatrix = math.matrix([[1], [2], [3], [4]]);
ylabels = math.matrix([[1], [2], [3], [4]]);

// should show theta of 1 (which forms a perfectly diagonal line if plotted)
console.log(normalEqn(Xmatrix, ylabels));

// test values #3
Xmatrix = math.matrix([[1, 5], [1, 2], [1, 4], [1, 5]]);
ylabels = math.matrix([[1], [6], [4], [2]]);

// should show thetas of 9.25 and -1.5
console.log(normalEqn(Xmatrix, ylabels));
