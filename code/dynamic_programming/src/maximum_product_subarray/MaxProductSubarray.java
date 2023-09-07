public class MaxProductSubarray{
	static int findMaxProduct(int arr[]){
		if(arr.length == 0)
			return 0;
		int maxNegativeProduct= arr[0], maxPositiveProduct = arr[0], ans= maxPositiveProduct;
		for(int i = 1;i < arr.length; i++) {
			if(arr[i] < 0){
				int temp = maxNegativeProduct;
				maxNegativeProduct = maxPositiveProduct;
				maxPositiveProduct = temp;
			}
			maxNegativeProduct = Math.min( arr[i] , arr[i] * maxNegativeProduct);// minimize negative element
			maxPositiveProduct = Math.max( arr[i] , arr[i] * maxPositiveProduct);// maximize positive element
			ans = Math.max( ans , maxPositiveProduct);//maximize answer
		}
		return ans;
	}
	public static void main(String args[]) {
		int arr1[] = {1,-1,5,3,-2,4,6,-11};//test1
		System.out.println( findMaxProduct(arr1) );
		//int arr2[]={1,2,3,-1,11,-100,10,20,30};//test2
		//System.out.println( findMaxProduct(arr2) );
	}
}
