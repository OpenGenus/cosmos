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

void polynomial_ellipse(float h, float k, float rx, float ry){
  float x=rx;
  float y=0;
  float range=0;
  do{
    y=abs(ry*(sqrt(1-(pow((x-h),2)/pow(rx,2)))))+k;
    setPixel(round_val(h+x),round_val(k+y));
    setPixel(round_val(h+x),round_val(k-y));
    setPixel(round_val(h-x),round_val(k-y));
    setPixel(round_val(h-x),round_val(k+y));
    x-=0.01;
  }while(x>=range);
}

void draw(void){
  glClear(GL_COLOR_BUFFER_BIT);
  polynomial_ellipse(0.0,0.0,200.0,100.0);
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
