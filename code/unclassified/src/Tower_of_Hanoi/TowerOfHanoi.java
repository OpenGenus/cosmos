import java.util.Scanner;

public class TowerOfHanoi{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		toh("a","b","c",3);
	}

	private static void toh(String src, String dest, String helper, int i) {
		if(i==0){
			return;
		}
		toh(src,helper,dest,i-1);
		System.out.println("Move "+ i +" from "+src+" to "+dest);
		toh(helper,dest,src,i-1);
	}
}
