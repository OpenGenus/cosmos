# Part of Cosmos by OpenGenus Foundation


def minimum_coins(value, denominations):
    result = []
    # Assuming denominations is sorted in descendig order
    for cur_denom in denominations:
        while cur_denom <= value:
            result.append(cur_denom)
            value = value - cur_denom

    return result


# Testing
def test():
    scenarios = [
        [100, [50, 25, 10, 5, 1], [50, 50]],
        [101, [50, 25, 10, 5, 1], [50, 50, 1]],
        [77, [50, 25, 10, 5, 1], [50, 25, 1, 1]],
        [38, [50, 25, 10, 5, 1], [25, 10, 1, 1, 1]],
        [17, [50, 25, 10, 5, 1], [10, 5, 1, 1]],
        [3, [50, 25, 10, 5, 1], [1, 1, 1]],
        [191, [100, 50, 25, 10, 5, 1], [100, 50, 25, 10, 5, 1]],
    ]

    for scenario in scenarios:
        actual = minimum_coins(scenario[0], scenario[1])
        if actual != scenario[2]:
            message = "Test Failed: Value: {}, Denominations: {}, Expected Result: {}, Actual Result: {}".format(
                scenario[0], scenario[1], scenario[2], actual
            )
            print(message)


test()
