#include <iostream>
// Part of Cosmos by OpenGenus Foundation
struct Vector
{
    int x;
    int y;
};

struct Shape
{
    Vector center;
    int width;
    int height;
};

bool checkAABBCollision(Shape &a, Shape &b)
{
    // change '<' to '<=' if you want to include edge touching as a collision
    return (abs(a.center.x - b.center.x) * 2 < (a.width + b.width)) &&
           (abs(a.center.y - b.center.y) * 2 < (a.height + b.height));
}

int main()
{
    Shape a = { Vector {3, 3}, 4, 5 };
    Shape b = { Vector {9, 3}, 6, 4 };

    // 0 - no collision
    std::cout << checkAABBCollision(a, b) << std::endl;

    a = { Vector {3, 3}, 4, 5 };
    b = { Vector {7, 3}, 6, 4 };

    // 1 - collision
    std::cout << checkAABBCollision(a, b) << std::endl;

    a = { Vector {3, 10}, 4, 6 };
    b = { Vector {3, 5}, 6, 6 };

    // 1 - collision
    std::cout << checkAABBCollision(a, b) << std::endl;
}
