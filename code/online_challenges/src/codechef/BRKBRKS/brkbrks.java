import java.util.*;
import java.lang.*;
import java.io.*;

class brkbks{
	
	public static void main (String[] args) throws java.lang.Exception{
	
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while (t-- >0){
		    int strength= s.nextInt();
		    int w1 = s.nextInt();
		    int w2 = s.nextInt();
		    int w3 = s.nextInt();
		    ArrayList<Integer> arrLL = new ArrayList<>();
		    arrLL.add(w1);
		    arrLL.add(w2);
		    arrLL.add(w3);
		    int hits = 0;
		    while (arrLL.size() !=0){
		        int sum = 0;
		        while (sum <strength){
		            sum = sum + arrLL.get(0);
		            if (sum <= strength){
		                arrLL.remove(0);
		            }
		            if (arrLL.size() ==0){
		                break;
		            }
		        }
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