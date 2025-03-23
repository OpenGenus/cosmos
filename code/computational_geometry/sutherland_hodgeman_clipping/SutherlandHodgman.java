/* Part of Cosmos by OpenGenus Foundation */

import java.awt.*;
import java.awt.geom.Line2D;
import java.util.*;
import java.util.List;
import javax.swing.*;
 
public class SutherlandHodgman extends JFrame {
 
    SutherlandHodgmanPanel panel;
 
    public static void main(String[] args) {
        JFrame f = new SutherlandHodgman();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
 
    public SutherlandHodgman() {
        Container content = getContentPane();
        content.setLayout(new BorderLayout());
        panel = new SutherlandHodgmanPanel();
        content.add(panel, BorderLayout.CENTER);
        setTitle("SutherlandHodgman");
        pack();
        setLocationRelativeTo(null);
    }
}
 
class SutherlandHodgmanPanel extends JPanel {
    List<double[]> subject, clipper, result;
 
    public SutherlandHodgmanPanel() {
        setPreferredSize(new Dimension(600, 500));
 
        // these subject and clip points are assumed to be valid
        double[][] subjPoints = {{50, 150}, {200, 50}, {350, 150}, {350, 300},
        {250, 300}, {200, 250}, {150, 350}, {100, 250}, {100, 200}};
 
        double[][] clipPoints = {{100, 100}, {300, 100}, {300, 300}, {100, 300}};
 
        subject = new ArrayList<>(Arrays.asList(subjPoints));
        result  = new ArrayList<>(subject);
        clipper = new ArrayList<>(Arrays.asList(clipPoints));
 
        clipPolygon();
    }
 
    private void clipPolygon() {
        int len = clipper.size();
        for (int i = 0; i < len; i++) {
 
            int len2 = result.size();
            List<double[]> input = result;
            result = new ArrayList<>(len2);
 
            double[] A = clipper.get((i + len - 1) % len);
            double[] B = clipper.get(i);
 
            for (int j = 0; j < len2; j++) {
 
                double[] P = input.get((j + len2 - 1) % len2);
                double[] Q = input.get(j);
 
                if (isInside(A, B, Q)) {
                    if (!isInside(A, B, P))
                        result.add(intersection(A, B, P, Q));
                    result.add(Q);
                } else if (isInside(A, B, P))
                    result.add(intersection(A, B, P, Q));
            }
        }
    }
 
    private boolean isInside(double[] a, double[] b, double[] c) {
        return (a[0] - c[0]) * (b[1] - c[1]) > (a[1] - c[1]) * (b[0] - c[0]);
    }
 
    private double[] intersection(double[] a, double[] b, double[] p, double[] q) {
        double A1 = b[1] - a[1];
        double B1 = a[0] - b[0];
        double C1 = A1 * a[0] + B1 * a[1];
 
        double A2 = q[1] - p[1];
        double B2 = p[0] - q[0];
        double C2 = A2 * p[0] + B2 * p[1];
 
        double det = A1 * B2 - A2 * B1;
        double x = (B2 * C1 - B1 * C2) / det;
        double y = (A1 * C2 - A2 * C1) / det;
 
        return new double[]{x, y};
    }
 
    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D) g;
        g2.translate(80, 60);
        g2.setStroke(new BasicStroke(3));
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                RenderingHints.VALUE_ANTIALIAS_ON);
 
        drawPolygon(g2, subject, Color.blue);
        drawPolygon(g2, clipper, Color.red);
        drawPolygon(g2, result, Color.green);
    }
 
    private void drawPolygon(Graphics2D g2, List<double[]> points, Color color) {
        g2.setColor(color);
        int len = points.size();
        Line2D line = new Line2D.Double();
        for (int i = 0; i < len; i++) {
            double[] p1 = points.get(i);
            double[] p2 = points.get((i + 1) % len);
            line.setLine(p1[0], p1[1], p2[0], p2[1]);
            g2.draw(line);
        }
    }
}
