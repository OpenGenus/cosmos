import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
      Scanner scn = new Scanner(System.in);
      int n = scn.nextInt();
      String src="initial";
      String spr="spare" ;
      String fn="final";
      toh(n,src,spr,fn);
    }

    public static void toh(int n, String src, String spr, String fn){
        if(n==0)
        {
            return;
        }
        else
        {
        toh(n-1,src,fn,spr);
        System.out.println("Moved "+n+" From "+src+" -> "+fn);
        toh(n-1,spr,src,fn);
        }
        
        
        
        
        
    }

} 
