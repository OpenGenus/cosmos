extern crate nalgebra as na;
extern crate num;
#[macro_use]
extern crate lazy_static;

use na::DMatrix;
use na::Scalar;
use na::dimension::Dynamic;
use num::FromPrimitive;
use std::sync::{Arc, Mutex};
use std::io;
use std::fmt::Display;

const BK: isize = 0;
const Q: isize = 1;

trait Nqueen {
    fn isSafe(&self, x: isize, y: isize) -> bool;
    fn solveNqueenRec(&mut self, i: isize) -> bool;
    fn printSolution(&self);
    fn solveNqueen(&mut self);
    fn between(&self, pos: isize) -> bool {
        pos >= 0 && pos < *N.lock().unwrap() as isize
    }
}
impl<S> Nqueen for DMatrix<S>
where
    S: Scalar + Display + FromPrimitive,
{
    fn isSafe(&self, x: isize, y: isize) -> bool {
        let mut result = true;
        let n = *N.lock().unwrap();
        if self.between(x) && self.between(y) {
            result = self.iter()
                .enumerate()
                .filter(|ci| {
                    let temp: S = FromPrimitive::from_isize(Q).unwrap();
                    *ci.1 == temp
                })
                .filter(|cw| {
                    let diffx = x - (cw.0 % n) as isize;
                    let diffy = y - (cw.0 / n) as isize;
                    match (diffx, diffy) {
                        (0, 0) => false,
                        (0, _) => true,
                        (_, 0) => true,
                        (t_x, t_y) => {
                            if t_x == t_y || t_x == -t_y {
                                true
                            } else {
                                false
                            }
                        }
                    }
                })
                .count() == 0;
        }
        result
    }
    fn solveNqueen(&mut self) {
        if self.solveNqueenRec(0) {
            self.printSolution();
        } else {
            println!("Solution does not exist");
        }
    }
    fn solveNqueenRec(&mut self, i: isize) -> bool {
        let n = *N.lock().unwrap() as isize;
        if i == n {
            true
        } else {
            let mut result = false;
            for j in 0..n {
                if self.isSafe(i, j) {
                    unsafe {
                        *self.get_unchecked_mut(i as usize, j as usize) =
                            FromPrimitive::from_isize(Q).unwrap();
                    }
                    if self.solveNqueenRec(i + 1) {
                        result = true;
                        break;
                    }
                    unsafe {
                        *self.get_unchecked_mut(i as usize, j as usize) =
                            FromPrimitive::from_isize(BK).unwrap();
                    }
                }
            }
            result
        }
    }
    fn printSolution(&self) {
        let n = *N.lock().unwrap();
        for (idx, item) in self.iter().enumerate() {
            print!("{position:>1}", position = item);
            if idx % n == (n - 1) {
                println!();
            }
        }
    }
}

lazy_static! {
    static ref N: Arc<Mutex<usize>> = Arc::new(Mutex::new(0));
}
fn main() {
    println!("Please Enter the size of the Map");
    let mut input_str = String::new();
    io::stdin().read_line(&mut input_str).unwrap();
    if let Ok(t) = input_str.trim().parse::<usize>() {
        *N.lock().unwrap() = t;
        let DimN = Dynamic::new(t);
        let mut map = DMatrix::from_element_generic(DimN, DimN, BK);
        map.solveNqueen();
    }
}

