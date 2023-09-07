import java.util.*;

public class UniqueNumber {

    public static void main(String[] args) {
        // token array to search
	int[] a = new int[10];
	System.out.println(uniqueNumber(a));
    }

    public int uniqueNumber(int[] a) {
	Map<Integer, Integer> numbers = new HashMap<Integer, Integer>();
	for (int i=0; i<a.length; i++) {
	    numbers.put(a[i], numbers.getOrDefault(a[i], 0) + 1);
	}
	for (int i=0; i<a.length; i++) {
	    if (numbers.get(a[i]) != 3) {
		return numbers[i];
	    }
	}

	return -1;
    }
