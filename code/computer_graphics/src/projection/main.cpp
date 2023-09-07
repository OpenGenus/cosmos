#include <GL/glut.h>
#include<bits/stdc++.h>

// $ g++ gl.cpp -o gl -lGL -lGLU -lglut- To compile //

using namespace std;

typedef float Matrix4x4 [4][4];

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
void Draw(float a[8][3])                 //Display the Figure
{
    int i;
    glColor3f (0.7, 0.4, 0.7);
    glBegin(GL_POLYGON);
    glVertex3f(a[0][0],a[0][1],a[0][2]);
    glVertex3f(a[1][0],a[1][1],a[1][2]);
    glVertex3f(a[2][0],a[2][1],a[2][2]);
    glVertex3f(a[3][0],a[3][1],a[3][2]);
    glEnd();
    i=0;
    glColor3f (0.8, 0.6, 0.5);
    glBegin(GL_POLYGON);
    glVertex3s(a[0+i][0],a[0+i][1],a[0+i][2]);
    glVertex3s(a[1+i][0],a[1+i][1],a[1+i][2]);
    glVertex3s(a[5+i][0],a[5+i][1],a[5+i][2]);
    glVertex3s(a[4+i][0],a[4+i][1],a[4+i][2]);
    glEnd();
    glColor3f (0.2, 0.4, 0.7);
    glBegin(GL_POLYGON);
    glVertex3f(a[0][0],a[0][1],a[0][2]);
    glVertex3f(a[3][0],a[3][1],a[3][2]);
    glVertex3f(a[7][0],a[7][1],a[7][2]);
    glVertex3f(a[4][0],a[4][1],a[4][2]);
    glEnd();
    i=1;
    glColor3f (0.5, 0.4, 0.3);
    glBegin(GL_POLYGON);
    glVertex3s(a[0+i][0],a[0+i][1],a[0+i][2]);
    glVertex3s(a[1+i][0],a[1+i][1],a[1+i][2]);
    glVertex3s(a[5+i][0],a[5+i][1],a[5+i][2]);
    glVertex3s(a[4+i][0],a[4+i][1],a[4+i][2]);
    glEnd();
    i=2;
    glColor3f (0.5, 0.6, 0.2);
    glBegin(GL_POLYGON);
    glVertex3s(a[0+i][0],a[0+i][1],a[0+i][2]);
    glVertex3s(a[1+i][0],a[1+i][1],a[1+i][2]);
    glVertex3s(a[5+i][0],a[5+i][1],a[5+i][2]);
    glVertex3s(a[4+i][0],a[4+i][1],a[4+i][2]);
    glEnd();
    i=4;
    glColor3f (0.7, 0.3, 0.4);
    glBegin(GL_POLYGON);
    glVertex3f(a[0+i][0],a[0+i][1],a[0+i][2]);
    glVertex3f(a[1+i][0],a[1+i][1],a[1+i][2]);
    glVertex3f(a[2+i][0],a[2+i][1],a[2+i][2]);
    glVertex3f(a[3+i][0],a[3+i][1],a[3+i][2]);
    glEnd();
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Axes();
    glColor3f (1.0, 0.0, 0.0);                // Set the color to RED
    Draw(ptsIni);
    // matrixSetIdentity(theMatrix);
    int d0 = n1*xo + n2*yo + n3*zo;
    int d1 = n1*a + n2*b + n3*c;
    int d = d0 - d1;
    switch(choice)
    {
        case 1:
            parallel[0][0] = d1 - a*n1;
            parallel[0][1] = -a*n2;
            parallel[0][2] = -a*n3;
            parallel[0][3] = a*d0;
            parallel[1][0] = -b*n1;
            parallel[1][1] = d1 - b*n2;
            parallel[1][2] = -b*n3;
            parallel[1][3] = b*d0;
            parallel[2][0] = -c*n1;
            parallel[2][1] = -c*n2;
            parallel[2][2] = d1 - c*n3;
            parallel[2][3] = c*d0;
            parallel[3][0] = parallel[3][1] = parallel[3][2] = 0;
            parallel[3][3] = d1;
            TransformPoints(parallel);
            break;
        case 2:
            perspective[0][0] = d + a*n1;
            perspective[0][1] = a*n2;
            perspective[0][2] = a*n3;
            perspective[0][3] = -a * d0;
            perspective[1][0] = b*n1;
            perspective[1][1] = d + b*n2;
            perspective[1][2] = b*n3;
            perspective[1][3] = -b*d0;
            perspective[2][0] = c*n1;
            perspective[2][1] = c*n2;
            perspective[2][2] = d + c*n3;
            perspective[2][3] = -c*d0;
            perspective[3][0] = n1;
            perspective[3][1] = n2;
            perspective[3][2] = n3;
            perspective[3][3] = -d1;
            TransformPoints(perspective);
            break;
    }
    for (int i = 0; i < 8; ++i)
    {
        /* code */
        for (int j = 0; j < 3; ++j)
        {
            /* code */
            cout<<ptsFin[i][j]<<" ";
        }
        cout<<"\n";
    }
    Draw(ptsFin);
    glFlush();
}


void init(void)
 {
    glClearColor (1.0, 1.0, 1.0, 1.0);
     // Set the Background color to WHITE
    glOrtho(-454.0, 454.0, -250.0, 250.0, -250.0, 250.0);
     // Set the no. of Co-ordinates along X & Y axes and their gappings
    glEnable(GL_DEPTH_TEST);
 // To Render the surfaces Properly according to their depths
 }


int main (int argc, char **argv)
{

    cout<<"1. Parallel projection\n2. Perspective projection\n";

    cout<<"Enter your choice :\n";

    cin>>choice;

    if(choice==1)
    {
        cout<<"Enter the i,j and k components of vector V :\n";
        cin>>a>>b>>c;
        cout<<"Enter the co-ordinate (R0) of plane :\n";
        cin>>xo>>yo>>zo;
        cout<<"Enter the i,j and k components of normal vector N:\n";
        cin>>n1>>n2>>n3;
    }
    else if(choice==2)
    {
        cout<<"Enter the x,y and z components of center of projection:\n";
        cin>>a>>b>>c;
        cout<<"Enter the co-ordinate (R0) of plane :\n";
        cin>>xo>>yo>>zo;
        cout<<"Enter the i,j and k components of normal vector N:\n";
        cin>>n1>>n2>>n3;
    }
    else
    {
        cout<<"Invalid choice\n";
        return 0;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    // glutInitWindowSize (1362, 750);
    glutInitWindowSize (2000, 1500);
    glutInitWindowPosition (0, 0);
    glutCreateWindow (" Projections ");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

