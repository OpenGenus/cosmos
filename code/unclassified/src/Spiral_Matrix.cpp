//Problem: Given an m x n matrix, return all elements of the matrix in spiral order.
/*
Input:
n=3 m=3
Matriz:
2       3       5
19      23      7
17      13      11
Output:
vector => 2 3 5 7 11 13 17 19 23
*/
#include <iostream> 
#include<vector>
#include<cmath>
using namespace std;
vector<int> SpiralOrder(vector<vector<int>> Mat,int n,int m) {
	int val = 0,a[n][m];
	int k = 0, l = 0; 
	/*  k - starting row index
        n - ending row index
        l - starting column index
        m - ending column index
        i - iterator
    */
	vector<int> v;
	//Spiral Form Order: (right->down->left->up->right->..->end)
	while (k < n && l < m){
        for (int i = l; i < m; ++i){//Right
          v.push_back( Mat[k][i]);
        }
        k++;
        for (int i = k; i < n; ++i){//Down
            v.push_back(Mat[i][m-1]);
        }
        m--;
        if (k < n) 
        { 
            for (int i = m-1; i >= l; --i){//left
                v.push_back(Mat[n-1][i]);
            }
            n--; 
        }
        if (l < m) 
        { 
            for (int i = n-1; i >= k; --i){//up
               v.push_back( Mat[i][l]);
            }
            l++; 
        }
	}
	return v;
}
int main() 
{ 
	int m,n,i,j=0;
    cin>>n>>m;
    vector<vector<int>> Mat;
    for(i=0;i<n;i++){
		vector<int>a;
		for(j=0;j<m;j++){
			int v;
            cin>>v;
			a.push_back(v);
        }
		Mat.push_back(a);
    }
	vector<int> ans=SpiralOrder(Mat,n,m);
	for(auto x:ans){
		cout<<x<<" ";
	}cout<<endl;
	return 0; 
} 
//Time Complexity: O(M*N). To traverse the matrix O(m*n) time is required.
