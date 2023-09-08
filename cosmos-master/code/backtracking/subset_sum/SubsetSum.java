import java.util.ArrayList;
import java.util.Scanner;

public class SubsetSum {
    public static ArrayList<ArrayList<Integer>> SubsetGenerate(int arr[], int requiredSum){

        ArrayList<ArrayList<Integer>> RequiredSubsets = new ArrayList<ArrayList<Integer>>();
        int temp,size = arr.length;

        for(int i=0;i<(1<<size);i++){

            temp = 0;

            for(int j=0;j<size;j++)
                if((i & (1<<j)) > 0)
                    temp += arr[j];

            if(requiredSum == temp){
                ArrayList<Integer> subset = new ArrayList<>();

                for(int j=0;j<size;j++)
                    if((i & (1<<j)) > 0)
                        subset.add(arr[j]);

                RequiredSubsets.add(subset);
            }
        }

        return RequiredSubsets;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter n >> ");
        int n = sc.nextInt();
        int arr[] = new int[n];

        System.out.print("Enter n array elements >> ");
        for(int i=0;i<n;i++)
            arr[i] = sc.nextInt();

        System.out.print("Enter required Subset Sum >> ");
        int requiredSum = sc.nextInt();

        ArrayList<ArrayList<Integer>> RequiredSubsets = SubsetGenerate(arr,requiredSum);

        int temp;
        System.out.println("Subsets with sum = " + requiredSum + " : ");

        for(int i=0;i<RequiredSubsets.size();i++){
            temp = RequiredSubsets.get(i).size();
            for(int j=0;j<temp;j++){
                System.out.print(RequiredSubsets.get(i).get(j) + " ");
            }
            System.out.println();
        }

    }
}
