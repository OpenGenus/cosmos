
#include <iostream>
using namespace std;


int main()
{
int h, w;
    cin >> h >> w;
    int a[h][w];
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
            cin >> a[i][j];
    }
    int sum = 0;
    for(int i = 0; i < h; i++)
    {
        if(i == 0)
        {
            for(int j = 0; j < w; j++)
              {
                int temp = 0;
                if(j == 0)
                  {
                      temp = (a[i][j] - 1) * 4 + 6;
                      sum = sum + temp;
                  }

             else
                 {
                     temp = (a[i][j] - 1) * 4 + 6;
                     int d = min(a[i][j-1], a[i][j]);
                     temp=temp - (d * 2);
                     sum = sum + temp;
                 }
              }
      }
        else
        {
             for(int j=0;j<w;j++)
              {
                int temp=0;
                if(j==0)
                  {
                      temp = (a[i][j] - 1) * 4 + 6;
                      int d = min(a[i][j], a[i-1][j]);
                      temp = temp - (d * 2);
                      sum = sum + temp;
                  }

             else
                {
                     temp = (a[i][j] - 1) * 4 + 6;
                     int d = min(a[i][j-1], a[i][j]);
                     temp = temp - (d * 2);
                     d = min(a[i][j], a[i-1][j]);
                     temp = temp - (d * 2);
                     sum = sum + temp;
               }
            }
        }

    }
      cout << sum;

    return 0;
}
