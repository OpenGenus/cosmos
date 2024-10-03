// Part of Cosmos by OpenGenus Foundation
// Author: Igor Antun
// Github: @IgorAntun
// Function to find area of a triangle using three different vertices.

/* Function */
const area_of_triangle = (a, b, c) =>
  Math.abs(
    a.x * b.y + a.y * c.x + b.x * c.y - a.y * b.x - a.x * c.y - b.y * c.x
  ) / 2;

/* Test */
area_of_triangle({ x: 3, y: 50 }, { x: -6, y: 8 }, { x: 8, y: 0 }); // should return 330
