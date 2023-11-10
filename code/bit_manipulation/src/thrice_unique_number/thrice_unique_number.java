/*
 * Part of Cosmos by OpenGenus Foundation
*/
import java.util.*;

public class ThriceUniqueNumber {
    
    final public static int BITS=32;
    
    public static int ConvertToDec(int bitArr[]){
        int decNum=0;
        for(int i=0;i<BITS;++i){
            decNum+=bitArr[i]* (1<<i);
        }
        return decNum;
    }
    public static void SetArray(int bitArr[], int num){
        // update the bitArr to binary code of num
        
        int i=0;
        while(num!=0){
            if((num&1)!=0){
                bitArr[i]++;
            }
            num>>=1;
            i++;
    }
}
    public static int thriceUniqueNumber(int arr[], int size){
        
        // at max the numeber of bits can be 32 in a binary no.
        int[] bitArr=new int[BITS];
        
        for(int i=0;i<size;++i){
            SetArray(bitArr,arr[i]);
        }
        //by doing this all the numbers appearing thrice will be reomved from
        //the binary form
        for(int i=0;i<BITS;++i){
            bitArr[i] %= 3;
        }
        
        int ans=ConvertToDec(bitArr);
        
        return ans;
    }
    
    
    
    public static void main(String args[]) {
        
        Scanner s=new Scanner(System.in);
        //size of the array ( Number of elements to input)
        int size=s.nextInt();
        int[] arr=new int[size];
        //input size number of elements
        for(int i=0;i<size;i++){
            arr[i]=s.nextInt();
        }
        //function call
        System.out.println(thriceUniqueNumber(arr,size));

        /*Example
        Input
        10
        1 1 1 2 2 2 9 9 9 8

        OutPut
        8*/
    }
}
