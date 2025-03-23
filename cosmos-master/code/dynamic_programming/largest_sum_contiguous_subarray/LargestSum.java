import java.util.*;

public class LargestSum{
    public static void main(String[] args) {
        int input[] = new int[5];
        int sum = 0;
        for (int i=0 ; i<5; i++){
            Scanner scanner = new Scanner(System.in);
            input[i] = scanner.nextInt();
            sum = sum + input[i];
        }
        Arrays.sort(input);
        System.out.println(sum - input[0]);
    }
}