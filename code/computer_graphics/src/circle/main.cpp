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

void parametric_circle(float h, float k, float r){
  float x=0;
  float y=r;
  float angle=0;
  float range=M_PI_4;
  do{
    setPixel(round_val(h+x),round_val(k+y));
    setPixel(round_val(h+y),round_val(k+x));
    setPixel(round_val(h+y),round_val(k-x));
    setPixel(round_val(h+x),round_val(k-y));
    setPixel(round_val(h-x),round_val(k-y));
    setPixel(round_val(h-y),round_val(k-x));
    setPixel(round_val(h-y),round_val(k+x));
    setPixel(round_val(h-x),round_val(k+y));
    angle+=0.001;
    x=(r*cos(angle));
    y=(r*sin(angle));
  }while(angle<=range);
}

void draw(void){
  glClear(GL_COLOR_BUFFER_BIT);
  parametric_circle(0.0,0.0,150.0);
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
