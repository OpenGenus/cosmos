
/* Part of Cosmos by OpenGenus Foundation */
public class MatrixMult
{
  public static int[][] m;         // storage for the # of multiplications
  public static int[][] s;         // storage for the order

  public static void main(String[] args)
  {
    int[] p = getMatrixSizes(args);
    int n = p.length-1;            // of matrices in the product
    if (n < 2 || n > 15)
    {
      System.out.println("Wrong input");
      System.exit(0);
    }
 
    System.out.println("######Using a recursive non Dyn. Prog. method:");
    int mm = RMC(p, 1, n);
    System.out.println("Min number of multiplications: " + mm + "\n");

    System.out.println("######Using bottom-top Dyn. Prog. method:");
    MCO(p);
    System.out.println("Table of m[i][j]:");
       System.out.print("j\\i|");
       for (int i=1; i<=n; i++)
         System.out.printf("%5d ", i);
       System.out.print("\n---+");
       for (int i=1; i<=6*n-1; i++)
         System.out.print("-");
       System.out.println();
       for (int j=n; j>=1; j--)
       {
         System.out.print(" " + j + " |");
         for (int i=1; i<=j; i++)
           System.out.printf("%5d ", m[i][j]);
         System.out.println();
       }
    System.out.println("Min number of multiplications: " + m[1][n] + "\n");
    System.out.println("Table of s[i][j]:");
       System.out.print("j\\i|");
       for (int i=1; i<=n; i++)
         System.out.printf("%2d ", i);
       System.out.print("\n---+");
       for (int i=1; i<=3*n-1; i++)
         System.out.print("-");
       System.out.println();
       for (int j=n; j>=2; j--)
       {
         System.out.print(" " + j + " |");
         for (int i=1; i<=j-1; i++)
           System.out.printf("%2d ", s[i][j]);
         System.out.println();
       }
    System.out.print("Optimal multiplication order: ");
    MCM(s, 1, n);
    System.out.println("\n");

    System.out.println("######Using top-bottom Dyn. Prog. method:");
    mm = MMC(p);
    System.out.println("Min number of multiplications: " + mm);
  }

  // recursive algorithm that does not use the dynamic programming approach
  public static int RMC(int[] p, int i, int j)
  {
    if (i == j) return(0);
    int m_ij = Integer.MAX_VALUE;
    for (int k=i; k<j; k++)
    {
      int q = RMC(p, i, k) + RMC(p, k+1, j) + p[i-1]*p[k]*p[j];
      if (q < m_ij)
        m_ij = q;
    }
    return(m_ij);
  }

  // the bottom-top implementation of the dynamic programming method
  public static void MCO(int[] p)
  {
    int n = p.length-1;     // # of matrices in the product
    m = new int[n+1][n+1];  // create and automatically initialize array m
    s = new int[n+1][n+1];

    for (int l=2; l<=n; l++)
    {
      for (int i=1; i<=n-l+1; i++)
      {
        int j=i+l-1;  
        m[i][j] = Integer.MAX_VALUE;
        
        for (int k=i; k<=j-1; k++)
        {
          int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
          if (q < m[i][j])
          {
            m[i][j] = q;
            s[i][j] = k;
          }
        }
      }
    }
  }

  // algorithm for printing out optimal multiplication order
  public static void MCM(int[][] s, int i, int j)
  {
    if (i == j) System.out.print("A_" + i);
    else
    {
      System.out.print("(");
      MCM(s, i, s[i][j]);
      MCM(s, s[i][j]+1, j);
      System.out.print(")");
    }
  }

  // memorized version of MMC
  public static int MMC(int[] p)
  {
    int n = p.length-1;
    m = new int[n+1][n+1];
    for (int i=0; i<=n; i++)
    for (int j=i; j<=n; j++)
      m[i][j] = Integer.MAX_VALUE;
    return(LC(p, 1, n));
  }

  // auxilary method involved by MMC
  public static int LC(int[] p, int i, int j)
  {
    if (m[i][j] < Integer.MAX_VALUE) return(m[i][j]);

    if (i == j) m[i][j] = 0;
    else
    {
      for (int k=i; k<j; k++)
      { 
        int q = LC(p, i, k) + LC(p, k+1, j) + p[i-1]*p[k]*p[j];
        if (q < m[i][j])
          m[i][j] = q;
      }
    }
    return(m[i][j]);
  }

  // this method takes the numbers from the command line parameters and
  // puts them into an array of integers
  public static int[] getMatrixSizes(String[] ss)
  {
    int k = ss.length;
    if (k == 0)
    {
      System.out.println("No matrix dimensions entered");
      System.exit(0);
    }
    int[] p = new int[k];
    for (int i=0; i<k; i++)
    {
      try
      {
        p[i] = Integer.parseInt(ss[i]);
        if (p[i] <= 0)
        {
          System.out.println("Illegal input number " + k);
          System.exit(0);
        }
      }
      catch(NumberFormatException e)
      {
        System.out.println("Illegal input token " + ss[i]);
        System.exit(0);
      }
    }
    return(p);
  }
}
