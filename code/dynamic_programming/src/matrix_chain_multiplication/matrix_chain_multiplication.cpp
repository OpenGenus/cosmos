#include <climits>
#include <cstdio>
// Part of Cosmos by OpenGenus Foundation
/* Dynamic Programming Solution
 * Time Complexity:O(n^3)
 * Space Complexity:O(n^2)
 */
// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int matrixChainOrder(const int p[], int n)
{
 
    /* For simplicity of the program, one extra row and one
       extra column are allocated in m[][].  0th row and 0th
       column of m[][] are not used */
    int m[n][n];
 
    int i, j, k, L, q;
 
    /* m[i,j] = Minimum number of scalar multiplications needed
       to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where
       dimension of A[i] is p[i-1] x p[i]  */
 
    // cost is zero when multiplying one matrix.
    for (i=1; i<n; i++)
        m[i][i] = 0;
 
    // L is chain length.
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++)
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
 
    return m[1][n-1];
}
/*Recursive Approach Solution
 *Time Complexity > O(2^n)
 */
int recursiveMatrixChainOrder(const int p[], int i, int j)
{
    if (i==j)
        return 0;
    int q=INT_MAX;
    int temp;
    /* q = Minimum number of scalar multiplications needed
       to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where
       dimension of A[i] is p[i-1] x p[i] */

    for(int k=i;k<j;k++)
    {   
        temp=recursiveMatrixChainOrder(p,i,k)+recursiveMatrixChainOrder(p,k+1,j)+p[i-1]*p[j]*p[k];
        if(temp<q)
        	q=temp;
    }
    return q;
}
int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Minimum number of multiplications by dp solution is %d \n",
                       matrixChainOrder(arr, size));
    printf("Minimum number of multiplications by recursive solution is %d \n",
                       recursiveMatrixChainOrder(arr, 1, size-1));
    getchar(); 
    return 0;
}
