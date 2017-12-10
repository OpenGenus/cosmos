// Part of Cosmos by OpenGenus Foundation

import java.util.ArrayList;

public class Main {
    static ArrayList<Integer> array = new ArrayList<>();

    private static void replase(int num) {

        while (num > 0) {
            int k = num % 10;
            array.add(k);
            num = num / 10;
        }
        for (int i = 0; i < array.size(); i++) {
            if (array.get(i) == 0) {
                array.set(i, 5);
            }
        }
        int s = array.size();
        for (int j = 0; j < array.size() / 2; j++) {
            s--;
            int id = array.get(j);
            int last = array.get(s);
            array.set(j, last);
            array.set(s, id);
        }
    }

    public static void main(String[] args) {
        int number = 14912400;
        replase(number);
        System.out.println(array);
    }
} 
