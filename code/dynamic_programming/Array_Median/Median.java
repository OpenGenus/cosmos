import java.util.*;
// Part of Cosmos by OpenGenus Foundation
public class Median{
    public static void main(String[] args) {
        int length;
        int median;
        System.out.println("Enter Length of array");
        Scanner scanner = new Scanner(System.in);
        length = scanner.nextInt();
        int array[] = new int[length];
        for (int i=0 ; i<length ; i++){
            array[i] = scanner.nextInt();
        }
        Arrays.sort(array);
        if (array.length % 2 == 0){
            median =  (((array[array.length /2]) + (array[array.length/2 - 1])) / 2);
        }
        else {
            median = array[array.length / 2];
        }
        System.out.println(median);
    }
}
