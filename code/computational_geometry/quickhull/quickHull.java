/* Part of Cosmos by OpenGenus Foundation */

import java.util.ArrayList;
import java.util.Scanner;

public class quickHull {
    public static class Point {
        private final int x;
        private final int y;
        private final int pos;
        public Point(final int x, final int y, final int p) {
            this.x = x;
            this.y = y;
            this.pos = p;
        }
    }

    public static double dist(Point p1, Point p2) {
        return Math.sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    }

    public static Point getLeftMostBottomPoint(ArrayList<Point> points) {

        Point result = points.get(0);
        for(int i = 1; i < points.size(); i++) {
            if(points.get(i).x < result.x || (points.get(i).x == result.x && points.get(i).y < result.y)) {
                result = points.get(i);
            }
        }

        return result;
    }

    public static Point getRightMostUpperPoint(ArrayList<Point> points) {

        Point result = points.get(0);
        for(int i = 1; i < points.size(); i++) {
            if(points.get(i).x > result.x || (points.get(i).x == result.x && points.get(i).y > result.y)) {
                result = points.get(i);
            }
        }

        return result;
    }


    // Partition P with respect to line joining A and B
    public static int partition(Point A, Point B, Point P) {
        int cp1 = (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
        if (cp1 > 0) return 1;
        else if (cp1 == 0) return 0;
        else return -1;
    }

    // https://brilliant.org/wiki/distance-between-point-and-line/
    public static int distance(Point A, Point B, Point C) {
        return Math.abs((B.x - A.x) * (A.y - C.y) - (B.y - A.y) * (A.x - C.x));
    }

    public static ArrayList<Point> quickHull(ArrayList<Point> points) {
        ArrayList<Point> convexHull = new ArrayList<Point>();
        if (points.size() < 3) return (new ArrayList<Point> (points));

        Point leftMostBottom = getLeftMostBottomPoint(points);
        Point rightMostUpper = getRightMostUpperPoint(points);
        points.remove(leftMostBottom);
        points.remove(rightMostUpper);
        convexHull.add(leftMostBottom);
        convexHull.add(rightMostUpper);

        ArrayList<Point> leftPart = new ArrayList<>();
        ArrayList<Point> rightPart = new ArrayList<>();

        for(int i = 0; i < points.size(); i++) {
            Point p = points.get(i);
            if(partition(leftMostBottom, rightMostUpper,p) == -1) {
                leftPart.add(p);
            } else if(partition(leftMostBottom, rightMostUpper, p) == 1) {
                rightPart.add(p);
            }
        }

        hullSet(leftMostBottom, rightMostUpper, rightPart, convexHull);
        hullSet(rightMostUpper, leftMostBottom, leftPart, convexHull);

        return convexHull;
    }

    public static void hullSet(Point a, Point b, ArrayList<Point> set, ArrayList<Point> hull) {
        int insertPosition = hull.indexOf(b);
        if (set.size() == 0) return;
        if (set.size() == 1) {
            Point p = set.get(0);
            set.remove(p);
            hull.add(insertPosition, p);
            return;
        }

        int furthestDist = 0;
        Point furthestPoint = null;
        for (int i = 0; i < set.size(); i++) {
            Point p = set.get(i);
            int distance = distance(a, b, p);
            if (distance > furthestDist) {
                furthestDist = distance;
                furthestPoint = p;
            }
        }

        set.remove(furthestPoint);
        hull.add(insertPosition, furthestPoint);

        // Determine who's to the left of line joining a and furthestPoint
        ArrayList<Point> leftSet = new ArrayList<Point>();
        for (int i = 0; i < set.size(); i++) {
            Point current = set.get(i);
            if (partition(a, furthestPoint, current) == 1) {
                leftSet.add(current);
            }
        }

        hullSet(a, furthestPoint, leftSet, hull);

        // Determine who's to the left of line joining furthestPoint and b
        leftSet = new ArrayList<>();
        for (int i = 0; i < set.size(); i++) {
            Point current = set.get(i);
            if (partition(furthestPoint, b, current) == 1) {
                leftSet.add(furthestPoint);
            }
        }

        hullSet(furthestPoint, b, leftSet, hull);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        ArrayList<Point> points = new ArrayList<>();
        for(int i = 0; i < N; i++) {
            int x = in.nextInt(), y = in.nextInt();
            points.add(new Point(x, y, i+1));
        }
	
        ArrayList<Point> hull = quickHull(points);
        double ans = 0;
        for(int i = 1; i < hull.size(); i++) {
            ans += dist(hull.get(i), hull.get(i-1));
        }
        
        ans += dist(hull.get(0), hull.get(hull.size()-1));
        if(hull.size() == 1) ans = 0;
        System.out.println(ans);
        System.out.println("Points on the hull are:");
        for(Point p: hull) {
            System.out.print(p.pos+" ");
        }
    }
}
