#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<cmath>
#define _USE_MATH_DEFINES
#define sign(x) ((x>0)?1:((x<0)?-1:0))
float round_val(float v){
  return floor(v + 0.5);
}
void setpixel(GLint x, GLint y){
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}

void midpoint_ellipse(float xc, float yc, float rx, float ry)
{

   //Region 1
   float p=ry*ry-rx*rx*ry+rx*rx/4;
   float x=0,y=ry;
   while(2.0*ry*ry*x <= 2.0*rx*rx*y)
   {
	if(p < 0)
	{
		x++;
		p = p+2*ry*ry*x+ry*ry;
	}
	else
	{
		x++;y--;
		p = p+2*ry*ry*x-2*rx*rx*y-ry*ry;
	}
	setpixel(round_val(xc+x),round_val(yc+y));
	setpixel(round_val(xc+x),round_val(yc-y));
	setpixel(round_val(xc-x),round_val(yc+y));
	setpixel(round_val(xc-x),round_val(yc-y));
   }

  //Region 2
   p=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
   while(y > 0)
   {
	if(p <= 0)
	{
		x++;y--;
		p = p+2*ry*ry*x-2*rx*rx*y+rx*rx;
	}
	else
	{
		y--;
		p = p-2*rx*rx*y+rx*rx;
	}
	setpixel(round_val(xc+x),round_val(yc+y));
	setpixel(round_val(xc+x),round_val(yc-y));
	setpixel(round_val(xc-x),round_val(yc+y));
	setpixel(round_val(xc-x),round_val(yc-y));
   }
   //getch();
   //closegraph();
}

void draw(void){
  glClear(GL_COLOR_BUFFER_BIT);
  midpoint_ellipse(0.0,0.0,200.0,100.0);
  glFlush();
}


void init(){
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Green Window");
  glClearColor(1.0,1.0,1.0,0);
  glColor3f(0.0,0.0,0.0);
  gluOrtho2D(-250,250,-250,250);

}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  init();
  glutDisplayFunc(draw);
  glutMainLoop();
  return 0;
}
