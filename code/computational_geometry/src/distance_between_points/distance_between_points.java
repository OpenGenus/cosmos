import java.lang.Math;

public class DistanceBetweenPoints {

     public static void main(String []args){
        // input points {x,y}
        int[] pointA = {0,1};
        int[] pointB = {0,4};
        
        double result = Math.sqrt(Math.pow((pointB[0] - pointA[0]), 2) + Math.pow((pointB[1] - pointA[1]), 2));
        
        System.out.println(result);
     }
}
