import java.io.*;
import java.util.*;

class Brkbks {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();

        while (t-- > 0) {
            int strength = s.nextInt();
            int w1 = s.nextInt();
            int w2 = s.nextInt();
            int w3 = s.nextInt();
            ArrayList<Integer> arrLL = new ArrayList<>();
            arrLL.add(w1);
            arrLL.add(w2);
            arrLL.add(w3);
            int hits = 0;

            while (arrLL.size() != 0) {
                int sum = 0;

                // Calculating the sum of widths of bricks
                while (sum < strength) {
                    sum += arrLL.get(0);
                    if (sum <= strength) {
                        arrLL.remove(0);
                    }
                    if (arrLL.size() == 0) {
                        break;
                    }
                }

                // Hits required by Ada to break the given stack of bricks
                hits++;
            }
            System.out.println(hits);
        }
    }

}

/*
TEST CASE

INPUT
3
3 1 2 2
2 1 1 1
3 2 2 1

OUTPUT
2
2
2
*/
