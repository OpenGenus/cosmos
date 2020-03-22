import 'dart:io';

class BubbleSort 
{
    List<int> unsorted;
    BubbleSort(this.unsorted);

    //add array that you want to sort
    void addArray(int count, List<int> list) 
    {
        list = [];
        unsorted = list;
        for (int i = 0; i < count; i++) 
        {
            print('Add number to array : ');
            var input = stdin.readLineSync();
            int x = int.parse(input);
            assert(x is int);
            unsorted.add(x);
        }
    }

    printArray(List<int> array) 
    {
        for (int i = 0; i < array.length; i++) 
        {
            print(array[i]);
        }
    }

    void sort(List<int> a) 
    {
        for (var i = 0; i < a.length; i++) 
        {
            bool swaped = false;
            for (var j = i + 1; j < a.length; j++) 
            {
                if (a[i] > a[j]) 
                {
                    var tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                    swaped = true;
                }
            }
            if (!swaped) break;
        }
    }
}

void main() 
{
    List<int> unsorted = [];
    BubbleSort bubbleSort = new BubbleSort(unsorted);
    print('Enter the number of elements');
    var countString = stdin.readLineSync();
    int count = int.parse(countString);
    bubbleSort.addArray(count, unsorted);
    print('The given array is : ');
    bubbleSort.printArray(bubbleSort.unsorted);
    // sort the array and display using the next print
    bubbleSort.sort(bubbleSort.unsorted);
    print('Sorted Array is:');
    bubbleSort.printArray(bubbleSort.unsorted);
}

/*Sample Input and Output
Enter the number of elements
6
Add number to array :
45
Add number to array :
78
Add number to array :
34
Add number to array :
21
Add number to array :
1
Add number to array :
98
The given array is :
45
78
34
21
1
98
Sorted Array is:
1
21
34
45
78
98 
*/
