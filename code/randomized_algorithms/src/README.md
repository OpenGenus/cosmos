# Randomized Algorithms
A randomized algorithm is that which receives in addition to its input data,a stream of random bits for making random choices.
For example, even when the input is fixed the execution time of randomized algorithm is a random variable. <br >
Practically computers can't generate completely random numbers so they are approximated using pseudorandom number generator.
## Types of Randomized Algorithms
* Monte Carlo
* Las Vegas

###### Monte Carlo :
Monte Carlo may produce incorrect answer but we are able to bound its error by probability.Also, by running it many times on independent random variable, we can make failure probability arbitrarily small at the expense of running time.<br >
```Karger's algorithm for minimum cut``` is an example of Monte Carlo algorithm.<br >
**Implementation:** [Karger Algorithm](https://github.com/RN0311/cosmos/tree/master/code/randomized_algorithms/src/karger_minimum_cut_algorithm)

######  Las Vegas :
Las Vegas algorithm fails with some probability but we can tell when it fails.We can think of Las Vegas algorithm as an algorithm which for an unpredictable amount of time but always succeed(we we can convert such an algorithm back into one that runs in bounded time by declaring that it fails if it runs too long—a condition we can detect).<br >
```QuickSort``` is an example of Las Vegas.<br >
**Implementation:** [Quick Sort](https://github.com/RN0311/cosmos/tree/master/code/randomized_algorithms/src/randomized_quick_sort)


###### Monte Carlo Vs Las Vegas

```
* A Monte Carlo algorithm produces an answer that is correct with non-zero probability,whereas Las Vegas 
algorithm always produces the correct answer.

* The running time of both types of randomized algorithms is a random variable whose expectation is 
bounded in general by a polynomial in terms of input size.

* These expectations are only over the random choices made by the algorithm independent of the input.
Thus independent repetitions of Monte Carlo algorithms drive down the failure probability exponentially.

```
<br >
Collaborative effort by [OpenGenus](https://github.com/opengenus)
