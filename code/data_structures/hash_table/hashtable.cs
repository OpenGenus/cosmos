using System;
using System.Collections;  // namespace for hashtable
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 * Part of Cosmos by OpenGenus Foundation'
 *
 * The Hashtable class represents a collection of key-and-value pairs that are organized
 * based on the hash code of the key. It uses the key to access the elements in the collection.
 * */
namespace hashtables
{
    sealed class hTable // a class
    {
        static int key; // key of the hastable
        public bool uniqueness { get; set; } // setting to check if allow uniqueness or not
        Hashtable hashtable = new Hashtable();
        internal void add(string value)
        {
            if(uniqueness)
            {
                if(hashtable.ContainsValue(value))
                {
                    Console.WriteLine("Entry exists");
                }
                else
                {
                    hashtable.Add(++key,value);
                }
            }
            else
            {
                hashtable.Add(++key, value);
            }

        }
        internal void delete(int key)
        {
            if (hashtable.ContainsKey(key))
            {
                Console.WriteLine("Deleted value : " + hashtable[key].ToString());
                hashtable.Remove(key);
            }
            else
            {
                Console.WriteLine("Key not found");
            }
        }
        internal void show()
        {
            foreach(var key in hashtable.Keys)
            {
                Console.WriteLine(key.ToString() + " : " + hashtable[key]);
            }
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            hTable obj = new hTable();

            // i want uniqueness therefore making property true
            obj.uniqueness = true;

            // adding 3 values
            Console.WriteLine("ADDING EXAMPLE");
            obj.add("terabyte");
            obj.add("sandysingh");
            obj.add("adichat");

            // adding terabyte again to see the exists message
            Console.WriteLine("ADDING 'terabyte' AGAIN");
            obj.add("terabyte");

            // showing all original
            Console.WriteLine("Original Table");
            obj.show();

            // removing value at key = 2
            Console.WriteLine("Deleting value");
            obj.delete(2);

            // showing all new
            Console.WriteLine("New Table");
            obj.show();


            Console.ReadKey(); // in ordr to pause the program
        }
    }
}
