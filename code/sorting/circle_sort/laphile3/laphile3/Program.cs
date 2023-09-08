using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace laphile3
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("press [1] to add new  person");
                Console.WriteLine("press [2] to Desplay person");
                Console.WriteLine("press [3] to add person");
                int choice;
                choice = int.Parse(Console.ReadLine());
                if (choice == 1)
                {
                    FileStream fs = new FileStream("people.txt", FileMode.Append);
                    StreamWriter sw = new StreamWriter(fs);
                    while (true)
                    {
                        
                        Console.WriteLine("Enter the ID ");
                        int ID = int.Parse(Console.ReadLine());
                        string id = "ID= ";
                        Console.WriteLine("Enter the Name");
                        string Name = Console.ReadLine();
                        string name = "Name=";
                        sw.WriteLine(id + ID);
                        sw.WriteLine(name + Name);
                        Console.WriteLine("press y to add agin or n to main menu");
                        char mychoice = char.Parse(Console.ReadLine());
                        if (mychoice == 'n')
                        {
                            break;
                        }

                    }
                    sw.Close();

                }
                else if (choice == 2)
                {
                    FileStream fs = new FileStream("people.txt", FileMode.Open);
                    StreamReader sr = new StreamReader(fs);
                    while (sr.Peek() != -1)
                    { 
                        string check = sr.ReadLine();
                        string[] tap1 =check.Split('=');
                        string TakeID = tap1[1];
                         check = sr.ReadLine();
                         tap1 = check.Split('=');
                        string TakeName = tap1[1];
                        Console.WriteLine("ID\tName\n--\t----");
                        Console.Write(TakeID);
                        Console.Write("\t");
                        Console.WriteLine(TakeName);
                        Console.WriteLine();

                    }
                    sr.Close();

                }
                    else break;


            }

        }
    }
}
