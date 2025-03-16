import java.util.Scanner;

class search_element{
	public static void main(String []args){
		Scanner obj=new Scanner(System.in);
		System.out.println("Enter the no of elememts");
		int n=obj.nextInt();
		int []a=new int[100];
		for(int i=0;i<n;i++){
			a[i]=obj.nextInt();
		}
		System.out.println("Enter the elememts");
 		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]>a[j]){
					int temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		System.out.println("The sorted array is ");
		for(int i=0;i<n;i++){
			System.out.println(a[i]);
		}
		System.out.println("Enter the element u want to search");
		int k=obj.nextInt();
		int p,flag=0,q,mid;
		p=0;
		q=n;
		
		while(p<=q){
			mid=(p+q)/2;
			if(a[mid]==k){
				flag=1;
				System.out.println("Element found at index "+mid);
				break;
			}
			else if(k>a[mid]){
				p=mid+1;			
			}
			else{
				q=mid-1;
			}
		}		
		if(flag==0){
			System.out.println("The element you are searching for doesn't exist in the array");
		}		

	}




}
