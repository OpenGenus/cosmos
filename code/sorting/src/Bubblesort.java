public class Bubblesort
{
   public static void printArray(int arr[]){
   for (int i = 0 ; i < arr.length ; i++){
      System.out.println(arr[i]+"");
      }
   }
   public static void main(String[] args) {
      int arr[] = {7 , 9 , 5 , 22 , 344 , 32, 5};
      {
         for (int i = 0 ; i < arr.length;i++)
         {
            for (int j = 0 ; j < arr.length - i - 1 ; j++)
            {
               if (arr[j] > arr[j+1]){
                  //swap
                  int temp = arr[j];
                  arr[j] = arr[j+1];
                  arr[j+1] = temp;
               }
            }
         }
      }
      printArray(arr);
   }
}
