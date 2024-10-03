import java.util.*;
import java.lang.*;
import java.io.*;

class Test
{
    static int tree[]; 
    static int lazy[]; 
     
    public static void main (String[] args) throws java.io.IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringWriter sw = new StringWriter();
        BufferedWriter bb = new BufferedWriter(sw);
          
        int n, q;
          
        String in_[] = br.readLine().split(" ");
          
        n = Integer.parseInt(in_[0]);
        q = Integer.parseInt(in_[1]);
          
        int x = (int)Math.ceil((Math.log10(n))/Math.log10(2));
        int size = (int)(2*Math.pow(2, x))-1;
          
        tree = new int[size];
        lazy = new int[size];
          
        while(q>0)
        {
            q--;
            in_ = br.readLine().split(" ");
            int start, end;
			
            if(in_[0].equals("0"))
            {
                start = Integer.parseInt(in_[1]);
                end = Integer.parseInt(in_[2]);
				updateTreeNodeRange(0, 0, n-1,start, end);
		    }
		    else
		    {
				start = Integer.parseInt(in_[1]);
				end = Integer.parseInt(in_[2]);
				bb.write(String.valueOf(queryRange(0, 0, n-1, start, end)));
				bb.newLine();
		    }
        }
        bb.flush();
        System.out.println(sw.getBuffer());
        bb.close();
    }
     
    public static void updateTreeNodeRange(int index, int left, int right, int start, int end)
    {
        int l = 2 * index + 1, r = 2 * index + 2;
          
        if(lazy[index] == 1)
        {
		    tree[index] = (right - left + 1) - tree[index];
               
		    if(left != right)
		    {
				lazy[l] ^= 1;
				lazy[r] ^= 1;
		    }
		    lazy[index] = 0;
        }
          
        if ((left > right) || (left > end) || (right < start))
            return ;
          
        if ((left >= start) && (right <= end)) 
        {
            tree[index] = (right - left + 1) - tree[index];
               
            if(left != right)
            {
				lazy[l] ^= 1;
				lazy[r] ^= 1;
            }
            return ;
        }
     
        updateTreeNodeRange(index * 2 + 1, left, (left + right)/2, start, end); 
        updateTreeNodeRange(index * 2 + 2, 1 + (left + right)/2, right, start, end);
     
        tree[index]  = tree[l]  + tree[r];
        return ;
    }
     
    public static int queryRange(int index, int left, int right, int start, int end)
    {
        int l = 2 * index + 1, r = 2 * index + 2;
     
        if(lazy[index] == 1)
        {
            tree[index] = (right - left + 1) - tree[index];
               
            if(left != right)
		    {
				lazy[l] ^= 1;
				lazy[r] ^= 1;
		    }
		    lazy[index] = 0;
        }
     
        if ((left > right) || (left > end) || (right < start))  
            return 0; 
     
        if ((left >= start) && (right <= end)) 
            return tree[index]; 
          
        return (queryRange(2 * index + 1, left, (left + right)/2, start, end) +
            queryRange(2 * index + 2, 1 + (left + right)/2, right, start, end));
    }    
}
