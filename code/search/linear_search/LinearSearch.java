/*
 * Part of Cosmos by OpenGenus Foundation
 *
 */

// A possible (imaginary) package.
package org.opengenus.cosmos.search;

import java.util.Scanner;

/**
 * The {@code LinearSearch} class is the simplest of the searching
 * algorithm. The goal of the algorithm is to check the existence of an
 * element in the given array.
 * <p>
 * <b>How it works</b>
 * {@code LinearSearch} goes through each element of the given array until
 * either the element to be searched is found or we have reached the end
 * of the array.
 * <p>
 * <b>Complexity</b>
 * Time Complexity -> O(n)
 * Space Complexity -> O(1)
 *
 * @author Cosmos by OpenGenus Foundation
 *
 */
class LinearSearch {
    
    /**
     * Searches for key in the given array. Returns the index within this
     * array that is the element searched for.
     *
     * @param   arr
     *          Array that is the source of the search.
     *
     * @param   key
     *          The number to be searched for in the array.
     *
     * @return  the index of the element, else -1.
     */
    static int linearSearch(int arr[], int key) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == key)
                return i;
        }
        return -1;
    }
    
    /**
     * A recursive implementation of {@link #linearSearch()}
     *
     * @param   arr
     *          Array that is the source of the search.
     *
     * @param   key
     *          The number to be searched for in the array.
     * 
     * @return A recursive call to {@link #recursiveLinearSearch()}
     */
    static int recursiveLinearSearch(int arr[], int key) {
        return recursiveLinearSearch(arr, key, 0);
    }
    
    private static int recursiveLinearSearch(int arr[], int key, int index) {
        
        // Key not found at all.
        if (index == arr.length)
            return -1;
        
        // Key found at current index.
        if (key == arr[index])
            return index;
        
        // Else, keep moving through indices
        return recursiveLinearSearch(arr, key, index + 1);
    }
    
    public static void main(String args[]) {
        
        // Object of scanner class to take input.
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array to be searched");
        int size = sc.nextInt();
        int arr[] = new int[size];
        
        // Loop to take input.
        for(int i = 0; i < size; i++) {
            System.out.println("Enter the element number " + (i + 1) + " of the array");
            arr[i] = sc.nextInt();
        }
        
        System.out.println("Enter the number you want to find");
        int key = sc.nextInt();
        
        System.out.println("Position of " + key + " is " + linearSearch(arr, key));
        System.out.println("Position of " + key + " is " + recursiveLinearSearch(arr, key));
    }
}
