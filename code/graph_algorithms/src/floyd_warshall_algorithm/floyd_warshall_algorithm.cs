using System;

namespace Cosmos
{
	public static class FloydWarshall
	{
		private const float Infinity = float.PositiveInfinity;

		public static void Solve(float[,] graph)
		{
			var v = graph.GetLength(0);

			for (var k = 0; k < v; k++)
			{
				for (var i = 0; i < v; i++)
				{
					for (var j = 0; j < v; j++)
					{
						graph[i, j] = Math.Min(graph[i, j], graph[i, k] + graph[k, j]);
					}
				}
			}

			for (int i = 0; i < v; i++)
			{
				for (int j = 0; j < v; j++)
				{
					Console.Write(float.IsPositiveInfinity(graph[i, j]) ? "∞ " : $"{graph[i, j]} ");
				}
				Console.WriteLine();
			}
		}
		
		private static void Main(string[] args)
		{
			var graph = new float[,]
			{
				{0, 5, Infinity, 10},
				{Infinity, 0, 3, Infinity,},
				{Infinity, Infinity, 0, 1},
				{Infinity, Infinity, Infinity, 0}
			};
			
			FloydWarshall.Solve(graph);
		}
	}
}