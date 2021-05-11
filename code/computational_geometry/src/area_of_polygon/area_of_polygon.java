public class AreaOfPolygon {

     public static void main(String []args){
        // input points {xPoints[i],yPoints[j]}
        int[] xPoints = {4, 4, 8, 8, -4, -4};
        int[] yPoints = {6, -4, -4, -8, -8, 6};
        
        double result = 0;
        int j = xPoints.length - 1;
        
        for (int i=0; i< xPoints.length; i++){
            result +=  (xPoints[j] + xPoints[i]) * (yPoints[j] - yPoints[i]); 
            j = i;
        }
        
        result = result/2;
        
        System.out.println(result);
     }
}
