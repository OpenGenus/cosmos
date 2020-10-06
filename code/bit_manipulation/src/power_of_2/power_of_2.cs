using System;

class MainClass {
  public static void Main(String[] args){
 		int num = Convert.ToInt32(Console.ReadLine());

		if(((num & (num-1))==0) && (num != 0))
			Console.WriteLine("Yes, the number is a power of 2");
		else
			Console.WriteLine("No, the number is not a power of 2");
  }
}
