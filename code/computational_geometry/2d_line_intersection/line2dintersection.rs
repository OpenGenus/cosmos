extern crate nalgebra as na;
extern crate num;

use num::NumCast;

struct Line {
    p1: (f64, f64),
    p2: (f64, f64),
}

impl Line {
    fn convert_f64<S: NumCast>(pos: (S, S)) -> (f64, f64) {
        (NumCast::from(pos.0).unwrap(), NumCast::from(pos.1).unwrap())
    }
    fn new<S: NumCast>(p_1: (S, S), p_2: (S, S)) -> Self {
        Line {
            p1: Line::convert_f64(p_1),
            p2: Line::convert_f64(p_2),
        }
    }
    fn intersect(line1: &Line, line2: &Line) -> (f64, f64) {
        let (l1_x, l1_y) = (line1.p1.0 - line1.p2.0, line1.p1.1 - line1.p2.1);
        let (l2_x, l2_y) = (line2.p1.0 - line2.p2.0, line2.p1.1 - line2.p2.1);

        let c = l1_x * l2_y - l1_y * l2_x;

        let a = line1.p1.0 * line1.p2.1 - line1.p1.1 * line1.p2.0;
        let b = line2.p1.0 * line2.p2.1 - line2.p1.1 * line2.p2.0;

        ((a * l2_x - b * l1_x) / c, (a * l2_y - b * l1_y) / c)
    }
    fn is_in_line(&self, pos: (f64, f64)) -> bool {
        let (l_x, l_y) = (self.p1.0 - self.p2.0, self.p1.1 - self.p2.1);
        let (p_x, p_y) = (self.p1.0 - pos.0, self.p1.1 - pos.1);
        if l_y / l_x == p_y / p_x || l_y / l_x == -p_y / p_x {
            true
        } else {
            false
        }
    }
}

fn main() {
    let line1 = Line::new((10, 3), (20, 10));
    let line2 = Line::new((10, 10), (20, 3));
    let intersect = Line::intersect(&line1, &line2);

    if line1.is_in_line(intersect) && line2.is_in_line(intersect) {
        println!("intersection : ({},{})", intersect.0, intersect.1);
    } else {
        println!("no intersection");
    }
}
