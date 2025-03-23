#include<bits/stdc++.h>
#include <GL/glut.h>
typedef long long ll;
typedef long double ld;
#define pb push_back
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define vi vector<double>
#define ii pair<double, double>
#define vii vector<ii>
#define si set<double>
#define mi map<double,double>
#define msi map<string, double>
#define vpp pair< pair<double,double> , pair<double,double> >
#define present(container, element) (container.find(element) != container.end()) //for set and map
#define cpresent(container, element) (find(all(container),element) != container.end()) //for vectors
#define REP(i, a, b) \
for(int i = a; i <= b; i++) // a to b, and variable i is local!
#define REPL(i, a, b) \
for(ll i = a; i <= b; i++) // a to b, and variable i is local!
#define tr(container, it) \
for(auto it = container.begin(); it != container.end(); it++)
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef float Matrix4x4 [4][4];
using namespace std;
// $ g++ gl.cpp -o gl -lGL -lGLU -lglut- To compile //
float x_1,y_1,z_1,x_2,y_2,z_2,xmax,xmin,zmin,zmax,ymax,ymin;
void Init()
{
    glClearColor(1.0,1.0,1.0,0); //clear color-black
    glColor3f(0.0,0.0,0.0); //fill color-white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0 , 500 , 0 , 500);
}
Matrix4x4 theMatrix;

Matrix4x4 perspective;

Matrix4x4 parallel;

// float ptsIni[8][3]={{80,80,-100},{180,80,-100},{180,180,-100},{80,180,-100},
//                     {60,60,0},{160,60,0},{160,160,0},{60,160,0}};
// float ptsIni[8][3]={{40,40,-50},{90,40,-50},{90,90,-50},{40,90,-50},
//                     {30,30,0},{80,30,0},{80,80,0},{30,80,0}};

float ptsIni[8][3]={{20,20,-25},{45,20,-25},{45,45,-25},{20,45,-25},
                    {15,15,0},{40,15,0},{40,40,0},{15,40,0}};

//Realign above line while execution
// Initial Co-ordinates ofthe Cube to be Transformed
float ptsFin[8][3];

float a,b,c,xo,yo,zo,n1,n2,n3;

int choice;

void matrixSetIdentity(Matrix4x4 m)    // Initialises the matrix as Unit Matrix
{
    int i, j;
    for (i=0; i<4; i++)
        for (j=0; j<4; j++)
            m[i][j] = (i == j);
}


void TransformPoints(Matrix4x4 theMatrix)
{
    int i,k;
    for(k=0 ; k<8 ; k++)
        for (i=0 ; i<3 ; i++)
            ptsFin[k][i] = theMatrix[i][0]*ptsIni[k][0] + theMatrix[i][1]*ptsIni[k][1]
                    + theMatrix[i][2]*ptsIni[k][2] + theMatrix[i][3];
// Realign above line while execution
}


void Axes(void)
{
    glColor3f (0.0, 0.0, 0.0);               // Set the color to BLACK
    glBegin(GL_LINES);                       // Plotting X-Axis
    glVertex2s(-1000 ,0);
    glVertex2s( 1000 ,0);
    glEnd();
    glBegin(GL_LINES);                       // Plotting Y-Axis
    glVertex2s(0 ,-1000);
    glVertex2s(0 , 1000);
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
        glVertex2f(x_1,y_1);
        glVertex2f(x_2,y_2);
        glVertex2f(xmin,ymin);
        glVertex2f(xmin,ymax);
        glVertex2f(xmin,ymax);
        glVertex2f(xmax,ymax);
        glVertex2f(xmax,ymax);
        glVertex2f(xmax,ymin);
        glVertex2f(xmax,ymin);
        glVertex2f(xmin,ymin);
    glEnd();
    glFlush();
}

void clippedLine(double u1,double u2)
{
    double delta_x = x_2 - x_1;
    double delta_y = y_2 - y_1;
    double cl1_x = x_1 + delta_x*u1;
    double cl2_x = x_1 + delta_x*u2;
    double cl1_y = y_1 + delta_y*u1;
    double cl2_y = y_1 + delta_y*u2;
    cout<<cl1_x<<" "<<cl1_y<<" "<<cl2_x<<" "<<cl2_y<<"\n";
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
        glVertex2f(xmin,ymin);
        glVertex2f(xmin,ymax);
        glVertex2f(xmin,ymax);
        glVertex2f(xmax,ymax);
        glVertex2f(xmax,ymax);
        glVertex2f(xmax,ymin);
        glVertex2f(xmax,ymin);
        glVertex2f(xmin,ymin);
        glVertex2f(x_1 + delta_x*u1,y_1 + delta_y*u1);
        glVertex2f(x_1 + delta_x*u2,y_1 + delta_y*u2);
    glEnd();
    glFlush();
}

void LiangBarsky()
{
    double delta_x = x_2 - x_1;
    double delta_y = y_2 - y_1;
    vector<double> p;
    p.push_back(delta_x);
    p.push_back(-delta_x);
    p.push_back(delta_y);
    p.push_back(-delta_y);

    vector<double>q;
    q.push_back(xmax - x_1);
    q.push_back(x_1 - xmin);
    q.push_back(ymax - y_1);
    q.push_back(y_1 - ymin);


    double u1 = 0,u2 = 1;
    for (int i = 0; i < 4; ++i)
    {
        /* code */
        if(p[i] < 0)
            u1 = max(u1,q[i]/p[i]);
        else if(p[i] >0)
            u2 = min(u2,q[i]/p[i]);
        else
            if(q[i] < 0)
            {
                cout<<"Line outside the clipping window\n";
                return;
            }
    }
    if(u1 > u2)
    {
        cout<<"Line outside the clipping window\n";
        return;
    }
    else
    {
        clippedLine(u1,u2);
    }
}

void CyrusBeck()
{
    cout<<"HI I am in Cyrus Beck\n";
    cout<<x_1<<" "<<y_1<<"\n";
    cout<<x_2<<" "<<y_2<<"\n";
    ii p1 = make_pair(x_1,y_1);
    ii p2 = make_pair(x_2,y_2);
    vii n;
    vii f;
    n.pb({1,0});
    n.pb({-1,0});
    n.pb({0,1});
    n.pb({0,-1});
    f.pb({xmin,ymin});
    f.pb({xmax,ymax});
    f.pb({xmin,ymin});
    f.pb({xmax,ymax});
    double tl = 0,tu = 1;
    ii D = make_pair(x_2 - x_1,y_2 - y_1);
    REP(i,0,3)
    {
        ii w;
        w = {x_1 - f[i].F,y_1 -f[i].S};
        double Ddotn = D.F * n[i].F + D.S * n[i].S;
        double Wdotn = w.F * n[i].F + w.S * n[i].S;
        if(Ddotn != 0.0)
        {
            double t = -Wdotn / Ddotn;
            if(Ddotn > 0.0)
            {
                if(t>1)
                {
                    cout<<"Line outside the clipping window\n";
                    return;
                }
                tl = max(t,tl);
            }
            else
            {
                if(t<0)
                {
                    cout<<"Line outside the clipping window\n";
                    return;
                }
                tu = min(t,tu);
            }
        }
        else
        {
            if(Wdotn < 0.0)
            {
                cout<<"Line outside the clipping window\n";
                return;
            }
        }
    }
    if(tl > tu)
    {
        cout<<"Line outside the clipping window\n";
    }
    else
    {
        cout<<tl<<" "<<tu<<"\n";
        clippedLine(tl,tu);
    }

}


void myKey(unsigned char key,int x,int y)
{
    if(key=='l')
    {
        glFlush();
        LiangBarsky();
    }
    else if(key=='c')
    {
        glFlush();
        CyrusBeck();
    }

}

int main(int argc, char **argv)
{
    /* code */
    cout<<"Enter the first coordinate of a line (x1,y1,z1) : \n";
    cin>>x_1>>y_1>>z_1;
    cout<<"Enter the second coordinate of the line (x2,y2,z2) :\n";
    cin>>x_2>>y_2>>z_2;
    cout<<"Enter the xmin and xmax of clipping window :\n";
    cin>>xmin>>xmax;
    cout<<"Enter the ymin and ymax of clipping window :\n";
    cin>>ymin>>ymax;
    cout<<"Enter the zmin and zmax of clipping window :\n";
    cin>>zmin>>zmax;
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500,500);
    glutInitWindowPosition (700,700);
    glutCreateWindow ("Line Clipping");
    Init();
    glutDisplayFunc(display);
    glutKeyboardFunc(myKey);
    // glutCreateWindow ("Liang Barsky's Line Clipping");
    // Init();
    // glutDisplayFunc(LiangBarsky);
    glutMainLoop();
    return 0;
}
