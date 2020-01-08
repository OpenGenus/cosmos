import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class RotateArray {
	public static void main(String [] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while(t-- > 0) {
			String nd [] = br.readLine().split(" ");
			int n = Integer.parseInt(nd[0]);
			int d = Integer.parseInt(nd[1]);
			String str [] = br.readLine().split(" "); 
            StringBuffer sb = new StringBuffer();
            for(int i=d;i<=n-1;i++) {
            	int num = Integer.parseInt(str[i]);
            	sb.append(num + " ");
            }
            for(int i=0;i<d;i++) {
            	int num = Integer.parseInt(str[i]);
            	sb.append(num +" ");
            }
            System.out.println(sb.toString());
		}
	}
}
