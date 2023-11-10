import java.util.Scanner;
public class TwoDimensionalArray{

    // Creating a user defined 2-D Array
    public static int[][] createarray(){
        Scanner s = new Scanner(System.in);
        
        // Taking number of rows and columns in input from user
        System.out.println("Enter number of rows");
        int rows = s.nextInt();
        System.out.println("Enter number of columns");
        int columns = s.nextInt();
        
        // Declaring an 2-D Array
        int[][] arr = new int[rows][columns];
        
        System.out.println("Enter element of desired matrix");
        for (int i = 0; i <arr.length; i++){
            for (int j = 0 ; j < arr[0].length; j++){
                arr[i][j] = s.nextInt();
            }
        }
        return arr;
    }

    // Printing a 2-D array
    public static void printarray (){
        int[][] arr = createarray();
        for (int i = 0; i <arr.length; i++){
            for (int j = 0 ; j < arr[0].length; j++){
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }
    public static void main(String args[]) {
        printarray();
    }
}

