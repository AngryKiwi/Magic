
/**
 *
 * @author tevin
 */
import java.awt.Point;
import java.util.ArrayList;

public class quickhull {

    public ArrayList<Point> quickHull(ArrayList<Point> points) {

        ArrayList<Point> convexHull = new ArrayList<Point>();

        // setting min points and max points
        int minPoint = -1, maxPoint = -1;

        int maxX = Integer.MAX_VALUE;
        int minX = Integer.MIN_VALUE;

        // 
        for (int i = 0; i < points.size(); i++) {
            if (points.get(i).x > minX) {
                minX = points.get(i).x;
                minPoint = i;
            }
            if (points.get(i).x < maxX) {
                maxX = points.get(i).x;
                maxPoint = i;
            }
        }

        Point A = points.get(minPoint);
        Point B = points.get(maxPoint);

        convexHull.add(A);
        convexHull.add(B);

        points.remove(A);
        points.remove(B);

        ArrayList<Point> leftSet = new ArrayList<Point>();
        ArrayList<Point> rightSet = new ArrayList<Point>();

        for (int i = 0; i < points.size(); i++) {
            Point p = points.get(i);
            if (pointLocation(A, B, p) == -1) {
                leftSet.add(p);
            } else if (pointLocation(A, B, p) == 1) {
                rightSet.add(p);
            }
        }

        hullSet(A, B, rightSet, convexHull);
        hullSet(B, A, leftSet, convexHull);

        return convexHull;
    }

    public int distance(Point A, Point B, Point C) {

        int num = (B.x - A.x) * (A.y - C.y) - (B.y - A.y) * (A.x - C.x);

        if (num < 0) {
            num = -num;
        }

        return num;

    }

    public void hullSet(Point A, Point B, ArrayList<Point> set,
            ArrayList<Point> hull) {

        int insertPosition = hull.indexOf(B);

        if (set.isEmpty()) {
            return;
        }

        if (set.size() == 1) {
            Point p = set.get(0);
            set.remove(p);
            hull.add(insertPosition, p);
            return;
        }

        int dist = Integer.MIN_VALUE;
        int furthestPoint = -1;

        for (int i = 0; i < set.size(); i++) {
            Point p = set.get(i);
            int distance = distance(A, B, p);
            if (distance > dist) {
                dist = distance;
                furthestPoint = i;
            }
        }

        Point P = set.get(furthestPoint);
        set.remove(furthestPoint);
        hull.add(insertPosition, P);
        // Determine who's to the left of AP
        ArrayList<Point> leftSetAP = new ArrayList<Point>();

        for (int i = 0; i < set.size(); i++) {
            Point M = set.get(i);
            if (pointLocation(A, P, M) == 1) {
                leftSetAP.add(M);
            }
        }

        // determine who's to the left of PB
        ArrayList<Point> leftSetPB = new ArrayList<Point>();

        for (int i = 0; i < set.size(); i++) {
            Point M = set.get(i);
            if (pointLocation(P, B, M) == 1) {
                leftSetPB.add(M);
            }
        }

        hullSet(A, P, leftSetAP, hull);
        hullSet(P, B, leftSetPB, hull);
    }

    public int pointLocation(Point A, Point B, Point P) {

        int cp1 = (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
        if (cp1 > 0) {
            return 1;
        } else if (cp1 == 0) {
           return 0;
        } else {
            return -1;
        }
    }

    public static void main(String args[]) {

        // creating an arraylist of points
        ArrayList<Point> points = new ArrayList<Point>();
        points.add(new Point(0, 3));
        points.add(new Point(1, 1));
        points.add(new Point(2, 2));
        points.add(new Point(4, 4));
        points.add(new Point(0, 0));
        points.add(new Point(1, 2));
        points.add(new Point(3, 1));
        points.add(new Point(3, 3));

        // creating an object qh
        quickhull qh = new quickhull();

        // quichull of points
        ArrayList<Point> p = qh.quickHull(points);

        for (int i = 0; i < p.size(); i++) {
            System.out.println("(" + p.get(i).x + ", " + p.get(i).y + ")");
        }
    }
}
