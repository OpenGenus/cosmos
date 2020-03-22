import java.lang.Math;

class LCS
{
    // Function to calculate length of longest common subsequence
    public static int LongestCommonSubsequence(int arr1[], int arr2[], int size1, int size2) 
    { 
        int lcs[][] = new int[size1+1][size2+1];
        for (int i=0; i<=size1; i++) 
        { 
                for (int j=0; j<=size2; j++) 
                { 
                    if (i == 0 || j == 0) 
                        lcs[i][j] = 0; 
		    // when the last character of both subsequences match, increase length of lcs by 1
		    // LCS( {10,15,20,25} ,{10,15,23,25} )=1+ LCS( {10,15,20} ,{10,15,23} )
                    else if (arr1[i-1] == arr2[j-1]) 
                        lcs[i][j] = lcs[i-1][j-1] + 1;
		    // when the last character is not same, take maximum obtained by adding one character to one of the subsequences 
		    // LCS({10,15,20} ,{10,15,23})= max(LCS( {10,15,20} ,{10,15} ) ,LCS( {10,15} ,{10,15,23}) )
                    else
                        lcs[i][j] = Math.max(lcs[i-1][j], lcs[i][j-1]); 
                } 
        } 
        return lcs[size1][size2]; 
    } 
   
    // Driver Function
    public static void main(String args[]) 
    { 
        int arr1[] = {10, 15, 20, 25, 30, 35, 40};
        int arr2[] = {10, 12, 23, 25, 28, 30, 32, 40};
        int size1 = arr1.length ;
        int size2 = arr2.length;
        LCS obj=new LCS();
        int l= obj.LongestCommonSubsequence(arr1, arr2, size1, size2);
        System.out.println("Length of Longest Common Subsequence is: "+l);
    }
}
/*The longest common subsequence comprises of elements 10, 25, 30, 40 in the above arrays
Output:
Length of Longest Common Subsequence is: 4
*/
