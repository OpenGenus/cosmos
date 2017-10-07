//Part of Cosmos by OpenGenus Foundation

import java.util.*;

public class coprime{
	
	public static void main(String args[]){
		
		Scanner i= new Scanner(System.in);
                int a,b;
		System.out.println("Enter 1st Number");
		a=i.nextInt();
		System.out.println("Enter 2nd Number");
		b=i.nextInt();
		
		while(b!=0) {
                int x=a;
                a=b;
                b=x%b;
        }
        
		if(a==1){
            System.out.println("Coprime");
		}
                
        else{
            System.out.println("Not Coprime");
        }
	}


}
