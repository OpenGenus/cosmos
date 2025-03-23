import java.util.*; 
import java.lang.*; 
  
public class HashTable { 
  
    // function to sort hashmap by values 
    public static HashMap<String, Integer> sortByValue(HashMap<String, Integer> hm) 
    { 
        // Create a list from elements of HashMap 
        List<Map.Entry<String, Integer> > list = 
               new LinkedList<Map.Entry<String, Integer> >(hm.entrySet()); 
  
        // Sort the list 
        Collections.sort(list, new Comparator<Map.Entry<String, Integer> >() { 
            public int compare(Map.Entry<String, Integer> o1,  
                               Map.Entry<String, Integer> o2) 
            { 
                return (o1.getValue()).compareTo(o2.getValue()); 
            } 
        }); 
          
        // put data from sorted list to hashmap  
        HashMap<String, Integer> temp = new LinkedHashMap<String, Integer>(); 
        for (Map.Entry<String, Integer> aa : list) { 
            temp.put(aa.getKey(), aa.getValue()); 
        } 
        return temp; 
    } 

    public static void main(String[] args) 
    { 
  
        HashMap<String, Integer> hm = new HashMap<String, Integer>(); 
  
        // enter data into hashmap 
        hm.put("Math", 98); 
        hm.put("Data Structure", 85); 
        hm.put("Database", 91); 
        hm.put("Java", 95); 
        hm.put("Operating System", 79); 
        hm.put("Networking", 80); 
        Map<String, Integer> hm1 = sortByValue(hm); 
  
        // print the sorted hashmap 
        for (Map.Entry<String, Integer> en : hm1.entrySet()) { 
            System.out.println("Key = " + en.getKey() +  
                          ", Value = " + en.getValue()); 
        } 
    } 
} 
