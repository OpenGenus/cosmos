using System;

namespace Cosmos
{
	public static class DiamondSquare
	{
		public static double[,] Generate(int n, int randomSeed, int seedBound)
		{
			var random = new Random(randomSeed);

			var width = (int) (Math.Pow(2, n) + 1);
			var matrix = new double[width, width];

			// Set random seed values in the corners of the matrix
			matrix[0, 0] = random.NextDouble() * (seedBound - (-seedBound)) - seedBound;
			matrix[0, width - 1] = random.NextDouble() * (seedBound - (-seedBound)) - seedBound;
			matrix[width - 1, 0] = random.NextDouble() * (seedBound - (-seedBound)) - seedBound;
			matrix[width - 1, width - 1] = random.NextDouble() * (seedBound - (-seedBound)) - seedBound;

			var tileWidth = width - 1;
			while (tileWidth > 1)
			{
				var halfWidth = tileWidth / 2;

				// Diamond step
				for (var x = 0; x < width - 1; x += tileWidth)
				{
					for (var y = 0; y < width - 1; y += tileWidth)
					{
						var average =
							(matrix[x, y] +
							 matrix[x + tileWidth, y] +
							 matrix[x, y + tileWidth] +
							 matrix[x + tileWidth, y + tileWidth]) / 4;

						matrix[x + halfWidth, y + halfWidth] =
							average  + random.NextDouble() * (width - (-width)) - width;
					}
				}

				// Square step
				for (var x = 0; x < width - 1; x += halfWidth)
				{
					for (var y = (x + halfWidth) % tileWidth; y < width - 1; y += tileWidth)
					{
						var average =
							matrix[(x - halfWidth + width - 1) % (width - 1), y] +
							matrix[(x + halfWidth) % (width - 1), y] +
							matrix[x, (y + halfWidth) % (width - 1)] +
							matrix[x, (y - halfWidth + width - 1) % (width - 1)] / 4;
				
						matrix[x, y] =
							average + random.NextDouble() * (width - (-width)) - width;
				
						// Wrap around values
						if (x == 0) matrix[width - 1, y] = average;
						if (y == 0) matrix[x, width - 1] = average;
					}
				}

				tileWidth = halfWidth;
			}

			return matrix;
		}


		// public static void Main(string[] args)
		// {
		// 	var matrix = DiamondSquare.Generate(2, 16, 128);
		//
		// 	for (var i = 0; i < matrix.GetLength(0); i++)
		// 	{
		// 		for (var j = 0; j < matrix.GetLength(1); j++)
		// 		{
		// 			Console.Write(matrix[i, j].ToString("N8") + "\t");
		// 		}
		//
		// 		Console.WriteLine();
		// 	}
		// }
	}
}