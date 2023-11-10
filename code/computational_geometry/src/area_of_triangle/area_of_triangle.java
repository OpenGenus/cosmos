import java.lang.Math;

public class AreaOfTriangle {

     public static void main(String []args){
        // input points {x,y}
        int[] pointA = {15,15};
        int[] pointB = {23,30};
        int[] pointC = {50,25};
        
        double result = Math.abs(((pointA[0]*(pointB[1] - pointC[1])) + (pointB[0]*(pointC[1] - pointA[1])) + (pointC[0]*(pointA[1] - pointB[1])))/2);
        
        System.out.println(result);
     }
}
