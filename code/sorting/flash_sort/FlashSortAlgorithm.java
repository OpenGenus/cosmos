//  Part of Cosmos by OpenGenus Foundation

import java.util.Arrays;

public abstract class SortAlgorithm {
   private SortItem parent;					// The sort item.
   protected boolean stopRequested = false;	// When true stop sorting.
   protected int[] h;						// Generalized water marks.
   protected int waterMarks = 2;			// Number of water marks.

   public SortAlgorithm() {
      this.h = new int[waterMarks];
   }

  /**
   * Set the parent.
   */
   public void setParent(SortItem p) {
     this.parent = p;
   }

  /**
   * Pause for a while.
   */
   protected void pause() throws Exception {
      if (stopRequested)
	     throw new Exception("Sort Algorithm");

	  this.parent.pause();
   }

  /**
   * Pause for a while and mark item 1.
   */
   protected @Deprecated void pause(int h1) throws Exception {
	  if (stopRequested)
	     throw new Exception("Sort Algorithm");

	  this.parent.pause(h1);
   }

  /**
   * Pause for a while and mark item 1 & 2.
   */
   protected @Deprecated void pause(int h1, int h2) throws Exception {
	  if (stopRequested)
	     throw new Exception("Sort Algorithm");

	  this.parent.pause(h1, h2);
   }

  /**
   * Pause for a while and mark items. - Andrew Kitchen  95/11/22
   */
   protected @Deprecated void pause(int h[]) throws Exception {
	  if (stopRequested)
	     throw new Exception("Sort Algorithm");

      this.parent.pause(h);
   }

  /**
   * Stop sorting.
   */
   public void stop() {
	  this.stopRequested = true;
   }

  /**
   * Initialize
   */
   public void init() {
	  this.stopRequested = false;
   }

  /**
   * This method will be called to
   * sort an array of integers.
   */
   abstract void sort(int a[]) throws Exception;

}


public class FlashSortAlgorithm extends SortAlgorithm {

void sort(int[] a) throws Exception {
   partialFlashSort(a);
   insertionSort(a);
}

    private void insertionSort(int [] a) throws Exception {
int i, j, hold;

for (i=a.length-3; i>=0; i--) {
if (a[i+1] < a[i]) {
hold = a[i];
j=i;

while (a[j+1] < hold) {
a[j] = a[j+1];
j++;
pause();
}

a[j] = hold;
pause();
}
}
}

    /**
     * Partial flash sort
     */

    private void partialFlashSort(int [] a) throws Exception {
        int n = a.length;
        int m = n / 20;
        int [] l = new int[m];

        int i = 0, j = 0, k = 0;
        int anmin = a[0];
        int nmax = 0;

        for (i = 1; i < n; i++) {
            if (a[i] < anmin)
                anmin = a[i];
            if (a[i] > a[nmax])
                nmax = i;
            pause(i,n);
        }

        if (anmin == a[nmax])
            return;

        double c1 = ((double) m - 1) / (a[nmax] - anmin);

        for (i = 0; i < n; i++) {
            k = (int) (c1 * (a[i] - anmin));
            l[k]++;
            pause(i,n);
        }

        for (k = 1; k < m; k++){
            l[k] += l[k - 1];
            pause(k,m);
        }

        int hold = a[nmax];
        a[nmax] = a[0];
        a[0] = hold;

        int nmove = 0;
        int flash;
        j = 0;
        k = m - 1;

        while (nmove < n - 1) {
            while (j > (l[k] - 1)) {
                j++;
                k = (int) (c1 * (a[j] - anmin));
                pause(nmove,n-1);
            }

            flash = a[j];

            while (!(j == l[k])) {
                k = (int) (c1 * (flash - anmin));

                hold = a[l[k] - 1];
                a[l[k] - 1] = flash;
                flash = hold;

                l[k]--;
                nmove++;
                pause(j,k);
            }
        }
    }
}
