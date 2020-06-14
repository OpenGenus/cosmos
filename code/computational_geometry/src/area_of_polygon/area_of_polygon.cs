namespace Cosmos
{
	public static class AreaOfPolygon
	{
		public readonly struct Point
		{
			public Point(float x, float y)
			{
				X = x;
				Y = y;
			}

			public float X { get; }
			public float Y { get; }
		}
		
		public static double Calculate(Point a, Point b, Point c)
		{
			double result = ((a.X - b.X) * (c.Y - b.Y) - (a.Y - b.Y) * (c.X - b.X)) / 2;
			return (result < 0) ? (-result) : result;
		}
	}
}