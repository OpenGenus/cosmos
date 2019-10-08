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

void setPixel(GLint x, GLint y){
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}

void bresenham_circle(int h, int k, int r){
  int x=0;
  int y=r;
  int p=(3-(2*r));
  do{
    setPixel((h+x),(k+y));
    setPixel((h+y),(k+x));
    setPixel((h+y),(k-x));
    setPixel((h+x),(k-y));
    setPixel((h-x),(k-y));
    setPixel((h-y),(k-x));
    setPixel((h-y),(k+x));
    setPixel((h-x),(k+y));
    x++;
    if(p<0){
      p+=((4*x)+6);
    }
    else{
      y--;
      p+=((4*(x-y))+10);
    }
  }while(x<=y);
}

void draw(void){
  glClear(GL_COLOR_BUFFER_BIT);
  bresenham_circle(0.0,0.0,150.0);
  glFlush();
}

void init(){
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Window");
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
