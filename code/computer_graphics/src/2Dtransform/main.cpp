#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

typedef double Matrix3x3 [3][3];
Matrix3x3 matComposite;
int choice;

void setIdentity(Matrix3x3 matIdentity)
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			matIdentity[i][j] = (i==j);
}
void matrixPreMultiply(Matrix3x3 m1,Matrix3x3 m2)
{
	Matrix3x3 temp;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			temp[i][j] = m1[i][0]*m2[0][j] + m1[i][1] * m2[1][j] + m1[i][2] * m2[2][j];

	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			m2[i][j] = temp[i][j];
}
void translate2D(double tx,double ty)
{
	Matrix3x3 matTranslation;
	setIdentity(matTranslation);
	matTranslation[0][2] = tx;
	matTranslation[1][2] = ty;
	matrixPreMultiply(matTranslation,matComposite);
}
void rotate2D(double x,double y,double theta)
{
	Matrix3x3 matRot;
	matRot[0][0] = cos(theta);
	matRot[0][1] = -sin(theta);
	matRot[0][2] = x*(1-cos(theta)) + y*sin(theta);
	matRot[1][0] = sin(theta);
	matRot[1][1] = cos(theta);
	matRot[1][2] = y*(1-cos(theta)) - x*sin(theta);
	matrixPreMultiply(matRot,matComposite);
}
void scale2D(double sx,double sy,double x,double y)
{
	Matrix3x3 matScale;
	setIdentity(matScale);
	matScale[0][0] = sx;
	matScale[0][2] = (1-sx)*x;
	matScale[1][1] = sy;
	matScale[1][2] = (1-sy)*y;
	matrixPreMultiply(matScale,matComposite);
}
void shear2D(double shx,double shy)
{
	Matrix3x3 matShear;
	setIdentity(matShear);
	matShear[0][1] = shx;
	matShear[0][2] =  0;
	matShear[1][0] = shy;
	matShear[1][2] =  0;
	matrixPreMultiply(matShear,matComposite);
}

void reflectx2D()
{
	Matrix3x3 matShear;
	setIdentity(matShear);
	matShear[0][1] = 0;
	matShear[0][2] =  0;
	matShear[1][0] = 0;
	matShear[1][1] = -1;
	matShear[1][2] =  0;
	matrixPreMultiply(matShear,matComposite);
}

void transformVertex(int nVertices,vector < pair<double,double> > & vertex)
{
	double temp;
	for (int i = 0; i < nVertices; ++i)
	{
		temp = matComposite[0][0]*vertex[i].first + matComposite[0][1]*vertex[i].second + matComposite[0][2];
		vertex[i].second = matComposite[1][0] * vertex[i].first + matComposite[1][1]*vertex[i].second + matComposite[1][2];
		vertex[i].first = temp;
	}
}
void triangle(vector< pair<double,double> > & vertex)
{
	for(int k=0;k<3;k++)
		glVertex2f(vertex[k].first,vertex[k].second);
}

void display()
{
	int n = 3;
	//cout<<"Enter the three vertices of the triangle" << endl;
	vector< pair<double,double> > vertex(3);
	/*for (int i = 0; i < n; ++i)
		cin>>vertex[i].first>>vertex[i].second;*/
	vertex[0]={10,10};
	vertex[1]={30,10};
	vertex[2]={20,30};

	pair<int,int>centroid;
	double xSum=0,ySum=0;
	for(int i=0;i<n;i++)
	{
		xSum += vertex[i].first;
		ySum += vertex[i].second;
	}
	centroid.first = xSum/n;
	centroid.second = ySum/n;
	cout << "Enter Choice"<<endl;
	cout << "1 for translate"<<endl;
	cout << "2 for shear"<<endl;
	cout << "3 for scale"<<endl;
	cout << "4 for rotate"<<endl;
	cout << "5 for line refection"<<endl;
	cin >> choice;

	glBegin(GL_TRIANGLES);

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	triangle(vertex);
	setIdentity(matComposite);

	if(choice==1)
	{
		double tx = 0,ty = 100;

		translate2D(tx,ty);
		transformVertex(n,vertex);
	}

	else if(choice==2)
	{
		double shx = 1,shy=0;

		shear2D(shx,shy);
		transformVertex(n,vertex);
	}

	else if(choice==3)
	{
		double sx = 0.5,sy=0.5;

		scale2D(sx,sy,0,0);
		transformVertex(n,vertex);
	}

	else if(choice==4)
	{
		double theta=1.57;

		rotate2D(50.0,50.0,theta);
		transformVertex(n,vertex);
	}

	else if(choice==5)
	{
		double m,c;
		cout << "Enter m and c"<< endl;
		cin >> m >> c;

		double tx=0,ty=c;
		double theta=atan(m);

		translate2D(tx,-ty);
		rotate2D(0,0,-theta);
		reflectx2D();
		rotate2D(0,0,theta);
		translate2D(tx,ty);
		transformVertex(n,vertex);
	}

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	triangle(vertex);
	glEnd();
	glFlush();

}
void Init()
{
    glClearColor(1.0,1.0,1.0,0); //clear color-black
    glColor3f(0.0,0.0,0.0); //fill color-white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0 , 500 , 0 , 500);
}
void winReshape(GLint newwidth,GLint newheight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,225,0,225);
	glClear(GL_COLOR_BUFFER_BIT);
}
int main(int argc,char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500,500);
    glutInitWindowPosition (700, 700);
    glutCreateWindow ("2D transformations");
    Init();
    glutDisplayFunc(display);
    glutReshapeFunc(winReshape);
    glutMainLoop();
    return 0;
}
