struct Point {
    x: f64,
    y: f64
}

impl Point {
    fn distance_to(&self, b: &Point) -> f64 {
        ((self.x - b.x) * (self.x - b.x) + (self.y - b.y) * (self.y - b.y)).sqrt()
    }   
}

#[test]
fn test_point_distance() {
    // Make 2 points
    // (0,0), (3,4), distance should be 5
    let a = Point { x: 0.0, y: 0.0 };
    let b = Point { x: 3.0, y: 4.0 };

    assert_eq!(a.distance_to(&b), 5.0);
}
