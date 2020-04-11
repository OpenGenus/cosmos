/*
* JavaScript Implementation for Postman Sort Algorithm
*/

let temp, max, count, maxdigits = 0, c = 0;
let t1, t2, k, t, n = 1, p, s;

/* Function to arrange the of sequence having same base */
function arrange(p, s) {
    for(var i = p; i < s - 1; i++) {
        for(var j = i + 1; j < s; j++) {
            if(arr1[i] > arr1[j]) {
                // swap array1[i] and array1[j]
                temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;

                temp = arr[i] % 10;
                arr[i] = arr[j] % 10;
                arr[j] = temp;
            }
        }
    }
}

count = 10;
console.log("The size of the Array : " + count);
let arr = [70, 80, 20, 50, 10, 60, 40, 100, 90, 30];
console.log("The Unsorted Array is : ");
console.log(arr);

let arr1 = new Array();
for(let i = 0; i < count; i++) {
    // first element in t
    t = arr[i];
    // Calculating the Number of digits using logarithmic
    c = Math.trunc(Math.log(arr[i]/Math.log(10)));
    // number of digits in a each number
    if(maxdigits < c)
    maxdigits = c;                               
}

while(--maxdigits)
n = n * 10;

for(var i = 0; i < count; i++) {
    // MSB - Dividing by particular base
    max = arr[i] / n; 
    t = i;
    for(var j = i + 1; j < count; j++) {
        if(max > arr[j]/n) {
            max = arr[j] / n;
            t = j;
        }
    }
    temp = arr1[t];
    arr1[t] = arr1[i];
    arr1[i] = temp;
    temp = arr[t];
    arr[t] = arr[i];
    arr[i] = temp;
}

while (n >= 1) {
    for(var i = 0; i < count;) {
        t1 = arr[i] / n;
        for(j = i + 1; t1 == (arr[j] / n); j++);
        arrange(i, j);
        i = j;
    }
    n = n / 10;
}

console.log("Sorted Array is : ");
console.log(arr);

/*
INPUT :
The size of the Array : 10
The Unsorted Array is : [70, 80, 20, 50, 10, 60, 40, 100, 90, 30]

OUTPUT : 
Sorted Array is : [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
*/
