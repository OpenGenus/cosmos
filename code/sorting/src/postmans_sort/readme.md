# Postman sort

Did you know that an array of number can be sorted on the basis of significant digits? Let's see how!.

A highly engineered variant of top-down radix sort where attributes of the key are described so the Sorting algorithm can allocate buckets and distribute efficiently.

Postman sort works by sorting the integers of an array from their most significant digits to their least significant digits. In the Postman sort the integer having most significant digits and the number of elements in that integer is determined, the length of the longest integer is stored. All the elements in the array are divided by a particular base. The elements of the array are sorted on the basis of the most significant digit to the least significant digit i.e. from leftmost to rightmost digit.

## Example

Let's arrange the numbers in ascending order using postman sort.

- Unsorted List

The input array contains 7 elements which are {25, 432, 788, 130, 23, 121, 564}

- Iteration 1

The elements of the array being sorted on the basis of the most significant digit, it becomes {25, 23, 130, 121, 432, 564, 788}

- Iteration 2

The elements of the array being sorted on the basis of the second most significant digit, it becomes {25, 23, 121, 130, 432, 564, 788}

- Iteration 3

At last those elements of the array are compared which have same value of significant digit and if they are not in correct
order, the elements gets swapped and are arranged in desired order. The array after getting sorted becomes
{23, 25, 121, 130, 432, 564, 788}

In this way the elements of the array are sorted on the basis of their significant digits.

## Algorithm

The algorithm consists of these steps: It compares the integers in the array on the basis of the significant digits.

- Firstly, the maximum number of significant digits in the array of integers is determined, a particular base is set according to the significant digits.

- Every element in the array is divided by that particular base and in this way the leftmost digits of all the elements in the array i.e. the most significant digit is compared throughout the array elements and the numbers are swapped if they are not in correct order.

- Similarly next most significant digit is compared as the base is reset, the elements of the array which are having the same value of that particular digit are arranged by comparing their values.

- The randomly arranged numbers are sorted using Postman Sort.
Firstly the significant digits in all the elements in the array is determined, the base is set according to the maximum significant digits. In this case the maximum significant digits is 3 so the base is set as 100. All the array elements are divided by the base, in this way the most significant digit is detemined and arranged if they are not found in correct order. The base is divided by 10, the base is reset then the elements are arranged on the basis of the next most significant digit. The array elements are divided by the base , if the elements are not found in correct order they are arranged. During the last iteration, the base becomes 1, the array elements are divided by the base and are arranged if not found in correct order.

## Pseudocode
```
declare temp, max, count, maxdigits = 0, c = 0
declare t1, t ,i, j
Initialise n = 1
Input the number of elements in the array and store their values in arr[], arr1[]
//determining significant digits in all the elements 
for(i = 0; i < count; i++)
    t = arr[i]
    while(t > 0)
        c++
        t = t/10
    //maximium significant digits
    if(maxdigits < c)
        maxdigits = c
    c = 0
    
//setting the base
for(i = 0; i < maxdigits; i++)
    n = n * 10
// elements arranged on the  basis of MSD
for(i = 0; i < count; i++)
    max = arr[i] / n
    t = i
    for(j = i + 1; j < count; j++)
        if(max > (arr[j] / n))
            max = arr[j] / n
            t = j       
    temp = arr1[t]
    arr1[t] = arr1[i]
    arr1[i] = temp
    temp = arr[t]
    arr[t] = arr[i]
    arr[i] = temp
//elements arranged according to the next MSD    
while(n >= 1)
    for(i = 0; i < count;)
        t1 = arr[i] / n
        for(j = i + 1; t1 == (arr[j]/n); j++);
            arrange(i, j)
        i = j
    n = n / 10
              
// function to arrange the intergers having same bases              
void arrange(int k, int n)
    for(i = k; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
            if(arr1[i] > arr[j])
                temp = arr1[i]
                arr1[i] = arr1[j]
                arr1[j] = temp
                temp = arr[i] % 10
                arr[i] = arr[j] % 10
                arr[j] = temp
```
## Complexity 

   Time Complexity = d * (n + k)
   Space Complexity = n + 2^d

where
>d = number of digits<br/>
>n = number of keys<br/>
>k = size of bucket<br/>

## Application

The Postman's sort is a variant of bucket sort that takes advantage of a hierarchical structure of elements, typically described by a set of attributes. This is the algorithm used by letter-sorting machines in post offices: mail is sorted first between domestic and international; then by state, province or territory; then by destination post office; then by routes, etc. Since keys are not compared against each other, sorting time is O(cn), where c depends on the size of the key and number of buckets. This is similar to a radix sort that works "top down," or "most significant digit first."


