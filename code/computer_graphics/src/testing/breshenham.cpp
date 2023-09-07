#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>

/* Function that returns -1,0,1 depending on whether x */
/* is <0, =0, >0 respectively */
#define sign(x) ((x>0)?1:((x<0)?-1:0))

/* Function to plot a point */
void setPixel(GLint x, GLint y) {
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}

/* Generalized Bresenham's Algorithm */
void bres_general(int x1, int y1, int x2, int y2)
{
  int dx, dy, x, y, d, s1, s2, swap=0, temp;

  dx = abs(x2 - x1);
  dy = abs(y2 - y1);
  s1 = sign(x2-x1);
  s2 = sign(y2-y1);

  /* Check if dx or dy has a greater range */
  /* if dy has a greater range than dx swap dx and dy */
  if(dy > dx){temp = dx; dx = dy; dy = temp; swap = 1;}

  /* Set the initial decision parameter and the initial point */
  d = 2 * dy - dx;
  x = x1;
  y = y1;

  int i;
  for(i = 1; i <= dx; i++)
  {
    setPixel(x,y);

    while(d >= 0)
    {
      if(swap) x = x + s1;
      else
      {
        y = y + s2;
        d = d - 2* dx;
      }
    }
    if(swap) y = y + s2;
    else x = x + s1;
    d = d + 2 * dy;
  }
  glFlush();
}

/* Function to draw a rhombus inscribed in a rectangle and roll */
/* number printed in it */
void draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  /* Draw rectangle */
  bres_general(20,40,620,40);
  bres_general(620,40,620,440);
  bres_general(620,440,20,440);
  bres_general(20,440,20,40);

  /* Draw rhombus */
  bres_general(320,440,20,240);
  bres_general(20,240,320,40);
  bres_general(320,40,620,240);
  bres_general(620,240,320,440);

  /* 1 */
  bres_general(250,150,250,250);
  /* 0 */
  bres_general(300,150,300,250);
  bres_general(300,250,400,250);
  bres_general(400,250,400,150);
  bres_general(400,150,300,150);

  glFlush();
}

void init() {
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640, 480);
  glutCreateWindow("Green Window");
  glClearColor(0.0,0.0,0.0,0);
  glColor3f(1.0,1.0,1.0);
  gluOrtho2D(0,640,0,480);

}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  init();
  glutDisplayFunc(draw);
  glutMainLoop();
  return 0;
}
