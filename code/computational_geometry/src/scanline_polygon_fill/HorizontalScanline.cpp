#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;


struct point
{
    int x,y;
    point(int x_,int y_){x=x_;y=y_;}
    point(){};
    bool operator < (point other)
    {
        return y<other.y;
    }
};
struct node
{
    int ymax;
    float x;
    float m_;
    node(){}
    node (float x_,int ymax_,float m__){x=x_;ymax=ymax_;m_=m__;}
    bool operator < (node other)
    {
        return x<other.x;
    }
    void show(){
        cout<<"   "<<ymax<<"  "<<x<<"  "<<m_<<"      ";
    }
};
int n;
point vertices[50];
vector <node> xyz, AET, GET[1000];
int main(){

    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    freopen("myFile.txt", "w", stdout);

    int n = 4;
    vertices[0].x = 30; vertices[0].y = 40;
    vertices[1].x = 120; vertices[1].y = 70;
    vertices[2].x = 100; vertices[2].y = 10;
    vertices[3].x = 20; vertices[3].y = 30;
    for (int i=0;i<n;i++)
    {
        point A=vertices[i],B=vertices[(i+1)%n];
        if (A.y>B.y)swap(A,B);

        float m_=(B.x-A.x)*(1.0)/(B.y-A.y+0.000001);
        GET[A.y].push_back(node(A.x,B.y,m_));
        //cout<<A.y<<"  "<<B.y<<"  "<<A.x<<"  "<<m_<<endl;
        delay(100);
    }
    for (int i=0;i<1000;i++)sort(GET[i].begin(),GET[i].end());

    cout<<"GET:   \n";
    for(int j = 0; j<1000; j++){
        if((int)GET[j].size()>0){
            for (int i=0;i<((int)GET[j].size());i++){
                    GET[j][i].show();
                    delay(100);
            }
            cout<<endl;
        }
    }

    int y=0;
    initwindow(700,700);

    cout<<"\n\nAET:   \n";
    while(y<700)    {
        vector<node> temp;
        for (auto element:AET){
            if (y < element.ymax){
                node z = element;
                z.x += element.m_;
                temp.push_back(z);
            }
        }


        for (auto x:GET[y])temp.push_back(x);
        sort(temp.begin(),temp.end());
        AET=temp;
        int parity=1;
        for (int i=0;i<((int)AET.size())-1;i++){
            if (parity){
                line(round(AET[i].x),y,AET[i+1].x,y);
                delay(20);
            }
            parity^=1;
        }

        for (int i=0;i<((int)AET.size());i++){
            AET[i].show();
            delay(25);
        }
        cout<<endl;
        y++;

    }
    getch();
    closegraph();
    return 0;
}
