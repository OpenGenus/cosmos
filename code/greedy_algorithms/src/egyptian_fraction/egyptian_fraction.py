# Part of Cosmos by OpenGenus Foundation

import math
import fractions


def fibonacciEgyptian(numerator, denominator, current_fraction=[]):
    # Fibonacci's algorithm implementation
    inverse = denominator / numerator
    first_part = fractions.Fraction(1, math.ceil(inverse))
    second_part = fractions.Fraction(
        int(-denominator % numerator), denominator * math.ceil(inverse)
    )
    current_fraction.append(first_part)
    if second_part.numerator != 1:
        return fibonacciEgyptian(
            second_part.numerator, second_part.denominator, current_fraction
        )
    else:
        current_fraction.append(second_part)
        print(current_fraction)
        return current_fraction
