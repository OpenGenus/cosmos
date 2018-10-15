struct Point {
    x: f64,
    y: f64
}

struct Triangle {
    a: Point,
    b: Point,
    c: Point
}

impl Triangle {
    fn area(&self) -> f64 {
        // TODO: How can i destructure properly?
        let ref a = self.a;
        let ref b = self.b;
        let ref c = self.c;
        
        ((a.x * b.y) + (a.y * c.x) + (b.x * c.y) 
        - (a.y * b.x) - (a.x * c.y) - (b.y * c.x)).abs() / 2.0
    }
}

#[test]
fn test_tri_area() {
    let tri = Triangle {
        a: Point {
            x: 3.0,
            y: 50.0
        },
        b: Point {
            x: -6.0,
            y: 8.0
        },
        c: Point {
            x: 8.0,
            y: 0.0
        }
    };
    
    assert_eq!(tri.area(), 330.0);
}
