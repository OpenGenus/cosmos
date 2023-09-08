import java.util.Scanner;

class array_funcs{
	
	public static void main(String []args){
		Scanner obj=new Scanner(System.in);
		int a,l,pos=0;
		System.out.println("Enter the size of array ");
		int n=obj.nextInt();
		int[] arr=new int[100];
		for(int i=0;i<n;i++){
			arr[i]=obj.nextInt();
		}
		System.out.println("Press 1 to Insert a new element || Press 2 to Delete an element || Press 3 to find the location of a given element || Press 4 to display the elements");
		a=obj.nextInt();
		switch(a){
			case 1:
				System.out.println("Enter the element you want to insert ");				
				l=obj.nextInt();
				System.out.println("Enter the pos where you want to insert the element");				
				pos=obj.nextInt();
				for(int i=n;i>=pos;i--){
					arr[i]=arr[i-1];
				}
				arr[pos]=l;
				System.out.println("New array after insertion");
				for(int i=0;i<=n;i++){
					System.out.println(arr[i]);
				}
				break;
			case 2:
				System.out.println("Enter the element you want to delete ");				
				l=obj.nextInt();
				for(int i=0;i<n;i++){
					if(arr[i]==l){
						pos=i;
						break;
					}
				}
				for(int i=pos;i<n;i++){
					arr[i]=arr[i+1];
				}
				System.out.println("New array after deletion");
				for(int i=0;i<n-1;i++){
					System.out.println(arr[i]);
				}
				break;	
			case 3:
				System.out.println("Enter the element you want to locate ");				
				l=obj.nextInt();
				for(int i=0;i<n;i++){
					if(arr[i]==l){
						pos=i;
						break;
					}
				}
				System.out.println("Element found at "+pos);
				break;
			case 4:
				for(int i=0;i<n;i++){
					System.out.println(arr[i]);
				}
				
				break;
			default:
				System.out.println("Enter a valid no");	
		}


	}




}
