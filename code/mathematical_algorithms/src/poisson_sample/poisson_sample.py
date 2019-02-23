from random import random
from math import exp
from math import factorial


def poisson_sample(mean, n=1):
    "Return a list containing n samples from a Poisson distribution with specified mean"
    sample = []
    for i in range(n):
        rand_num = random()  # get a uniform random number in [0, 1)
        count = 0
        while rand_num > 0:  # Uses the inversion method to generate values
            rand_num -= (
                mean ** count * exp(-mean) / factorial(count)
            )  # Subtract P(X=count)
            count += 1
        sample.append(count - 1)
    return sample
