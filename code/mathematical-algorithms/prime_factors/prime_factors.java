/* Part of Cosmos by OpenGenus Foundation */
import java.util.*;

public class PrimeFactors {
    public static List<Integer> primeFactors(int numbers) {
        int n = numbers;
        List<Integer> factors = new ArrayList<Integer>();
        for (int i = 2; i <= n / i; i++) {
            while (n % i == 0) {
                factors.add(i);
                n /= i;
            }
        }
        if (n > 1) {
            factors.add(n);
        }
        return factors;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println("Primefactors of " + n);
        List<Integer> al =  primeFactors(n);
        //remove duplicate 
        // if you want the duplicate remove the following 3 lines
        Set<Integer> hs = new HashSet<>();
        hs.addAll(al);
        al.clear();
        al.addAll(hs);
        for (Integer integer : al) {
            System.out.println(integer);
        }
    }
}
