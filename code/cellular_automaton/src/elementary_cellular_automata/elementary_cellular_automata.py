import random, copy, math

random_start = False

# Ruleset that can be changed to any other rule
# Example rules found here: http://atlas.wolfram.com/01/01/
rules = {
    (1, 1, 1): 0,
    (1, 1, 0): 1,
    (1, 0, 1): 0,
    (1, 0, 0): 1,
    (0, 1, 1): 1,
    (0, 1, 0): 0,
    (0, 0, 1): 1,
    (0, 0, 0): 0,
}

# Grid to hold the results of the rules
grid = []


def main():
    width, height = 40, 40

    current_row = []

    # Creates a random starting state for the automata
    if random_start:
        for i in range(0, width):
            alive = int(random.getrandbits(1))
            current_row.append(alive)

    # Creates a known state with only one alive element
    else:
        for i in range(0, width):
            current_row.append(0)
        current_row[int(width / 2)] = 1

    grid.append(current_row)

    next_row = copy.deepcopy(current_row)

    for k in range(height):

        # Determine the next row state by comparing rules
        for j in range(0, len(current_row) - 2):
            alive = rules[(current_row[j], current_row[j + 1], current_row[j + 2])]
            next_row[j + 1] = alive

        alive = rules[
            (current_row[len(current_row) - 1], current_row[0], current_row[1])
        ]
        next_row[0] = alive

        alive = rules[
            (
                current_row[len(current_row) - 2],
                current_row[len(current_row) - 1],
                current_row[0],
            )
        ]
        next_row[len(next_row) - 1] = alive

        current_row = copy.deepcopy(next_row)

        grid.append(current_row)

    grid_to_string(grid)


# Output the final grid into a string
def grid_to_string(grid):
    output = ""

    for row in grid:
        for element in row:
            output += str(element)
        output += "\n"

    print output


if __name__ == "__main__":
    main()
