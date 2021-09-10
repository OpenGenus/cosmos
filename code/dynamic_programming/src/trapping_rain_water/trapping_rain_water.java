public class Main {

    public static void main(String args[]) {
        int[] heightArray =  {1, 2, 1, 3, 1, 2, 1, 4, 1, 0, 0, 2, 1, 4};
        System.out.println(trap_rain_water(heightArray));
    }

    public static int trap_rain_water(int[] height) {
        int result = 0;
    
        if(height==null) {
            return result;
		}
    
        int left[] = new int[height.length];
        int right[] = new int[height.length];
    
        //left[i] will contain height of tallest bar on the left side of i'th bar
        left[0] = height[0];
        for(int i=1; i<height.length; i++) {
            left[i] = Math.max(left[i-1], height[i]);
        }
    
        //right[i] will contain height of tallest bar on the right side of i'th bar
        right[height.length - 1] = height[height.length - 1];
        for(int i=height.length-2; i>=0; i--) {
            right[i] = Math.max(right[i+1], height[i]);
        }
    
        //amount of water collected on i'th bar will be min(left[i], right[i]) - height[i]
        for(int i=0; i<height.length; i++) {
            result+= Math.min(left[i], right[i]) - height[i];
        }
    
        return result;
    }

}
