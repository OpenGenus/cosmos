extern crate nalgebra as na;
extern crate num;


use na::DMatrix;
use na::Scalar;
use na::dimension::Dynamic;
use num::FromPrimitive;
use std::fmt::Display;

trait MazeSolve {
    fn solveMaze(&mut self, end: (usize, usize));
    fn solveMazeRec(&mut self, pos: (usize, usize), end: (usize, usize), ways: &mut usize);
    fn printSolution(&self, end: (usize, usize));
}

const BK: usize = 0;
const BLOCK: usize = 1;
const PASSED: usize = 2;

static START: (usize, usize) = (0, 0);

impl<S> MazeSolve for DMatrix<S>
where
    S: Scalar + Display + FromPrimitive,
{
    fn solveMaze(&mut self, end: (usize, usize)) {
        let mut ways: usize = 0;

        self.solveMazeRec(START, end, &mut ways);
        if ways != 0 {
            println!("Total ways: {}", ways);
        } else {
            println!("No way");
        }
    }
    fn solveMazeRec(&mut self, pos: (usize, usize), end: (usize, usize), ways: &mut usize) {
        unsafe {
            *self.get_unchecked_mut(pos.0, pos.1) = FromPrimitive::from_usize(PASSED).unwrap();
        }
        let check_move = [(0, 1), (1, 0)].to_vec();
        if pos == end {
            *ways += 1;
            println!("Solution {}", *ways);
            self.printSolution(end);
        } else {
            for (m_x, m_y) in check_move {
                let after_mov = (pos.0 + m_x, pos.1 + m_y);
                if after_mov.0 <= end.0 && after_mov.1 <= end.1 {
                    let self_at: S = FromPrimitive::from_usize(BLOCK).unwrap();
                    if self.iter()
                        .enumerate()
                        .filter(|i| {
                            i.0 == after_mov.0 + after_mov.1 * (end.0 + 1) && *i.1 == self_at
                        })
                        .count() == 0
                    {
                        self.solveMazeRec(after_mov, end, ways);
                    }
                }
            }
        }
        unsafe {
            *self.get_unchecked_mut(pos.0, pos.1) = FromPrimitive::from_usize(BK).unwrap();
        }
    }
    fn printSolution(&self, end: (usize, usize)) {
        for (idx, item) in self.iter().enumerate() {
            let bk: S = FromPrimitive::from_usize(BK).unwrap();
            let block: S = FromPrimitive::from_usize(BLOCK).unwrap();
            let passed: S = FromPrimitive::from_usize(PASSED).unwrap();
            let charector = if *item == bk {
                "O"
            } else if *item == block {
                "X"
            } else if *item == passed {
                "*"
            } else {
                "O"
            };
            print!("{position:>1}", position = charector);
            if idx % (end.0 + 1) == end.0 {
                println!();
            }
        }
        println!();
    }
}

fn main() {
    let map_sample = [
        [0, 0, 1, 1, 1],
        [0, 0, 0, 0, 0],
        [0, 1, 1, 0, 0],
        [0, 0, 0, 1, 0],
        [0, 1, 0, 0, 0],
    ];
    let mut map =
        DMatrix::from_fn_generic(Dynamic::new(5), Dynamic::new(5), |r, c| map_sample[c][r]);
    println!("Print Map");
    map.printSolution((4, 4));
    map.solveMaze((4, 4));
}
