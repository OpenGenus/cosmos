// Part of Cosmos by OpenGenus
const N: usize = 9;
const UNASSIGNED: u8 = 0;

type Board = [[u8; N]; N];

fn solve_sudoku(grid: &mut Board) -> bool {
    let row;
    let col;

    if let Some((r, c)) = find_unassigned_cells(&grid) {
        row = r;
        col = c;
    } else {
        // SOLVED
        return true;
    }
    for num in 1..=9 {
        if is_safe(&grid, row, col, num) {
            grid[row][col] = num;

            if solve_sudoku(grid) {
                return true;
            }

            // Failed, try again
            grid[row][col] = UNASSIGNED;
        }
    }
    false
}

fn used_in_row(grid: &Board, row: usize, num: u8) -> bool {
    for col in 0..N {
        if grid[row][col] == num {
            return true;
        }
    }
    false
}

fn used_in_col(grid: &Board, col: usize, num: u8) -> bool {
    for row in grid.iter().take(N) {
        if row[col] == num {
            return true;
        }
    }
    false
}

fn used_in_box(grid: &Board, row_start: usize, col_start: usize, num: u8) -> bool {
    for row in 0..3 {
        for col in 0..3 {
            if grid[row + row_start][col + col_start] == num {
                return true;
            }
        }
    }
    false
}

fn is_safe(grid: &Board, row: usize, col: usize, num: u8) -> bool {
    !used_in_row(grid, row, num)
        && !used_in_col(grid, col, num)
        && !used_in_box(grid, row - (row % 3), col - (col % 3), num)
}

fn find_unassigned_cells(grid: &Board) -> Option<(usize, usize)> {
    for (row, _) in grid.iter().enumerate().take(N) {
        for col in 0..N {
            if grid[row][col] == UNASSIGNED {
                return Some((row, col));
            }
        }
    }
    None
}

fn print_grid(grid: &Board) {
    for row in grid.iter().take(N) {
        for col in 0..N {
            print!("{}  ", row[col]);
        }
        println!();
    }
}


#[test]
fn test1() {
    let mut board = [
        [3, 0, 6, 5, 0, 8, 4, 0, 0],
        [5, 2, 0, 0, 0, 0, 0, 0, 0],
        [0, 8, 7, 0, 0, 0, 0, 3, 1],
        [0, 0, 3, 0, 1, 0, 0, 8, 0],
        [9, 0, 0, 8, 6, 3, 0, 0, 5],
        [0, 5, 0, 0, 9, 0, 6, 0, 0],
        [1, 3, 0, 0, 0, 0, 2, 5, 0],
        [0, 0, 0, 0, 0, 0, 0, 7, 4],
        [0, 0, 5, 2, 0, 6, 3, 0, 0],
    ];
    // Can solve
    assert!(solve_sudoku(&mut board));
    let solved_board = [
        [3, 1, 6, 5, 7, 8, 4, 9, 2],
        [5, 2, 9, 1, 3, 4, 7, 6, 8],
        [4, 8, 7, 6, 2, 9, 5, 3, 1],
        [2, 6, 3, 4, 1, 5, 9, 8, 7],
        [9, 7, 4, 8, 6, 3, 1, 2, 5],
        [8, 5, 1, 7, 9, 2, 6, 4, 3],
        [1, 3, 8, 9, 4, 7, 2, 5, 6],
        [6, 9, 2, 3, 5, 1, 8, 7, 4],
        [7, 4, 5, 2, 8, 6, 3, 1, 9],
    ];
    assert_eq!(board, solved_board)
}

#[test]
fn test2() {
    let mut board = [
        [2, 0, 0, 9, 0, 0, 1, 0, 0],
        [6, 0, 0, 0, 5, 1, 0, 0, 0],
        [0, 9, 5, 2, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 2, 0, 0],
        [5, 0, 9, 1, 0, 2, 4, 0, 3],
        [0, 0, 8, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 5, 6, 3, 0],
        [0, 0, 0, 4, 6, 0, 0, 0, 9],
        [0, 0, 3, 0, 0, 9, 0, 0, 2],
    ];
    // Can solve
    assert!(solve_sudoku(&mut board));
    let solved = [
        [2, 3, 4, 9, 7, 6, 1, 8, 5],
        [6, 8, 7, 3, 5, 1, 9, 2, 4],
        [1, 9, 5, 2, 4, 8, 3, 7, 6],
        [4, 1, 6, 5, 3, 7, 2, 9, 8],
        [5, 7, 9, 1, 8, 2, 4, 6, 3],
        [3, 2, 8, 6, 9, 4, 7, 5, 1],
        [9, 4, 1, 8, 2, 5, 6, 3, 7],
        [7, 5, 2, 4, 6, 3, 8, 1, 9],
        [8, 6, 3, 7, 1, 9, 5, 4, 2],
    ];
    assert_eq!(board, solved);
}
