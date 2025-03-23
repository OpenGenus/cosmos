/**
 * Generic Maxheap implementation backed by List
 * Part of the OpenGenus/cosmos project. (https://github.com/OpenGenus/cosmos)
 * 
 * A heap is a data structure that satisifies the heap property.
 * In this case, the heap property means that the parent(P) of a node(N) is greater than or equal to the value of N.
 * Elements are manipulated by adding them to the heap and removing the top-most element (root).
 */
using System;
using System.Collections.Generic;

namespace Cosmos_Data_Structures
{
    class MaxHeap<T> where T : IComparable
    {
        private List<T> lst;
        public int Size { get; private set; }

        public MaxHeap()
        {
            lst = new List<T>();
            Size = 0;
        }

        //Add an element to the heap.
        public void Push(T element)
        {
            //If there is room in lst, then use that space, else append to the end of lst with lst.Add().
            if (Size == lst.Count)
            {
                lst.Add(element);
            }
            else
            {
                lst[Size] = element;
            }

            Size++;
            UpSift();
        }

        //Removes and returns the root of the heap.
        //Throws an exception if the heap is empty.
        public T Pop()
        {
            if (IsEmpty())
            {
                throw new InvalidOperationException("Cannot pop on empty heap!");
            }

            T result = lst[0];
            HeapSwap(0, Size - 1);
            Size--;
            DownSift();
            //Size--;
            return result;
        }

        //Returns the root of the heap.
        public T Peek()
        {
            if (IsEmpty())
            {
                throw new InvalidOperationException("Cannot pop on empty heap!");
            }

            return lst[0];
        }

        //Returns true iff there are no elements in the heap, false otherwise.
        public bool IsEmpty()
        {
            return lst.Count == 0;
        }

        //Return a string representation of the heap.
        public override string ToString()
        {
            string result = "MaxHeap([Root] ";

            foreach (T i in lst)
            {
                result += i + " ";
            }

            result += ")";
            return result;
        }

        //Comparision helper function.
        private bool Compare(T a, T b)
        {
            return a.CompareTo(b) > 0;
        }

        //List swapping helper function.
        //a and b are List indexes.
        private void HeapSwap(int a, int b)
        {
            T tmp = lst[a];
            lst[a] = lst[b];
            lst[b] = tmp;
        }

        //Re-heapifies the heap when the root is removed.
        //Essentially, a new root is set (usually the last element in the heap) , and is checked to see if it satisfies the heap property.
        //If not, the element is moved down the heap until the heap property is satified, or the element becomes a leaf.
        //The downward movement of the root gives this function the name DownSift.
        private void DownSift()
        {
            //A heap with one element is trivally a valid heap.
            //Also deals with the edge case of an empty heap.
            if (Size <= 1) { return; }

            int current = 0;
            //Calculate the index of the children from the index of the parent.
            int left = (2 * current) + 1, right = (2 * current) + 2;
            //List bounds checking.
            bool validLeft = left < Size, validRight = right < Size;
            //Determine whether we need to check the left or the right children.
            //Short-circuit evaluation means that bounds-checking happens before heap property checking.
            bool notDone = (validLeft && !Compare(lst[current], lst[left])) || (validRight && !Compare(lst[current], lst[right]));

            while (notDone)
            {
                if (validLeft && validRight)
                {
                    if (Compare(lst[left], lst[right]))
                    {
                        HeapSwap(current, left);
                        current = left;
                    }
                    else
                    {
                        HeapSwap(current, right);
                        current = right;
                    }
                }
                else if (validLeft)
                {
                    HeapSwap(current, left);
                    current = left;
                }
                else if (validRight)
                {
                    HeapSwap(current, right);
                    current = right;
                }

                left = (2 * current) + 1;
                right = (2 * current) + 2;
                validLeft = left < Size;
                validRight = right < Size;
                notDone = (validLeft && !Compare(lst[current], lst[left])) || (validRight && !Compare(lst[current], lst[right]));
            }
        }

        //Re-heapifies the heap when a new element is added.
        //Essentially, if the inserted element does not satify the heap property, then the parent and child elements are swapped.
        //This continues until either the inserted element satifies the heap property with its parents, or it becomes the root.
        //The inserted element moves up the heap until the heap property is satisfied, hence the name UpSift.
        private void UpSift()
        {
            //A heap with one element is trivally a valid heap.
            //Also deals with the edge case of an empty heap.
            if (Size <= 1) { return; }

            int current = Size - 1;
            int parentIndex = (current - 1) / 2;

            while (Compare(lst[current], lst[parentIndex]))
            {
                HeapSwap(current, parentIndex);
                current = parentIndex;
                parentIndex = (current - 1) / 2;
            }
        }
    }

    //Test function for the heap.
    //Implements a basic heapsort algorithm.
    class MaxHeapTest
    {        
        static void Main(string[] args)
        {
            var heap = new MaxHeap<int>();
            var data = new int[] { 4, 11, 7, 12, 32, 8, 12, 21, 2};

            foreach(var i in data)
            {
                heap.Push(i);
            }

            for(int i = heap.Size; i != 0; i--)
            {
                Console.WriteLine(heap.Pop());
            }
            Console.ReadKey();
        }
        
    }
}
