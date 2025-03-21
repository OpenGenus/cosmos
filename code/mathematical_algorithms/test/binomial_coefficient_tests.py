# Test suite for the Binomial Coefficient Algorithm. 
# We ran this test suite with pytest. 

# Note: this implementation is the Dynamic Programming solution to the binomial coefficient
# from geeksforgeeks.com. The link is:
# https://www.geeksforgeeks.org/binomial-coefficient-dp-9/

import random
# Please not that we use math.comb which is only available on Python 3.8 or above.
import math
import binomialCoeff() from binomial_coefficient.py

# This function tests the binomial coefficient function by generating a random int for the value of n and k, calculating the binomial coefficient of those values, and asserting that the function calculated the same value.
def test_1():
    n = 10
    k = 5


    assert(binomialCoeff(n,k) == 252)

def test_2():
    n = 234
    k = 40

    assert(binomialCoeff(n,k) == 2090382965619538776890565879870798163571167815)

def test_3():
    n = 399
    k = 78

    assert(binomialCoeff(n,k) == 2081141624878121436255182369875518249771590196600744911784261235252057494896885774670)

def test_4():
    n = 234
    k = 200

    assert(binomialCoeff(n,k) == 97364614941709388140124964830028652656819)

def test_5():
    n = 20
    k = 8

    assert(binomialCoeff(n,k) == 125970)

def test_6():
    n = 15
    k = 25

    assert(binomialCoeff(n,k) == 0)
