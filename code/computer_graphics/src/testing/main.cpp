#include <iostream>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

#define endl '\n'
using namespace std;

double X1, Y1, X2, Y2;

float _round(float v)
{
	return floor(v + 0.5);
}
void LineDDA(void)
{
	double dx=(X2-X1);
	double dy=(Y2-Y1);
	double steps;
	float xInc,yInc,x=X1,y=Y1;
	/* Find out whether to increment x or y */
	steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
	xInc=dx/(float)steps;
	yInc=dy/(float)steps;

	/* Clears buffers to preset values */
	glClear(GL_COLOR_BUFFER_BIT);

	/* Plot the points */
	glBegin(GL_POINTS);
	/* Plot the first point */
	glVertex2d(x,y);

	for(int k=0;k<steps;k++)
	{
		x+=xInc;
		y+=yInc;
		glVertex2d(_round(x), _round(y));
	}
	glEnd();
	glFlush();
}
void Init()
{
	glClearColor(0.0,0.0,0.0,0); //clear color-white
	glColor3f(1.0,1.0,1.0); //fill color-black
	gluOrtho2D(0 , 640 , 0 , 480);
}
int main(int argc, char **argv)
{
	cout << "Enter two end points of the line to be drawn" << endl;
	cout << "Enter Point1( X1 , Y1)" << endl;
	cin >> X1 >> Y1;
	cout << "Enter Point2( X2 , Y2)" << endl;
	cin >> X2 >> Y2;

	glutInit(&argc,argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(640,0);
	glutInitWindowSize(640,480);
	glutCreateWindow("DDA_Line");

	Init();
	//function
	glutDisplayFunc(LineDDA);

	glutMainLoop();
	return 0;
}
