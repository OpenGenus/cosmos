using System; 
namespace Cosmos
{
	public static class AreaOfPolygon
	{
		public static double createShape(){
            Console.WriteLine("Enter number of sides of the polygon: "); 
            int n = int.Parse(Console.ReadLine()); 
            int [] x = new int[n]; 
            int [] y = new int[n]; 
            for(int i =0; i < n; i++){
                Console.WriteLine("Enter x coordinate: "); 
                x[i] = int.Parse(Console.ReadLine()); 
                Console.WriteLine("Enter y coordinate: "); 
                y[i] = int.Parse(Console.ReadLine()); 
            }
			return calculateArea(x, y); 
		}

        public static double calculateArea(int[] xCoords, int[] yCoords){
            int length = xCoords.Length; 
            int b; 
            double area = 0; 
            for (int i = 0; i < length; i ++){
                b = (i + 1) % length; 
                area += xCoords[i] * yCoords[b] - xCoords[b] * yCoords[i]; 
            }
            area = Math.Abs(area) / 2.0; 
            return area; 
        }
        
        public static void Main(string[] args)
    {
        double area = createShape();
        Console.WriteLine($"The area of the polygon is: {area}");
    }
	}
}