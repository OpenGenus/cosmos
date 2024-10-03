// Part of Cosmos by OpenGenus Foundation

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


public class BitonicSortAlgorithm extends SortAlgorithm
{
    private int[] a;
    // sorting direction:
    private final static boolean ASCENDING=true, DESCENDING=false;

public void sort(int[] a) throws Exception
{
    this.a = a;
    bitonicSort(0, a.length, ASCENDING);
}

private void bitonicSort(int lo, int n, boolean dir) throws Exception
{
    if (n>1)
    {
        int k=n/2;
        bitonicSort(lo, k, ASCENDING);
        bitonicSort(lo+k, k, DESCENDING);
        bitonicMerge(lo, n, dir);
    }
}

private void bitonicMerge(int lo, int n, boolean dir) throws Exception
{
    if (n>1)
    {
        int k=n/2;
        for (int i=lo; i<lo+k; i++)
            compare(i, i+k, dir);
        bitonicMerge(lo, k, dir);
        bitonicMerge(lo+k, k, dir);
    }
}

private void compare(int i, int j, boolean dir) throws Exception
{
    if (dir==(a[i]>a[j]))
    {
        int h=a[i];
        a[i]=a[j];
        a[j]=h;
        pause();
    }
}

} 
