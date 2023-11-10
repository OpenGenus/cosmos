/**
 * This Java program demonstrates the creation and manipulation of a 3D array.
 * We will create a 3D array, initialize its elements, and print them.
 */

 public class ThreeDArray {
    public static void main(String[] args) {
        // Define the dimensions of the 3D array
        int xSize = 3; // Size in the x-direction
        int ySize = 4; // Size in the y-direction
        int zSize = 2; // Size in the z-direction

        // Create a 3D array with the specified dimensions
        int[][][] threeDArray = new int[xSize][ySize][zSize];

        // Initialize the elements of the 3D array
        int value = 1;
        for (int x = 0; x < xSize; x++) {
            for (int y = 0; y < ySize; y++) {
                for (int z = 0; z < zSize; z++) {
                    threeDArray[x][y][z] = value;
                    value++;
                }
            }
        }

        // Print the 3D array
        for (int x = 0; x < xSize; x++) {
            for (int y = 0; y < ySize; y++) {
                for (int z = 0; z < zSize; z++) {
                    System.out.println("threeDArray[" + x + "][" + y + "][" + z + "] = " + threeDArray[x][y][z]);
                }
            }
        }
    }
}
