import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
class Frequency_Sort {
 
    static Integer[] arr= { 2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8 };
 

    public static void main(String[] args)
    {
        List<Integer> list = Arrays.asList(arr);
 

        sortBasedOnFrequencyAndValue(list);
    }
 
  
    public static void
    sortBasedOnFrequencyAndValue(List<Integer> list)
    {
        int n = arr.length;
        final HashMap<Integer, Integer> mapCount
            = new HashMap<Integer, Integer>();
        final HashMap<Integer, Integer> mapIndex
            = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; i++) {
            if (mapCount.containsKey(arr[i])) {
                mapCount.put(arr[i], mapCount.get(arr[i]) + 1);
            }
            else {
                mapCount.put( arr[i], 1);
                mapIndex.put(arr[i], i); 
            }
        }
 
        Collections.sort(list, new Comparator<Integer>() {
            public int compare(Integer n1, Integer n2)
            {
                int freq1 = mapCount.get(n1);
                int freq2 = mapCount.get(n2);
                if (freq1 != freq2) {
                    return freq2 - freq1;
                }
                else {
                    return mapIndex.get(n1)- mapIndex.get(n2); 
                }
            }
        });
        System.out.println(list);
    }
}
