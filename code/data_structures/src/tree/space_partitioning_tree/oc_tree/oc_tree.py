# Part of Cosmos by OpenGenus Foundation


class Octant:
    """
    UP: Y positive.
    DOWN: Y negative.
    FRONT: Z positive.
    BACK: Z negative.
    RIGHT: X positive.
    LEFT: X negative.
    """

    UP_FRONT_LEFT = 0
    UP_FRONT_RIGHT = 1
    UP_BACK_LEFT = 2
    UP_BACK_RIGHT = 3
    DOWN_FRONT_LEFT = 4
    DOWN_FRONT_RIGHT = 5
    DOWN_BACK_LEFT = 6
    DOWN_BACK_RIGHT = 7
    OUT_OF_BOUNDS = -1


class Point3D:
    """
    3d point representation.
          +----+
         /    /| Y
        +----+ |
        |    | +
        |    |/ Z
        +----+
          X
    """

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z


class Dimension:
    """
    Dimension representation.
    """

    def __init__(self, width, height, depth):
        self.width = width
        self.height = height
        self.depth = depth


class Box:
    """
    Box Class represents boundaries.
    """

    def __init__(self, x, y, z, width, height, depth):
        self.center = Point3D(x, y, z)
        self.dimension = Dimension(width, height, depth)
        self.minPos = Point3D(x - width / 2, y - height / 2, z - depth / 2)
        self.maxPos = Point3D(x + width / 2, y + height / 2, z + depth / 2)

    def contains(self, point3d):
        """
        Check if box contains a point.
        3D collision detection.
        https://developer.mozilla.org/en-US/docs/Games/Techniques/3D_collision_detection#point_vs._aabb
        """
        return (
            point3d.x >= self.minPos.x
            and point3d.x <= self.maxPos.x
            and point3d.y >= self.minPos.y
            and point3d.y <= self.maxPos.y
            and point3d.z >= self.minPos.z
            and point3d.z <= self.maxPos.z
        )

    def intersect(self, box):
        """
        Check if 2 boxes intersect.
        3D collision detection.
        https://developer.mozilla.org/en-US/docs/Games/Techniques/3D_collision_detection#aabb_vs._aabb
        """
        return (
            self.minPos.x <= box.maxPos.x
            and self.maxPos.x >= box.minPos.x
            and self.minPos.y <= box.maxPos.y
            and self.maxPos.y >= box.minPos.y
            and self.minPos.z <= box.maxPos.z
            and self.maxPos.z >= box.minPos.z
        )

    def find_octant(self, point3d):
        """
        Find which octant contains a specific point.
        """
        print(f"POINT x:{point3d.x} y:{point3d.y} z:{point3d.z} IN ", end="")

        if (
            self.center.x - self.dimension.width / 2 <= point3d.x
            and self.center.x >= point3d.x
            and self.center.y + self.dimension.height / 2 >= point3d.y
            and self.center.y <= point3d.y
            and self.center.z + self.dimension.depth / 2 >= point3d.z
            and self.center.z <= point3d.z
        ):
            print("UP FRONT LEFT")
            return Octant.UP_FRONT_LEFT

        if (
            self.center.x + self.dimension.width / 2 >= point3d.x
            and self.center.x <= point3d.x
            and self.center.y + self.dimension.height / 2 >= point3d.y
            and self.center.y <= point3d.y
            and self.center.z + self.dimension.depth / 2 >= point3d.z
            and self.center.z <= point3d.z
        ):
            print("UP FRONT RIGHT")
            return Octant.UP_FRONT_RIGHT

        if (
            self.center.x - self.dimension.width / 2 <= point3d.x
            and self.center.x >= point3d.x
            and self.center.y + self.dimension.height / 2 >= point3d.y
            and self.center.y <= point3d.y
            and self.center.z - self.dimension.depth / 2 <= point3d.z
            and self.center.z >= point3d.z
        ):
            print("UP BACK LEFT")
            return Octant.UP_BACK_LEFT

        if (
            self.center.x + self.dimension.width / 2 >= point3d.x
            and self.center.x <= point3d.x
            and self.center.y + self.dimension.height / 2 >= point3d.y
            and self.center.y <= point3d.y
            and self.center.z - self.dimension.depth / 2 <= point3d.z
            and self.center.z >= point3d.z
        ):
            print("UP BACK RIGHT")
            return Octant.UP_BACK_RIGHT

        if (
            self.center.x - self.dimension.width / 2 <= point3d.x
            and self.center.x >= point3d.x
            and self.center.y - self.dimension.height / 2 <= point3d.y
            and self.center.y >= point3d.y
            and self.center.z + self.dimension.depth / 2 >= point3d.z
            and self.center.z <= point3d.z
        ):
            print("DOWN FRONT LEFT")
            return Octant.DOWN_FRONT_LEFT

        if (
            self.center.x + self.dimension.width / 2 >= point3d.x
            and self.center.x <= point3d.x
            and self.center.y - self.dimension.height / 2 <= point3d.y
            and self.center.y >= point3d.y
            and self.center.z + self.dimension.depth / 2 >= point3d.z
            and self.center.z <= point3d.z
        ):
            print("DOWN FRONT RIGHT")
            return Octant.DOWN_FRONT_RIGHT

        if (
            self.center.x - self.dimension.width / 2 <= point3d.x
            and self.center.x >= point3d.x
            and self.center.y - self.dimension.height / 2 <= point3d.y
            and self.center.y >= point3d.y
            and self.center.z - self.dimension.depth / 2 <= point3d.z
            and self.center.z >= point3d.z
        ):
            print("DOWN BACK LEFT")
            return Octant.DOWN_BACK_LEFT

        if (
            self.center.x + self.dimension.width / 2 >= point3d.x
            and self.center.x <= point3d.x
            and self.center.y - self.dimension.height / 2 <= point3d.y
            and self.center.y >= point3d.y
            and self.center.z - self.dimension.depth / 2 <= point3d.z
            and self.center.z >= point3d.z
        ):
            print("DOWN BACK RIGHT")
            return Octant.DOWN_BACK_RIGHT

        print("NOT IN BOX")
        return Octant.OUT_OF_BOUNDS


class OctreeNode:
    """
    Octree node:
    - 8 octants, 8 children
    - It stores Point3D (a specific capacity)
    """

    def __init__(self, box, capacity):
        self.children = [None] * 8  # each node has 8 children
        self.values = [None] * capacity
        self.boundary = box
        self.divided = False
        self.size = 0

    def subdivide(self):
        """
        When the node is full, each octant (children) is initialized
        with a new center, capacity is the same.
        """
        self.divided = True
        w = self.boundary.dimension.width / 2
        h = self.boundary.dimension.height / 2
        d = self.boundary.dimension.depth / 2
        x = self.boundary.center.x
        y = self.boundary.center.y
        z = self.boundary.center.z
        capacity = len(self.values)

        # UPPER PART
        self.children[Octant.UP_FRONT_LEFT] = OctreeNode(
            Box(x - w / 2, y + h / 2, z + d / 2, w, h, d), capacity
        )
        self.children[Octant.UP_FRONT_RIGHT] = OctreeNode(
            Box(x + w / 2, y + h / 2, z + d / 2, w, h, d), capacity
        )
        self.children[Octant.UP_BACK_LEFT] = OctreeNode(
            Box(x - w / 2, y + h / 2, z - d / 2, w, h, d), capacity
        )
        self.children[Octant.UP_BACK_RIGHT] = OctreeNode(
            Box(x + w / 2, y + h / 2, z - d / 2, w, h, d), capacity
        )

        # LOWER PART
        self.children[Octant.DOWN_FRONT_LEFT] = OctreeNode(
            Box(x - w / 2, y - h / 2, z + d / 2, w, h, d), capacity
        )
        self.children[Octant.DOWN_FRONT_RIGHT] = OctreeNode(
            Box(x + w / 2, y - h / 2, z + d / 2, w, h, d), capacity
        )
        self.children[Octant.DOWN_BACK_LEFT] = OctreeNode(
            Box(x - w / 2, y - h / 2, z - d / 2, w, h, d), capacity
        )
        self.children[Octant.DOWN_BACK_RIGHT] = OctreeNode(
            Box(x + w / 2, y - h / 2, z - d / 2, w, h, d), capacity
        )


class Octree:
    def __init__(self, box, capacity):
        self.root = OctreeNode(box, capacity)
        self.capacity = capacity

    def insert(self, point3d):
        """
        Each node is divided in 8 octants and has a capacity.
        At first, root node octants are empty
        - If a point is not inside the boudaries, it is not inserted
        - If node is not full the we insert it
        - Otherwise we subdive the node, find which octant contains
            the point and then insert the point
        """

        def insert_recursive(point3d, node):
            if node.boundary.contains(point3d) == False:
                print(f"NOT INSERTED x:{point3d.x} y:{point3d.y} z:{point3d.z}")
                return

            if node.size < self.capacity:
                node.values[node.size] = point3d
                node.size += 1
            else:
                node.subdivide()
                octant = node.boundary.find_octant(point3d)
                node = node.children[octant]
                insert_recursive(point3d, node)

        insert_recursive(point3d, self.root)


if __name__ == "__main__":
    box = Box(x=0, y=0, z=0, width=2, height=2, depth=2)
    octree = Octree(box, capacity=4)  # root

    # Example
    # center=(x=0,y=0,z=0)
    #        +--------+
    #       /        /|
    #      /        / | height = 2
    #     +--------+  |     Y
    #     |        |  |
    #     | (0,0,0)|  +
    #     |    *   | / depth=2
    #     |        |/    Z
    #     +--------+
    #     width = 2
    #          X

    # Points to be inserted
    points = [
        # 4 initial nodes, Octree does not subdivides
        Point3D(-1, 1, 1),
        Point3D(1, 1, 1),
        Point3D(-1, 1, -1),
        Point3D(1, 1, -1),
        # DOWN, Octree subdivides because node is Full
        Point3D(-1, -1, 1),  # (Octant) DOWN FRONT LEFT
        Point3D(1, -1, 1),  # (Octant) DOWN FRONT RIGHT
        Point3D(-1, -1, -1),  # (Octant) DOWN BACK LEFT
        Point3D(1, -1, -1),  # (Octant) DOWN BACK RIGHT
        Point3D(2, 2, 2),  # This point is not inserted
    ]

    for p in points:
        octree.insert(p)

    # Octants
    print("Octants:")
    point = Point3D(x=-1, y=1, z=1)
    assert box.find_octant(point) == Octant.UP_FRONT_LEFT, "should be UP_FRONT_LEFT"
    point = Point3D(x=1, y=1, z=1)
    assert box.find_octant(point) == Octant.UP_FRONT_RIGHT, "should be UP_FRONT_RIGHT"
    point = Point3D(x=-1, y=1, z=-1)
    assert box.find_octant(point) == Octant.UP_BACK_LEFT, "should be UP_BACK_LEFT"
    point = Point3D(x=1, y=1, z=-1)
    assert box.find_octant(point) == Octant.UP_BACK_RIGHT, "should be UP_BACK_RIGHT"
    point = Point3D(x=-1, y=-1, z=1)
    assert box.find_octant(point) == Octant.DOWN_FRONT_LEFT, "should be DOWN_FRONT_LEFT"
    point = Point3D(x=1, y=-1, z=1)
    assert (
        box.find_octant(point) == Octant.DOWN_FRONT_RIGHT
    ), "should be DOWN_FRONT_RIGHT"
    point = Point3D(x=-1, y=-1, z=-1)
    assert box.find_octant(point) == Octant.DOWN_BACK_LEFT, "should be DOWN_BACK_LEFT"
    point = Point3D(x=1, y=-1, z=-1)
    assert box.find_octant(point) == Octant.DOWN_BACK_RIGHT, "should be DOWN_BACK_RIGHT"

    # Intersection
    assert (
        Box(0, 0, 0, 1, 1, 1).intersect(Box(0.5, 0.5, 0.5, 1, 1, 1)) == True
    ), "Should Intersect!"
    assert (
        Box(1, 1, 1, 1, 1, 1).intersect(Box(1, 1, 1, 1, 1, 1)) == True
    ), "Should Intersect!"
    assert (
        Box(0, 0, 0, 1, 1, 1).intersect(Box(2, 2, 2, 2, 2, 2)) == False
    ), "Should NOT Intersect!"
