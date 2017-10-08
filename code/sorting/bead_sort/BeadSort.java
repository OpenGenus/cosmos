import java.util.Arrays;
// Part of Cosmos by OpenGenus Foundation
public class BeadSort {

    private enum BeadSortStatus {
        MARKED,
        NOT_MARKED,
    }

    public static void main(String[] args) {
        int[] arrayToSort = new int[]{4, 1, 6, 2, 40, 5, 3, 8, 7};
        System.out.println(Arrays.toString(beadSort(arrayToSort)));
    }

    public static int[] beadSort(int[] arr) {
        int max = 0;
        for (int anArr : arr) {
            if (anArr > max) {
                max = anArr;
            }
        }

        //Set up abacus
        BeadSortStatus[][] grid = new BeadSortStatus[arr.length][max];

        int[] levelcount = new int[max];
        for(int i = 0; i < max; i++) {
            levelcount[i] = 0;
            for(int j = 0; j < arr.length; j++) {
                grid[j][i] = BeadSortStatus.NOT_MARKED;
            }
        }

        //Drop the beads
        for (int anArr : arr) {
            int num = anArr;
            for (int j = 0; num > 0; j++, num--) {
                grid[levelcount[j]++][j] = BeadSortStatus.MARKED;
            }
        }

        //Count the beads
        int[] sorted=new int[arr.length];
        for(int i = 0; i < arr.length; i++) {
            int putt = 0;
            for(int j = 0; j < max && grid[arr.length - 1 - i][j] == BeadSortStatus.MARKED; j++) {
                putt++;
            }
            sorted[i] = putt;
        }

        return sorted;
    }

}
