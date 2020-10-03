import java.util.ArrayList;

public class TwoDimensionalArrayLists{
    
    public static void main(String args[]) {
    
        // Creating 2D ArrayList
        ArrayList<ArrayList<Integer> > arrLL = new ArrayList<ArrayList<Integer> >();
    
        // Allocating space to 0th row with the help of 'new' keyword
        // At 0th row, 0 gets stored in memory by default
        arrLL.add(new ArrayList<Integer>());
        // At 0th row, modifing the default value to 13
        arrLL.get(0).add(0, 13);
        
        System.out.println("2D ArrayList :");
        // Printing 2D ArrayList
        System.out.println(arrLL);

	// Determining the index of element - 13
        int ans = arrLL.get(0).indexOf(13);
        System.out.println(" Index of element 13 is "+ ans);

	// Determining the last index of element - 13
        int ans = arrLL.get(0).lastIndexOf(13);
        System.out.println(" Last Index of element 13 is "+ ans); 

	// 0th row gets deleted from the arrayList created
        arrLL.remove(0);
        // Modified arrayList is
        System.out.println(arrLL);
	
	// To check whether 13 present at a particular row in our ArrayList
        System.out.println(x.get(0).contains(13));
        System.out.println(x.get(0).contains(1));

	
   }
}

