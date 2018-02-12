# Randomized Algorithms
A randomized algorithm is that which receives in addition to its input data,a stream of random bits for making random choices.
For example, even when the input is fixed the execution time of randomized algorithm is a random variable. <br >
Practically computers can't generate completely random numbers so they are approximated using pseudorandom number generator.
## Types of Randomized Algorithms
* Monte Carlo
* Las Vegas

###### Monte Carlo :
Monte Carlo may produce incorrect answer but we are able to bound its error by probability.Also, by running it many times on independent random variable, we can make failure probability arbitrarily small at the expense of running time.
Polynomical equality-testing is an example of Monte Carlo algorithm.

######  Las Vegas :
Las Vegas algorithm fails with some probability but we can tell when it fails.We can think of Las Vegas algorithm as an algorithm which for an unpredictable amount of time but always succeed(we we can convert such an algorithm back into one that runs in bounded time by declaring that it fails if it runs too long—a condition we can detect).QuickSort is an example of Las Vegas.

<br >


Collaborative effort by [OpenGenus](https://github.com/opengenus)
