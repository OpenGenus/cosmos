import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class LangtonAnt {
    private static final int STEPS = 11000;
    
    private Point position = new Point(0, 0);
    private Direction direction = Direction.LEFT;
    private ArrayList<Point> blackTiles = new ArrayList<>();

    private void step() {
	if (blackTiles.contains(position)) {
	    direction = direction.turnRight();
	} else {
	    direction = direction.turnLeft();
	}
	int index;
	if((index = blackTiles.indexOf(position)) != -1) {
	    blackTiles.remove(index);
	} else {
	    blackTiles.add((Point)position.clone());
	}
	switch (direction) {
	case LEFT:
	    position.translate(-1, 0);
	    break;
	case RIGHT:
	    position.translate(1, 0);
	    break;
	case UP:
	    position.translate(0, 1);
	    break;
	case DOWN:
	    position.translate(0, -1);
	    break;
	}
    }

    public static void main(String[] args) {
	LangtonAnt ant = new LangtonAnt();
	JFrame frame = new JFrame("Langtons Ant");
	GridPanel gridPanel = ant.new GridPanel();
	frame.getContentPane().add(gridPanel);
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	frame.pack();
	frame.setVisible(true);
	for (int steps = 0; steps < STEPS; steps++) {
	    ant.step();
	    try {
		Thread.sleep(10);
	    } catch (InterruptedException e) {
		e.printStackTrace();
	    }
	    frame.repaint();
	}
    }

    private enum Direction {
	LEFT, RIGHT, UP, DOWN;

	public Direction turnLeft() {
	    switch (this) {
	    case LEFT:
		return DOWN;
	    case RIGHT:
		return UP;
	    case UP:
		return LEFT;
	    case DOWN:
		return RIGHT;
	    default:
		// Should never happen
		return UP;
	    }
	}

	public Direction turnRight() {
	    switch (this) {
	    case LEFT:
		return UP;
	    case RIGHT:
		return DOWN;
	    case UP:
		return RIGHT;
	    case DOWN:
		return LEFT;
	    default:
		// Should never happen
		return UP;
	    }
	}
    }
    
    private class GridPanel extends JPanel {
	private static final int GRID_SIZE = 10;
	private static final int DISPLAY_TILES = 60;
	private static final int PIXEL_SIZE = GRID_SIZE*DISPLAY_TILES;
	private static final int CENTER = PIXEL_SIZE/2;
	
	public GridPanel() {
	    setPreferredSize(new Dimension(DISPLAY_TILES*GRID_SIZE, DISPLAY_TILES*GRID_SIZE));
	}
	
	@Override
	protected void paintComponent(Graphics g) {
	    Graphics2D g2d = (Graphics2D) g;
	    g2d.setColor(Color.BLACK);
	    for (Point tile : blackTiles) {
		g2d.fillRect(tile.x*GRID_SIZE+CENTER, tile.y*GRID_SIZE+CENTER, GRID_SIZE, GRID_SIZE);
	    }
	    g2d.setColor(Color.RED);
	    g2d.fillOval(position.x*GRID_SIZE+CENTER, position.y*GRID_SIZE+CENTER, GRID_SIZE, GRID_SIZE);
	}
    }
}