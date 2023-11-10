import java.util.*;

public class GrahamScan {

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

    public static int ccw(Point a, Point b, Point c) {
        int cross = ((b.x - a.x) * (c.y - a.y)) - ((b.y - a.y) * (c.x - a.x));

        if(cross > 0) {
            return -1;
        } else if(cross < 0) {
            return 1;
        } else {
            return 0;
        }
    }

    public static Point getBottomMostLeftPoint(List<Point> points) {

        Point lowest = points.get(0);
        for(int i = 1; i < points.size(); i++) {
            if(points.get(i).y < lowest.y || (points.get(i).y == lowest.y && points.get(i).x < lowest.x)) {
                lowest = points.get(i);
            }
        }

        return lowest;
    }

    public static void sortByPolarAngle(ArrayList<Point> points) {
        final Point bottomMostLeft = getBottomMostLeftPoint(points);
        Collections.sort(points, new Comparator<Point>() {
            @Override
            public int compare(Point a, Point b) {
                double angleA = Math.atan2(a.y - bottomMostLeft.y, a.x - bottomMostLeft.x);
                double angleB = Math.atan2(b.y - bottomMostLeft.y, b.x - bottomMostLeft.x);

                if(angleA < angleB) {
                    return 1;
                } else if(angleA > angleB) {
                    return -1;
                } else {
                    if(dist(a, bottomMostLeft) < dist(b, bottomMostLeft)) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        });
    }

    public static ArrayList<Point> getConvexHull(ArrayList<Point> points) {
        if(points.size() == 1) {
            return points;
        }

        sortByPolarAngle(points);
        Collections.reverse(points);

        ArrayList<Point> hull = new ArrayList<>();
        hull.add(points.get(0));
        hull.add(points.get(1));
        for(int i = 2; i < points.size(); i++) {
            Point c = points.get(i);
            Point b = hull.get(hull.size()-1);
            Point a = hull.get(hull.size()-2);

            switch (ccw(a, b, c)) {
                case -1:
                    hull.add(c);
                    break;
                case 1:
                    hull.remove(hull.size()-1);
                    i--;
                    break;
                case 0:
                    hull.remove(hull.size()-1);
                    hull.add(c);
                    break;
            }
        }

        hull.add(hull.get(0));
        return hull;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();

        ArrayList<Point> points = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            int x = in.nextInt(), y = in.nextInt();
            Point p = new Point(x, y, i + 1);
            points.add(p);
        }

        Collections.sort(points, new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                if (o1.x == o2.x) {
                    return o1.y - o2.y;
                } else {
                    return o1.x - o2.x;
                }
            }
        });


        ArrayList<Point> temp = new ArrayList<>();
        temp.add(points.get(0));
        for(int i = 1; i < N; i++) {
            if(points.get(i).x != points.get(i-1).x || points.get(i).y != points.get(i-1).y) {
                temp.add(points.get(i));
            }
        }

        points = temp;
        points = getConvexHull(points);

        double ans = 0;
        for (int i = 1; i < points.size(); i++) {
            ans += dist(points.get(i - 1), points.get(i));
        }

        System.out.println(ans);
        System.out.println("AntiClockwise starting from Bottom-most left point: ");

        for(int i = 0; i < points.size()-1; i++) {
            System.out.print(points.get(i).pos + " ");
        }

        if(points.size() == 1) {
            System.out.print("1");
        }

        System.out.println("\n");
    }
}
