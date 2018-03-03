package Problem_001;
public class Problem_001 {

	public static void main(String []args) {
		int sum = 0;
		for(int i = 1; i < 1000; i++) {
			if(i % 3 ==0 || i % 5 == 0)
			{
				sum += i;
			}
		}
		System.out.print(sum); //233168
	} 
}
