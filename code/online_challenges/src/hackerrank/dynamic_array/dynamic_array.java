import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'dynamicArray' function below.
     *
     * The function is expected to return an INTEGER_ARRAY. The function accepts
     * following parameters: 1. INTEGER n 2. 2D_INTEGER_ARRAY queries
     */

    public static List < Integer > dynamicArray(int n, List < List < Integer >> queries) {
        List < List < Integer >> seqList = new ArrayList < List < Integer >> ();
        List < Integer > seq = new ArrayList < > ();
        for (int i = 0; i < n; i++) {
            seq = new ArrayList < > ();
            seqList.add(seq);
        }
        ArrayList < Integer > ans = new ArrayList < Integer > ();
        int lastAns = 0;
        for (int i = 0; i < queries.size(); i++) {
            int querynum = queries.get(i).get(0);
            int x = queries.get(i).get(1);
            int ele = queries.get(i).get(2);
            if (querynum == 1) {
                seqList.get((x ^ lastAns) % n).add(ele);
            } else if (querynum == 2) {
                seq = seqList.get((x ^ lastAns) % n);
                lastAns = seq.get(ele % seq.size());
                ans.add(lastAns);
            }
        }
        return ans;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int q = Integer.parseInt(firstMultipleInput[1]);

        List < List < Integer >> queries = new ArrayList < > ();

        IntStream.range(0, q).forEach(i - > {
            try {
                queries.add(Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                    .map(Integer::parseInt).collect(toList()));
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        List < Integer > result = Result.dynamicArray(n, queries);

        bufferedWriter.write(result.stream().map(Object::toString).collect(joining("\n")) + "\n");

        bufferedReader.close();
        bufferedWriter.close();
    }
}
