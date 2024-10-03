"""
Part of Cosmos by OpenGenus Foundation
"""


# Item class with weight and values
class Item:

    # intialize weight and values
    def __init__(self, weight=0, value=0):

        self.weight = weight
        self.value = value

        return


def fractional_knapsack(items, W):

    # Sorting items by value /weight
    sorted(items, key=lambda item: float(item.value) / float(item.weight))

    finalValue = 0.0
    currentWeight = 0

    for item in items:

        if currentWeight + item.weight <= W:
            # If adding Item won't overflow, add it completely
            finalValue += item.value
            currentWeight += item.weight

        else:
            # If we can't add current Item, add a fraction of it
            remaining = W - currentWeight
            finalValue += item.value * (float(remaining) / float(item.weight))
            break

    return finalValue


def main():

    W = 50

    items = [Item(10, 60), Item(20, 100), Item(30, 120)]

    print("Maximum value we can obtain -{}".format(fractional_knapsack(items, W)))

    return


if __name__ == "__main__":

    main()
