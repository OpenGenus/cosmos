/*
 Part of Cosmos by OpenGenus Foundation
 Ternary Search Uses Divide And Conquer Technique
 */

int ternarySearch(int arr[],int l,int r, int x){
    if(r>=l){
        int mid1 = l + (r-l)/3;
        int mid2 = r - (r-l)/3;
        if(arr[mid1] == x)
            return mid1;
        /*
            In this search, after each iteration it neglects (1/3)rd part of the array and repeats the same operations on the remaining 2/3rd 		    part of array 
        */
        if(arr[mid2] == x)
            return mid2;
        if(x<arr[mid1])
            return ternarySearch(arr,l,mid1-1,x);
        else if(x>arr[mid2])
            return ternarySearch(arr,mid2+1,r,x);
        else
            return ternarySearch(arr,mid1+1,mid2-1,x);
    }
    return -1; // if x is not found in array arr
}
