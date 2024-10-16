# Maze size
N = 4

def solve_maze_util(maze, x, y, sol):
    # if (x,y is goal) return True
    if x == N - 1 and y == N - 1:
        sol[x][y] = 1
        return True

    # Check if maze[x][y] is valid
    if is_safe(maze, x, y):
        # Mark x,y as part of solution path
        sol[x][y] = 1

        # Move forward in x direction
        if solve_maze_util(maze, x + 1, y, sol):
            return True

        # If moving in x direction doesn't give a solution then move down in y direction
        if solve_maze_util(maze, x, y + 1, sol):
            return True

        # If none of the above movements work, then BACKTRACK: unmark x,y as part of the solution path
        sol[x][y] = 0
        return False

    return False

def is_safe(maze, x, y):
    # if (x,y outside maze) return False
    if 0 <= x < N and 0 <= y < N and maze[x][y] == 1:
        return True
    return False

def print_solution(sol):
    for row in sol:
        for val in row:
            print(val, end=' ')
        print()

def solve_maze(maze):
    sol = [[0 for _ in range(N)] for _ in range(N)]

    if not solve_maze_util(maze, 0, 0, sol):
        print("Solution doesn't exist")
        return False

    print_solution(sol)
    return True

# Driver program to test above function
if __name__ == "__main__":
    maze = [[1, 0, 0, 0],
            [1, 1, 0, 1],
            [0, 1, 0, 0],
            [1, 1, 1, 1]]

    solve_maze(maze)
