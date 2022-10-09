#include<bits/stdc++.h>
using namespace std;
void setZeroes (vector < vector < int >>&matrix)
{
  vector < int >record;
  for (int i = 0; i < matrix.size (); i++)
    {
      for (int j = 0; j < matrix[0].size (); j++)
	{
	  if (matrix[i][j] == 0)
	    {
	      record.push_back (i);
	      record.push_back (j);
	    }
	}
    }
  if (record.size () > 0)
    {
      for (int i = 0; i < record.size () - 1; i += 2)
	{
	  for (int j = 0; j < matrix[0].size (); j++)
	    {
	      matrix[record[i]][j] = 0;
	    }
	  for (int k = 0; k < matrix.size (); k++)
	    {
	      matrix[k][record[i + 1]] = 0;
	    }
	}
    }
}

  int main ()
  {
    vector < vector < int >>matrix
    {
      {0, 1, 2, 0},
      {3, 4, 5, 2},
      {1, 3, 1, 5}
    };
    
    setZeroes (matrix);
    for (int i = 0; i < matrix.size (); i++)
      {
	for (int j = 0; j < matrix[i].size (); j++)
	  {
	    cout << matrix[i][j] << " ";
	  }
	cout << endl;
      }
    return 0;

  }
