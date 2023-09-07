 #include<iostream>
 #include<vector>
 using namespace std;
 void setZeroes(vector<vector<int>>& matrix) 
        { vector<vector<int>>temp=matrix;

            for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix[0].size(); j++)

                {
                    if(matrix[i][j]==0)
                    {
                        for(int r=0;r<matrix.size();r++)
                            {
                                temp[r][j]=0;
                            }
                      for(int c=0;c<matrix[0].size();c++) 
                            {
                                temp[i][c]=0;
                            }
                    }
                }
            }
        
      matrix=temp;
}
int main()
{
    vector<vector<int>>matrix={{1,1,1},{1,0,1},{1,1,1}};
    cout<<"Matrix before operation "<<endl;
    for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix[0].size(); j++)

                {
                     cout<<matrix[i][j]<<" ";
                }  
                 cout<<endl;
            } 

    setZeroes(matrix);
    cout<<"Matrix after operation "<<endl;
    for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix[0].size(); j++)

                {
                     cout<<matrix[i][j]<<" ";
                }  
                 cout<<endl;
            } 
           

    return 0;

}
