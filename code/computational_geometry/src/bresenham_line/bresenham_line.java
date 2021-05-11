package applet;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

public class bresenhamLine extends java.applet.Applet implements MouseListener, MouseMotionListener {

 private static final long serialVersionUID = 1L;
 int width, height;
 int xa = 0;
 int ya = 0;
 int xb = 0;
 int yb = 0;
 int pixelsize = 2;


 /**
  * This method does initialization
  * @param no parameters used .
  */

 public void init() {
  this.width = getSize().width;
  this.height = getSize().height;
  this.addMouseListener(this);
  this.addMouseMotionListener(this);
 }

 /**
  * This method is used to Draw Line.
  * @param xa first coordinate
  * @param ya first Coordinate
  * @param xb Second Coordinate
  * @param yb Second Coordinate
  * @return will not return anything .
  */
 public void bresenhamLineDraw(int xa, int ya, int xb, int yb) {

  // if point xa, ya is on the right side of point xb, yb, change them
  if ((xa - xb) > 0) {
   bresenhamLineDraw(xb, yb, xa, ya);
   return;
  }

  // test inclination of line
  // function Math.abs(y) defines absolute value y
  if (Math.abs(yb - ya) > Math.abs(xb - xa)) {
   // line and y axis angle is less then 45 degrees
   // thats why go on the next procedure
   bresteepLine(ya, xa, yb, xb);
   return;
  }

  // line and x axis angle is less then 45 degrees, so x is guiding
  // auxiliary variables
  int x = xa, y = ya, sum = xb - xa, Dx = 2 * (xb - xa), Dy = Math.abs(2 * (yb - ya));
  int delta_Dy = ((yb - ya) > 0) ? 1 : -1;

  // draw line
  for (int i = 0; i <= xb - xa; i++) {
   setpix(x, y);
   x++;
   sum -= Dy;
   if (sum < 0) {
    y += delta_Dy;
    sum += Dx;
   }
  }
 }

 /**
  * This method is used to Draw Steeper Line.
  * @param xc first coordinate
  * @param yc first Coordinate
  * @param xd Second Coordinate
  * @param yd Second Coordinate
  * @return will not return anything .
  */

 public void bresteepLine(int xc, int yc, int xd, int yd) {

  /** if point xc, yc is on the right side
      of point xd yd,
      change them
  **/
  if ((xc - xd) > 0) {
   bresteepLine(xd, yd, xc, yc);
   return;
  }

  int x = xc, y = yc, sum = xd - xc, Dx = 2 * (xd - xc), Dy = Math.abs(2 * (yd - yc));
  int delta_Dy = ((yd - yc) > 0) ? 1 : -1;

  for (int i = 0; i <= xd - xc; i++) {
   setPix(y, x);
   x++;
   sum -= Dy;
   if (sum < 0) {
    y   += delta_Dy;
    sum += Dx;
   }
  }
 }

 /**
  * This method is used to Set pixel for Line.
  * @param x first coordinate
  * @param y first Coordinate
  * @return will not return anything .
  */
 public void setPix(int x, int y) {
  Graphics g = getGraphics();
  g.setColor(Color.green);
  g.fillRect(pixelsize * x, pixelsize * y, pixelsize, pixelsize);
 }

 /**
  * This method is used to paint the line on screen.
  * @param g of graphics library
  * @return will not return anything .
  */
 public void paint(Graphics g) {
  Dimension d = getSize();
  g.drawLine(0, 0, d.width, 0);
  g.drawLine(0, 0, 0, d.height);
  g.drawLine(d.width - 1, d.height - 1, d.width - 1, 0);
  g.drawLine(d.width - 1, d.height - 1, 0, d.height - 1);
  bresenhamLineDraw(xa, ya, xb, yb);
 }

 public void mousePressed(MouseEvent e) {
  xa = e.getX() / pixelsize;
  ya = e.getY() / pixelsize;
 }

 public void mouseDragged(MouseEvent e) {
  xb = e.getX() / pixelsize;
  yb = e.getY() / pixelsize;
  repaint();
 }

 public void mouseReleased(MouseEvent e) {
 }
 public void mouseClicked(MouseEvent e) {
 }
 public void mouseEntered(MouseEvent e) {
 }
 public void mouseExited(MouseEvent e) {
 }
 public void mouseMoved(MouseEvent e) {
 }

}

/**
 * Sample Input -     Enter Start X: 100
 *                    Enter Start Y: 100
 *                    Enter End X: 300
 *                    Enter End Y: 300
 * Sample output - https://ibb.co/NxYdXqd
 *
*/
