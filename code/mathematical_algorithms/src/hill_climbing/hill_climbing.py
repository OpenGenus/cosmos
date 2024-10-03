import math

def hill_climbing(function, start, max_iterations, neighbor_function):
    best_eval = -math.inf
    current = start
    best = None
    for _i in range(max_iterations):
        if function(current) > best_eval:
            best_eval = function(current)
            best = current
        neighbors = neighbor_function(current)
        temp_max_eval = -math.inf
        for neighbor in neighbors:
            if function(neighbor) > temp_max_eval:
                current = neighbor
                temp_max_eval = function(neighbor)
    return best

def neighbor(value):
    return [value + 1, value - 1]

if __name__ == "__main__":
    function = lambda x: -(x-2)**2
    best = hill_climbing(function, 10, 100, neighbor)
    print(best)
