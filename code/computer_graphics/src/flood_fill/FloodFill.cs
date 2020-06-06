using System;

namespace Cosmos
{
	public static class FloodFill
	{
		public static void Fill4(ref int[,] buffer, int x, int y, int newColor, int oldColor)
		{
			if (IsInBounds(buffer, x, y) && buffer[x, y] == oldColor && buffer[x, y] != newColor)
			{
				buffer[x, y] = newColor;

				Fill4(ref buffer, x + 1, y, newColor, oldColor);
				Fill4(ref buffer, x - 1, y, newColor, oldColor);
				Fill4(ref buffer, x, y + 1, newColor, oldColor);
				Fill4(ref buffer, x, y - 1, newColor, oldColor);
			}
		}

		public static void Fill8(ref int[,] buffer, int x, int y, int newColor, int oldColor)
		{
			if (IsInBounds(buffer, x, y) && buffer[x, y] == oldColor && buffer[x, y] != newColor)
			{
				buffer[x, y] = newColor;

				Fill8(ref buffer, x + 1, y, newColor, oldColor);
				Fill8(ref buffer, x - 1, y, newColor, oldColor);
				Fill8(ref buffer, x, y + 1, newColor, oldColor);
				Fill8(ref buffer, x, y - 1, newColor, oldColor);
				Fill8(ref buffer, x + 1, y + 1, newColor, oldColor);
				Fill8(ref buffer, x - 1, y - 1, newColor, oldColor);
				Fill8(ref buffer, x - 1, y + 1, newColor, oldColor);
				Fill8(ref buffer, x - 1, y - 1, newColor, oldColor);
			}
		}
		
		public static void FillScanline(ref int[,] buffer, int x, int y, int newColor, int oldColor)
		{
			if (buffer[x, y] == oldColor && oldColor != newColor)
			{
				// Left
				var nextX = x - 1;
				while (nextX >= 0 && buffer[nextX, y] == oldColor)
				{
					buffer[nextX, y] = newColor;
					nextX--;
				}
				
				// Right
				nextX = x;
				while (nextX < buffer.GetLength(0) && buffer[nextX, y] == oldColor)
				{
					buffer[nextX, y] = newColor;
					nextX++;
				}

				// Below
				nextX = x;
				while (nextX < buffer.GetLength(0) && buffer[nextX, y] == newColor)
				{
					if (y < buffer.GetLength(1) - 1 && buffer[nextX, y + 1] == oldColor)
						FillScanline(ref buffer, nextX, y + 1, newColor, oldColor);
					nextX++;
				}

				nextX = x - 1;
				while (nextX >= 0 && buffer[nextX, y] == newColor)
				{
					if (y < buffer.GetLength(1) - 1 && buffer[nextX, y + 1] == oldColor)
						FillScanline(ref buffer, nextX, y + 1, newColor, oldColor);
					nextX--;
				}

				// Above
				nextX = x;
				while (nextX < buffer.GetLength(0) && buffer[nextX, y] == newColor)
				{
					if (y > 0 && buffer[nextX, y - 1] == oldColor)
						FillScanline(ref buffer, nextX, y - 1, newColor, oldColor);
					nextX++;
				}

				nextX = x - 1;
				while (nextX >= 0 && buffer[nextX, y] == newColor)
				{
					if (y > 0 && buffer[nextX, y - 1] == oldColor)
						FillScanline(ref buffer, nextX, y - 1, newColor, oldColor);
					nextX--;
				}
			}
		}

		private static bool IsInBounds(int[,] buffer, int x, int y)
		{
			return x >= 0 && x < buffer.GetLength(0) && y >= 0 && y < buffer.GetLength(1);
		}

		public static void Main(string[] args)
		{
			var buffer = new[,]
			{
				{1, 1, 0, 0, 0, 0, 1, 1, 1},
				{1, 1, 0, 0, 0, 0, 1, 1, 1},
				{1, 0, 0, 0, 0, 0, 1, 1, 1},
				{0, 1, 0, 0, 0, 0, 1, 1, 1}, // <-- Fill8 will leak here, Fill4 (and FillScanline) won't
				{0, 0, 1, 0, 0, 1, 1, 1, 1},
				{0, 0, 0, 1, 0, 1, 1, 1, 1},
				{0, 0, 0, 0, 1, 1, 1, 1, 1},
				{1, 1, 0, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0, 0, 0, 0, 0},
			};

			FillScanline(ref buffer, 0, 8, 2, 1);

			for (var i = 0; i < buffer.GetLength(0); i++)
			{
				for (var j = 0; j < buffer.GetLength(1); j++)
				{
					Console.Write(buffer[i, j] + " ");
				}

				Console.WriteLine();
			}
		}
	}
}