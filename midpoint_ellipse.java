package graphicsgrid;

import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import java.util.*;
import java.math.*;
 
public class midpoint_ellipse extends Applet implements ActionListener, MouseListener, MouseMotionListener{
	Graphics g;
	int gap = 10;
	int width, height;
    int originX, originY;
    Button tleft, tright, tup, tdown, zoomin, zoomout, sleft, sright, sup, sdown, aclock, clock, draw_reset;
    int xc=0, yc=0,rx=0,ry=0, xs=1, ys=1, theta=0;
    Label l1 = new Label("semi major axis = ");
	
	Label l2 = new Label("semi minor axis = ");
	Label l3 = new Label("x = ");
	Label l4 = new Label("y = ");
	
    

	TextField t1 = new TextField(3);
	TextField t2 = new TextField(3);
	TextField t3 = new TextField(3);
	TextField t4 = new TextField(3);
	
 
	public void init() {
		this.setSize(new Dimension(800, 600));
		Color mycolor = new Color(255,255,255);
		setBackground(mycolor);
		
		 add(l1);
		 add(t1);
		 add(l2);
		 add(t2);
		 add(l3);
		 add(t3);
		 add(l4);
		 add(t4);
		 
		 l1.setForeground(Color.blue);
		 l2.setForeground(Color.magenta);
		 l3.setForeground(Color.green);
		 l4.setForeground(Color.red);
		 
		 draw_reset = new Button();
			draw_reset.setLabel("Draw/Reset");
			draw_reset.setBackground(Color.white);
			draw_reset.addActionListener(this); 
			add(draw_reset);
 
		tleft = new Button();
		tleft.setLabel("Move Left");
		tleft.setBackground(Color.white);
		tleft.addActionListener(this); 
		add(tleft);
 
		tright = new Button();
		tright.setLabel("Move Right");
		tright.setBackground(Color.white);
		tright.addActionListener(this); 
		add(tright);
 
		tup = new Button();
		tup.setLabel("Move Up");
		tup.setBackground(Color.white);
		tup.addActionListener(this); 
		add(tup);   Color axes_color=new Color(0,0,200);
 
		tdown = new Button();
		tdown.setLabel("Move Down");
		tdown.setBackground(Color.white);
		tdown.addActionListener(this); 
		add(tdown);
 
		zoomin = new Button();
		zoomin.setLabel("Zoom In");
		zoomin.setBackground(Color.white);
		zoomin.addActionListener(this); 
		add(zoomin);
 
		zoomout = new Button();
		zoomout.setLabel("Zoom Out");
		zoomout.setBackground(Color.white);
		zoomout.addActionListener(this); 
		add(zoomout);
 
		
 
		sleft = new Button();
		sleft.setLabel("Scale Left");
		sleft.setBackground(Color.white);
		sleft.addActionListener(this); 
		add(sleft);
 
		sright = new Button();
		sright.setLabel("Scale Right");
		sright.setBackground(Color.white);
		sright.addActionListener(this); 
		add(sright);
 
		sup = new Button();
		sup.setLabel("Scale Up");
		sup.setBackground(Color.white);
		sup.addActionListener(this); 
		add(sup);
 
		sdown = new Button();
		sdown.setLabel("Scale Down");
		sdown.setBackground(Color.white);
		sdown.addActionListener(this); 
		add(sdown);
 
		aclock = new Button();
		aclock.setLabel("Rotate Anticlockwise");
		aclock.setBackground(Color.white);
		aclock.addActionListener(this); 
		add(aclock);
 
		clock = new Button();
		clock.setLabel("Rotate Clockwise");
		clock.setBackground(Color.white);
		clock.addActionListener(this); 
		add(clock);
 
		addMouseListener(this);
		addMouseMotionListener(this);
 
	}
 
	public void paint(Graphics g) {
		setBackground(Color.BLACK); 
        Color mycolor = new Color(200,200,200);
        g.setColor(mycolor);
 
		originX = (getX() + getWidth())/2;
		originY = (getY() + getHeight())/2;
 
        for (int k = 0 ; k <= 4000; k+=gap) {
            g.drawLine(originX-getWidth()/2, originY+k, originX+getWidth()/2, originY+k);
            g.drawLine(originX-getWidth()/2, originY-k, originX+getWidth()/2, originY-k);
            g.drawLine(originX+k, originY-getHeight()/2, originX+k, originY+getHeight()/2);
            g.drawLine(originX-k, originY-getHeight()/2, originX-k, originY+getHeight()/2);
            //g.drawLine(k, y1, x2, y2);
        }
 
     
        g.setColor(Color.BLUE);
        g.drawLine(originX-getWidth()/2, originY, originX+getWidth()/2, originY);
        g.drawLine(originX, originY-getHeight()/2, originX, originY+getHeight()/2);
        
        draw_eclipse(g,xc,yc,rx,ry);
 
	}
 
	public void draw_eclipse(Graphics g, int a, int b, int rx, int ry) {
		g.setColor(Color.yellow);
		xc = a;
		yc = b;
         
        int x0 = 0, y0 = ry;
        double p = ry*ry -rx*rx*ry +0.25*rx*rx;
        
        double cos,sin;
        cos = Math.cos(theta/180.0*Math.PI);
        sin = Math.sin(theta/180.0*Math.PI);
        System.out.println(cos);
        while (ry*ry*x0<rx*rx*y0) {
        	fill((int)(((x0+xc)*xs)*cos + ((y0+yc)*ys)*sin), (int)(((y0+yc)*ys)*cos - ((x0+xc)*xs)*sin),g);
        	fill((int)(((-x0+xc)*xs)*cos + ((y0+yc)*ys)*sin), (int)(((y0+yc)*ys)*cos - ((-x0+xc)*xs)*sin),g);
        	fill((int)(((x0+xc)*xs)*cos + ((-y0+yc)*ys)*sin), (int)(((-y0+yc)*ys)*cos - ((x0+xc)*xs)*sin),g);
        	fill((int)(((-x0+xc)*xs)*cos + ((-y0+yc)*ys)*sin), (int)(((-y0+yc)*ys)*cos - ((-x0+xc)*xs)*sin),g);
 
        	x0++;
 
        	if(p<0) {
        		p+=(2*ry*ry*x0) + ry*ry;
        	}
        	else {
        		y0--;
        		p+=(2*ry*ry*x0) - (2*rx*rx*y0) + ry*ry;
        	}
        }
        p = ry*ry*(x0+.5)*(x0+.5) + (rx*(y0-1))*(rx*(y0-1)) - rx*ry*rx*ry;
 
        while (y0>=0) {
        	fill((int)(((x0+xc)*xs)*cos + ((y0+yc)*ys)*sin), (int)(((y0+yc)*ys)*cos - ((x0+xc)*xs)*sin),g);
        	fill((int)(((-x0+xc)*xs)*cos + ((y0+yc)*ys)*sin), (int)(((y0+yc)*ys)*cos - ((-x0+xc)*xs)*sin),g);
        	fill((int)(((x0+xc)*xs)*cos + ((-y0+yc)*ys)*sin), (int)(((-y0+yc)*ys)*cos - ((x0+xc)*xs)*sin),g);
        	fill((int)(((-x0+xc)*xs)*cos + ((-y0+yc)*ys)*sin), (int)(((-y0+yc)*ys)*cos - ((-x0+xc)*xs)*sin),g);
        	
        	y0--;
 
        	if(p>0) {
        		p+= -(2*rx*rx*y0) + rx*rx;
        	}
        	else {
        		x0++;
        		p+= 2*ry*ry*x0 -2*rx*rx*y0 + rx*rx;
        	}
        }
	}
 
	public int get_xgrid(int x) {
		return (int)Math.floor((x-originX)/gap);
	}
 
	public int get_ygrid(int y) {
		return (int)Math.floor((originY-y)/gap);
	}
 
	public void fill(int x, int y, Graphics g) {
		g.fillRect(originX + x*gap, originY - y*gap, gap, gap);		
	}
 
	@Override
	public void mouseClicked(MouseEvent arg0) {
		// TODO Auto-generated method stub
	}
	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
 
	}
	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
 
	}
	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
 
	}
	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
 
	}
	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		if (arg0.getSource()==tleft) 
			xc-=1;
		else if (arg0.getSource()==tright)
			xc+=1;
		else if (arg0.getSource()==tup)
			yc+=1;
		else if (arg0.getSource()==tdown)
			yc-=1;
		else if (arg0.getSource()==sleft) 
			xs+=1;
		else if (arg0.getSource()==sright)
			xs-=1;
		else if (arg0.getSource()==sup)
			ys+=1;
		else if (arg0.getSource()==sdown)
			ys-=1;
		else if (arg0.getSource()==aclock)
			theta-=1;
		else if (arg0.getSource()==clock)
			theta+=1;
		else if (arg0.getSource() == zoomin)
        {
			gap*=2;
			if (gap>200)
				gap/=2;
        } 
		else if (arg0.getSource() == zoomout)
        {
			gap/=2;
			if (gap<3)
				gap*=2;
        }
		else if (arg0.getSource()==draw_reset) {
			
			rx=Integer.parseInt(t1.getText());
	        ry=Integer.parseInt(t2.getText());
	        xc=Integer.parseInt(t3.getText());
	        yc=Integer.parseInt(t4.getText());
			
		}
 
		repaint();
	}
 
	@Override
	public void mouseDragged(MouseEvent arg0) {
		// TODO Auto-generated method stub
 
	}
 
	@Override
	public void mouseMoved(MouseEvent arg0) {
		// TODO Auto-generated method stub
 
	}
}

