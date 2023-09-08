// cosmos

// This search uses Fibonacci series for reference of search. This series reduce the most of the part of array.

public class FibonacciSearch
{
    static int Fib[] =
    {
        0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765,
        10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578,
        5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296,
        433494437, 701408733, 1134903170, 1836311903
    };

    static int binsrch_geq(int n, int val)
    {
        int low, high, mid;
        int geq;
        low = 0;
        high = n - 1;
        geq = -1;
        while (low <= high)
        {
            mid = (low + high) >> 1;
            if (val < Fib[mid])
            {
                high = mid - 1;
                geq = mid;
            }
            else if (val > Fib[mid])
            {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return geq;
    }

    static int fibsrch(int arr[], int n, int val)
    {
        int k, idx, offs;
        int prevn = -1, prevk = -1;
        if (n != prevn)
        {
            k = (n > 1) ? binsrch_geq(Fib.length, n) : 1;
            prevk = k;
            prevn = n;
        }
        else
        {
            k = prevk;
        }
        for (offs = 0; k > 0;)
        {
            idx = offs + Fib[--k];
            if (idx >= n || val < arr[idx])
            {
                continue;
            }
            else if (val > arr[idx])
            {
                offs = idx;
                --k;
            }
            else
            {
                return idx;
            }
        }
        return -1;
    }

    public static void main(String[] args)
    {
        int data[] =
        {
            1, 4, 5, 7, 9, 11, 13, 16, 18, 20, 25, 27, 30, 32, 33, 36, 39, 41, 44, 47, 51, 53, 55
        };
        int i, x, n;
        x = 1;
        n = data.length;
        i = fibsrch(data, n, x);
        if (i >= 0)
        {
            System.out.println(x + " found at index " + (i+1));
        }
        else
        {
            System.out.println(x + " was not found");
        }
    }
}
