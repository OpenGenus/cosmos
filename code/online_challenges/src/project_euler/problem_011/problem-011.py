import os


def parse_grid(lines):
    grid = []
    for line in lines:
        row = []
        for i in line.rstrip('\n').split():
            row.append(int(i))
        grid.append(row)
    return grid


def main():
    grid = parse_grid(open(os.path.join(os.path.dirname(
        os.path.realpath(__file__)), 'grid.txt')).readlines())
    greatest = 0

    for i in range(len(grid)):
        for j in range(len(grid) - 3):
            n = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3]
            if n > greatest:
                greatest = n

    # VERTICAL
    for i in range(len(grid) - 3):
        for j in range(len(grid)):
            n = grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j]
            if n > greatest:
                greatest = n

    # DIAGONAL from T-L to B-R
    for i in range(len(grid) - 3):
        for j in range(len(grid) - 3):
            n = grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3]
            if n > greatest:
                greatest = n

    # DIAGONAL from T-R to B-L
    for i in range(len(grid) - 3):
        for j in range(3, len(grid)):
            n = grid[i][j] * grid[i+1][j-1] * grid[i+2][j-2] * grid[i+3][j-3]
            if n > greatest:
                greatest = n

    print(greatest)


if __name__ == '__main__':
    main()
