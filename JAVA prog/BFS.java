import java.util.*;

class BFS {

    // A recursive function to find nth catalan number

    int catalan(int n) {
        int res = 0;

        // Base case
        if (n <= 1) {
            return 1;
        }
        for (int i = 0; i < n; i++) {
            res += catalan(i) * catalan(n - i - 1);
        }
        return res;
    }

    public static void main(String[] args) {
        BFS cn = new BFS();
        for (int i = 0; i < 13; i++) {
            System.out.print(cn.catalan(i) + " ");
        }
    }
}
