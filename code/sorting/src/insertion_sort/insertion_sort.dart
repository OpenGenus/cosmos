import 'dart:io';
class InsertionSort 
{
    List<int> array;
    InsertionSort(this.array);

    void insertionSort(List<int> a, int size) 
    {
        int temp, j;
        for (int i = 1; i < a.length; i++) 
        {
            temp = a[i];
            j = i - 1;
            while (j >= 0 && array[j] > temp) 
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = temp;
        }
    }

    void readArray(int n ,List<int> a) 
    {
        for (int i = 0; i < n; i++) 
        {
            print('Add number to array : ');
            var input = stdin.readLineSync();
            int x = int.parse(input);
            assert(x is int);
            a.add(x);
        }
    }

    void printArray(List<int> a) 
    {
        for (var i = 0; i < a.length; i++) 
        {
            print(a[i]);
        }
    }
}

void main() 
{
    List<int> array = [];
    InsertionSort sort = InsertionSort(array);
    print('Enter number of elements of array:');
    var input = stdin.readLineSync();
    int size = int.parse(input);
    sort.readArray(size ,sort.array);
    sort.insertionSort(sort.array, size);
    print('Sorted Array is : ');
    sort.printArray(sort.array);
}

/* Sample Input and Output
Enter number of elements of array:
6
Add number to array :
87
Add number to array :
90
Add number to array :
43
Add number to array :
10
Add number to array :
134
Add number to array :
34
Sorted Array is :
10
34
43
87
90
134
*/
