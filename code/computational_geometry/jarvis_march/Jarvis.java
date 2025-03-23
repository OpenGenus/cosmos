import java.util.Scanner;
import java.util.Arrays;
 
/** Class point **/
class Point
{
    int x, y;
}
 
/** Class Jarvis **/
public class Jarvis
{    
    private boolean CCW(Point p, Point q, Point r)
    {
        int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
 
         if (val >= 0)
             return false;
         return true;
    }
    public void convexHull(Point[] points)
    {
        int n = points.length;
        /** if less than 3 points return **/        
        if (n < 3) 
            return;     
        int[] next = new int[n];
        Arrays.fill(next, -1);
 
        /** find the leftmost point **/
        int leftMost = 0;
        for (int i = 1; i < n; i++)
            if (points[i].x < points[leftMost].x)
                leftMost = i;
        int p = leftMost, q;
        /** iterate till p becomes leftMost **/
        do
        {
            /** wrapping **/
            q = (p + 1) % n;
            for (int i = 0; i < n; i++)
              if (CCW(points[p], points[i], points[q]))
                 q = i;
 
            next[p] = q;  
            p = q; 
        } while (p != leftMost);
 
        /** Display result **/
        display(points, next);
    }
    public void display(Point[] points, int[] next)
    {
        System.out.println("\nConvex Hull points : ");
        for (int i = 0; i < next.length; i++)
            if (next[i] != -1)
               System.out.println("("+ points[i].x +", "+ points[i].y +")");
    }
   
    public static void main (String[] args) 
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Jarvis Algorithm Test\n");
        /** Make an object of Jarvis class **/
        Jarvis j = new Jarvis();        
 
        System.out.println("Number of points n :");
        int n = 8;
        Point[] points = new Point[n];
        System.out.println("choosing randomly  "+ n +" x, y cordinates");
        
        points[0] = new Point();  
        points[0].x=0;
        points[0].y=3;
        
        points[1] = new Point(); 
        points[1].x=4;
        points[1].y=2;
        
        points[2] = new Point(); 
        points[2].x=3;
        points[2].y=5;
         
        points[3] = new Point(); 
        points[3].x=5;
        points[3].y=3;
        
        points[4] = new Point(); 
        points[4].x=3;
        points[4].y=0;
       
        points[5] = new Point(); 
        points[5].x=1;
        points[5].y=1;
        
        points[6] = new Point(); 
        points[6].x=1;
        points[6].y=2;
        
        points[7] = new Point(); 
        points[7].x=2;
        points[7].y=2;
        
       
        
        
        j.convexHull(points);        
    }
}
Jarvis Algorithm Test
