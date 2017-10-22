// computational geometry | 2D line intersecton | C#
using System;

/**
Model class which represents a Vector.
**/
class Vector {

  public int x { get; set; }
  public int y { get; set; }

  public Vector(int x, int y) {
    this.x = x;
    this.y = y;
  }

}

/**
Model class which represents a Line in form Ax + By = C
**/
class Line {

  public int A { get; set; }
  public int B { get; set; }
  public int C { get; set; }

  public Line(int a, int b, int c) {
    this.A = a;
    this.B = b;
    this.C = c;
  }
}

/**
Class which provides useful helper methods for straight lines.
**/
class LineOperation {

  /**
  Returns point of intersection, in parent's coordinate space of its parameters
  **/
  public Vector getIntersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int x12 = x1 - x2;
    int x34 = x3 - x4;
    int y12 = y1 - y2;
    int y34 = y3 - y4;

    int c = x12 * y34 - y12 * x34;

    int a = x1 * y2 - y1 * x2;
    int b = x3 * y4 - y3 * x4;

    int x = (a * x34 - b * x12) / c;
    int y = (a * y34 - b * y12) / c;

    return new Vector(x, y);
  }

  /**
  Line segments defined by 2 points a-b and c-d
  **/
  public Vector getIntersection(Vector vec1, Vector vec2, Vector vec3, Vector vec4) {
    return getIntersection(vec1.x, vec1.y, vec2.x, vec2.y, vec3.x, vec3.y, vec4.x, vec4.y);
  }

  // Accepts line in Ax + By = C format
  public Vector getIntersection(Line line1, Line line2) {
    int A1 = line1.A;
    int B1 = line1.B;
    int C1 = line1.C;
    int A2 = line2.A;
    int B2 = line2.B;
    int C2 = line2.C;

    int delta = A1*B2 - A2*B1;
    if (delta == 0)
      Console.WriteLine("Lines are parallel");

    int x = (B2*C1 - B1*C2) / delta;
    int y = (A1*C2 - A2*C1) / delta;

    return new Vector(x, y);
  }
}

// Driver Program
class MainClass {

  static void printVector(Vector intersectionPoint) {
    Console.WriteLine(String.Format("Lines intersect at x:{0}, y:{1}", intersectionPoint.x, intersectionPoint.y ) );
  }
  public static void Main(string[] args) {
    // 3x + 4y = 1
    Line line1 = new Line(3, 4, 1);
    // 2x + 5y = 3
    Line line2 = new Line(2, 5, 3);

    LineOperation lineOperation = new LineOperation();

    Vector intersectionPoint = lineOperation.getIntersection(line1, line2);

    Console.WriteLine("Test using line equation");
    printVector(intersectionPoint);
    Console.WriteLine("Test using points");

    intersectionPoint = lineOperation.getIntersection(new Vector(2, 5), new Vector(5, 3), new Vector(7, 4), new Vector(1, 6) );

    printVector(intersectionPoint);
  }
}
