// Return the polygon's area in "square units."
// The value will be negative if the polygon is
// oriented clockwise.
private float SignedPolygonArea()
{
    // Add the first point to the end.
    int num_points = Points.Length;
    PointF[] pts = new PointF[num_points + 1];
    Points.CopyTo(pts, 0);
    pts[num_points] = Points[0];

    // Get the areas.
    float area = 0;
    for (int i = 0; i < num_points; i++)
    {
        area +=
            (pts[i + 1].X - pts[i].X) *
            (pts[i + 1].Y + pts[i].Y) / 2;
    }

    // Return the result.
    return area;
}

// Return the polygon's area in "square units."
public float PolygonArea()
{
    // Return the absolute value of the signed area.
    // The signed area is negative if the polyogn is
    // oriented clockwise.
    return Math.Abs(SignedPolygonArea());
}