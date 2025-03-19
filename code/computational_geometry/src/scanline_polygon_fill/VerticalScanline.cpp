#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;


struct point
{
    int x,y;

    point(int x_,int y_){x=x_;y=y_;}
    point(){};
    bool operator < (point other)
    {
        return x<other.x;
    }
};

struct node{
    int xm;
    float y;
    float m;

    node(int xm, float y, float m){
        this->xm = xm;
        this->y = y;
        this->m = m;
    }
    bool operator < (node other)
    {
        return y>other.y;
    }
    void show()
    {
        cout << xm << " " << y << " " << m << endl;
    }

};

int n;
point vertices[50];
vector <node> xyz, AET, GET[1000];

int main()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    freopen("myFile.txt", "w", stdout);

    n = 6;
    vertices[0].x = 100; vertices[0].y = 100;
    vertices[1].x = 150; vertices[1].y = 150;
    vertices[2].x = 130; vertices[2].y = 210;
    vertices[3].x = 100; vertices[3].y = 180;
    vertices[4].x = 80; vertices[4].y = 200;
    vertices[5].x = 60; vertices[5].y = 160;



  for(int i = 0; i < n; i++)
  {
      point A = vertices[i];
      point B = vertices[(i+1)%n];

      if(A.x > B.x)
      {
          swap(A, B);
      }
      float m = (B.y - A.y)*(1.0)/(B.x - A.x);

      GET[A.x].push_back(node(B.x, A.y, m));
      delay(100);

  }

  for (int i=0;i<1000;i++)sort(GET[i].begin(),GET[i].end());

    cout<<"GET:   \n";
    for(int j = 0; j < 1000; j++)
    {
        if((int)GET[j].size() > 0)
        {
            for(int i = 0; i < ((int)GET[j].size()); i++)
            {
                GET[j][i].show();
                delay(100);
            }
        }

        cout << endl;
    }
     int x=0;
    initwindow(700,700);
    vector<point> arr(6);
    int t = 0;
    cout<<"\n\nAET:   \n";
    while(x<700)    {


        vector<node> temp;
        for (auto element:AET){
            if (x < element.xm){
                node z = element;
                z.y += element.m;
                temp.push_back(z);
            }
        }

            for (auto y:GET[x])temp.push_back(y);
        sort(temp.begin(),temp.end());
        AET=temp;

        int parity=1;
        for (int i=0;i<((int)AET.size())-1;i++){
            if (parity){
                line(x,round(AET[i].y),x,AET[i+1].y);
                delay(20);
            }
            parity^=1;
        }

        for (int i=0;i<((int)AET.size());i++){
            AET[i].show();
            delay(25);
        }
        cout<<endl;
        x++;

        }



    getch();
    closegraph();
    return 0;

}
