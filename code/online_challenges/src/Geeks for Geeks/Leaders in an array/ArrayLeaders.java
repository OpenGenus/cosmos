import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class ArrayLeaders {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while(t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			
			String str []= br.readLine().split(" ");
			List<Integer> list = new ArrayList<Integer>();
			
			int max = Integer.parseInt(str[n-1]);
			list.add(max);
			StringBuffer sb = new StringBuffer();
			for(int i=n-2;i>=0;i--){
				int num1 = Integer.parseInt(str[i]);
				if(num1 >= max) {
					max = num1;
					list.add(max);
				}
			}
			for(int j=list.size()-1;j>=0;j--)
		    {
		        sb.append(list.get(j));
		        sb.append(' ');
		    }
		    System.out.print(sb);
		    System.out.println();
		}

	}

}
