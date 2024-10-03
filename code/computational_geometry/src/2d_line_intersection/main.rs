use std::fmt;

struct P2{
    x: f64,
    y: f64
}
impl P2 {
    fn new(x: f64,y: f64) -> Self{
        P2 {
            x , y 
        }
    }
}
impl fmt::Display for P2 {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "({}, {})", self.x, self.y)
    }
}

struct LIn2{
    co_factors: (f64,f64),
    cons: f64
}
impl LIn2{
    fn new(co_factors: (f64,f64),cons:f64)-> Self{
        LIn2{
            co_factors,cons
        }
    }
    fn new_by_two_point(point1: P2,point2: P2) -> Self{
        let factor_y = point1.x-point2.x;
        let factor_x = point2.y-point1.y;
        
        let cons = factor_y*point1.y + factor_x*point1.x;
 
        Self::new((factor_x,factor_y),cons)
    }
    fn intersect(origin: Self,other: Self)->Option<P2>{
        let a=origin.co_factors.0;
        let b=origin.co_factors.1;
        let c=other.co_factors.0;
        let d=other.co_factors.1;
        
        let det_m= a*d-b*c;
        if det_m == 0.0{
            None
        }else{
            let x1 = origin.cons;
            let x2 = other.cons;
            
            Some(
            P2{
                x: (d*x1-b*x2)/det_m,
                y: (-c*x1+a*x2)/det_m
            }
            )
        }
    }
}
fn main() {
    let pa = P2::new(10.0,3.0);
    let pb = P2::new(20.0,10.0);
    let pc = P2::new(10.0,10.0);
    let pd = P2::new(20.0,3.0);
    
    let line_1 = LIn2::new_by_two_point(pa,pb);
    let line_2 = LIn2::new_by_two_point(pc,pd);
    
    match LIn2::intersect(line_1,line_2){
        Some(value) =>{
            println!("intersection is {}",value);
        },
        None => {
            println!("there is no intersection");
        }
    }

}
