extern crate nalgebra as na;
extern crate num;

use na::DMatrix;
use na::Scalar;
use na::dimension::Dynamic;
use std::fmt::Display;
use num::FromPrimitive;

const N: usize = 5; //map size N x N
trait ChessFunc {
    fn isSafe(&self, x: isize, y: isize) -> bool;
    fn solveKTUtil(
        &mut self,
        x: isize,
        y: isize,
        movei: usize,
        moves: &Vec<(isize, isize)>,
    ) -> bool;
    fn printSolution(&self);
    fn solveKT(&mut self);
}
impl<S> ChessFunc for DMatrix<S>
where
    S: Scalar + Display + FromPrimitive,
{
    fn solveKT(&mut self) {
        let moves = [
            (2, 1),
            (1, 2),
            (-1, 2),
            (-2, 1),
            (-2, -1),
            (-1, -2),
            (1, -2),
            (2, -1),
        ].to_vec(); //knight movement

        if self.solveKTUtil(0, 0, 1, &moves) {
            self.printSolution();
        } else {
            println!("Solution does not exist");
        }
    }
    fn solveKTUtil(
        &mut self,
        x: isize,
        y: isize,
        movei: usize,
        moves: &Vec<(isize, isize)>,
    ) -> bool {
        if movei == N * N {
            true
        } else {
            let mut result = false;
            for cnt in 0..moves.len() {
                let next_x: isize = x + moves[cnt].0;
                let next_y: isize = y + moves[cnt].1;

                if self.isSafe(next_x, next_y) {
                    unsafe {
                        *self.get_unchecked_mut(next_x as usize, next_y as usize) =
                            FromPrimitive::from_usize(movei).unwrap();
                    }
                    if self.solveKTUtil(next_x, next_y, movei + 1, moves) {
                        result = true;
                        break;
                    } else {
                        unsafe {
                            *self.get_unchecked_mut(next_x as usize, next_y as usize) =
                                FromPrimitive::from_isize(-1).unwrap();
                        }
                    }
                }
            }
            result
        }
    }
    fn printSolution(&self) {
        for (idx, item) in self.iter().enumerate() {
            print!("{position:>3}", position = item);
            if idx % N == (N - 1) {
                println!();
            }
        }
    }
    fn isSafe(&self, x: isize, y: isize) -> bool {
        let mut result = false;
        //println!("({},{})", x, y);
        match ((x + 1) as usize, (y + 1) as usize) {
            (1...N, 1...N) => {
                match self.iter().nth((y * N as isize + x) as usize) {
                    Some(sc) => {
                        let temp: S = FromPrimitive::from_isize(-1).unwrap();
                        if temp == *sc {
                            result = true;
                        }
                    }
                    None => {}
                };
            }
            _ => {}
        }
        //println!("({})", result);
        result
    }
}

fn main() {
    let DimN = Dynamic::new(N); //from nalgebra make dynamic dimension in here make N dimension
    let mut chessmap = DMatrix::from_fn_generic(DimN, DimN, |r, c| match (r, c) {
        (0, 0) => 0,
        _ => -1,
    }); //initialize matrix (0,0) set 0 and the others set -1
    //chessmap.printSolution();
    chessmap.solveKT(); //solve problum
}

