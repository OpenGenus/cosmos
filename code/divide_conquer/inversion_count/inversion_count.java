//  divide conquer | inversion count | Java
//  Part of Cosmos by OpenGenus Foundation

import java.util.Scanner;
public class InversionCount {
    public static int merge(int a[], int p, int q,int r){

        int i = p ,j = q ,k = 0, count = 0;

        int temp[] = new int[r-p+1];

        while(i<q && j<=r){

            if(a[i] < a[j]){
                temp[k++] = a[i++];
            }
            else{
                temp[k++] = a[j++];
                count += (q - i);
            }
        }

        while(i<q){
            temp[k++] = a[i++];
        }

        while(j<=r){
            temp[k++] = a[j++];
        }

        k = 0;

        while(p<=r)
            a[p++] = temp[k++];

        return count;
    }
    public static int mergeSort(int a[],int i, int j){
        int count = 0;

        if(i>=j)
            return 0;

        int mid = (i+j)/2;

        count += mergeSort(a,i,mid);
        count += mergeSort(a,mid+1,j);
        count += merge(a,i,mid+1,j);

        return count;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter n >> ");
        int n = sc.nextInt();

        int a[] = new int[n];

        System.out.print("Enter elements of array >> ");
        for(int i=0;i<n;i++)
            a[i] = sc.nextInt();

        int count = mergeSort(a,0,a.length-1);

        System.out.println("Number of inversions : " + count);

    }
}
