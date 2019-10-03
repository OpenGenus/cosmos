# Part of Cosmos by OpenGenus Foundation

import math

# Function returns number of people that should be present for a given probability, p
def compute_people(p):
    return math.ceil(math.sqrt(2 * 365 * math.log(1 / (1 - p))))


# Driver code
if __name__ == "__main__":
    print(compute_people(0.5))
    print(compute_people(0.9))
