import java.util.Scanner;

/**
 * @author Samy Metadjer
 * Diamond Square algorithm is a method allowing to generate
 * heightmaps for computer graphics by using a 2D Grid.
 */
public class DiamondSquare{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("The size of your matrix needs to be 2^n+1. Enter the number n please : ");
        double size = Math.pow(2, sc.nextInt())+1;
        double[][] matrix = new double[(int)size][(int)size];
        diamondSquare(matrix);

        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix.length; j++){
                System.out.println("matrix[" + i + "][" + j + "] = " + matrix[i][j]);
            }
        }
    }

    /**
     * Generates random value for each cell of the given array.
     * @param matrix the array to be manipulated
     */
    public static void diamondSquare(double[][] matrix){
        int height = matrix.length;
        int boundary = 40;
        int i = height - 1;
        int id;
        int shift;

        /*
        ** Set a random value to each corner of the matrix (Seeds values).
        ** It's the first square step of the algorithm
         */
        matrix[0][0] = (Math.random() * (boundary - (-boundary) )) + (-boundary);
        matrix[0][height-1] = (Math.random() * (boundary - (-boundary) )) + (-boundary);
        matrix[height-1][0] = (Math.random() * (boundary - (-boundary) )) + (-boundary);
        matrix[height-1][height-1] = (Math.random() * (boundary - (-boundary) )) + (-boundary);

        while (i > 1) {
            id = i / 2;
            for (int xIndex = id; xIndex < height; xIndex += i) { // Beginning of the Diamond Step
                for (int yIndex = id; yIndex < height; yIndex += i) {
                    double moyenne = (matrix[xIndex - id][yIndex - id]
                            + matrix[xIndex - id][yIndex + id]
                            + matrix[xIndex + id][yIndex + id]
                            + matrix[xIndex + id][yIndex - id]) / 4;
                    matrix[xIndex][yIndex] = moyenne + (Math.random() * (height - (-height) )) + (-height);
                }
            }
            for (int xIndex = 0; xIndex < height; xIndex += id) { // Beginning of the Square Step
                if (xIndex % i == 0) {
                    shift = id;
                } else {
                    shift = 0;
                }
                for (int yIndex = shift; yIndex < height; yIndex += i) {
                    int somme = 0;
                    int n = 0;
                    if (xIndex >= id) {
                        somme += matrix[xIndex - id][yIndex];
                        n += 1;
                    }
                    if (xIndex + id < height) {
                        somme += matrix[xIndex + id][yIndex];
                        n += 1;
                    }
                    if (yIndex >= id) {
                        somme += matrix[xIndex][yIndex - id];
                        n += 1;
                    }
                    if (yIndex + id < height) {
                        somme += matrix[xIndex][yIndex + id];
                        n += 1;
                    }
                   matrix[xIndex][yIndex] = somme / n + (Math.random() * (height - (-height) )) + (-height);
                }
            }
            i = id;
        }
    }
}
