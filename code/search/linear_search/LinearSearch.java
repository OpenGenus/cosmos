/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * Copyrigh (C) 2017 Cosmos by OpenGenus Foundation
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
    
    public static void main(String args[])
    {
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
