/*
* Part of Cosmos by OpenGenus Foundation
* The Lonely Integer Problem
* Given an array in which all the no. are present twice except one, find that lonely integer.
*/

public class LonelyInt{
  public static void main(String args[]){
    int[] testArr = {1,1,2,4,2};
    System.out.println(lonelyInt(testArr));
  }
  public static int lonelyInt(int[] arr){
    int lonely = 0;
    for(int i : arr){
        lonely ^= i;
    }
    return lonely;
  }
}
