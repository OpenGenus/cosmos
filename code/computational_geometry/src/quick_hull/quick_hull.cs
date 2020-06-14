using System;
using System.Collections.Generic;

namespace Cosmos
{
	public static class Quickhull
	{
		public readonly struct Point : IEquatable<Point>
		{
			public Point(float x, float y)
			{
				X = x;
				Y = y;
			}

			public float X { get; }
			public float Y { get; }

			public static bool operator ==(Point a, Point b)
			{
				return Math.Abs(a.X - b.X) < float.Epsilon && Math.Abs(a.Y - b.Y) < float.Epsilon;
			}

			public static bool operator !=(Point a, Point b)
			{
				return !(a == b);
			}

			public static float Dot(Point a, Point b)
			{
				return a.X * b.X + a.Y * b.Y;
			}

			public static float Distance(Point a, Point b, Point c)
			{
				return Math.Abs((b.X - a.X) * (a.Y - c.Y) - (b.Y - a.Y) * (a.X - c.X));
			}

			public override bool Equals(object obj)
			{
				return obj is Point other && Equals(other);
			}

			public bool Equals(Point other)
			{
				return X.Equals(other.X) && Y.Equals(other.Y);
			}

			public override int GetHashCode()
			{
				return HashCode.Combine(X, Y);
			}

			public override string ToString()
			{
				return $"({X}, {Y})";
			}
		}


		private static void FindHull(Point a, Point b, ref List<Point> input, ref List<Point> output)
		{
			var maxDistance = -1f;
			var c = new Point(0, 0);

			foreach (var point in input)
			{
				if (point == a || point == b) continue;
				
				if (!(Point.Dot(new Point(point.X - a.X, point.Y - a.Y), new Point(-(b.Y - a.Y), b.X - a.X)) < 0))
				{
					var distance = Point.Distance(a, b, point);
					if (distance > maxDistance)
					{
						c = point;
						maxDistance = distance;
					}
				}
			}
			
			if (Math.Abs(maxDistance - (-1)) < float.Epsilon) return;
			output.Add(c);
			FindHull(a, c, ref input, ref output);
			FindHull(c, b, ref input, ref output);
		}

		public static IEnumerable<Point> QuickhullSolver(List<Point> input)
		{
			var output = new List<Point>();

			if (input.Count < 3) return output;
			
			var a = new Point(0, 0);
			var b = new Point(0, 0);
			foreach (var point in input)
			{
				if (point.X < a.X)
				{
					a = point;
				}

				if (point.X > b.X)
				{
					b = point;
				}
			}
			
			output.Add(a);
			output.Add(b);
			
			FindHull(a, b, ref input, ref output);
			FindHull(b, a, ref input, ref output);

			return output;
		}
	}
}