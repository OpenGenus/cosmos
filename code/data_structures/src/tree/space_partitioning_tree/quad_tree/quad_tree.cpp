// Part of Cosmos by OpenGenus Foundation
#include "iostream"
#include "vector"

#define ll long long
using namespace std;

struct Rectangle {
    float x;
    float y;
    float h;
    float w;
};

struct Point {
    float x;
    float y;
};


class QuadTree {
    Rectangle boundary{};
    vector<Point> arr;
    QuadTree *NorthEast;
    QuadTree *NorthWest;
    QuadTree *SouthEast;
    QuadTree *SouthWest;
    bool divided;
    int bucket;
public:
    QuadTree(Rectangle b, int lim) {
        boundary = b;
        bucket = lim; // Number of Points that can be included in one quadrant.
        divided = false;
        NorthEast = nullptr;
        NorthWest = nullptr;
        SouthEast = nullptr;
        SouthWest = nullptr;
    }

    [[nodiscard]] bool contains(Point point) const {
        if (((point.x >= boundary.x - boundary.w) and (point.x <= boundary.x + boundary.w)) and
            ((point.y <= boundary.y + boundary.h) and (point.y >= boundary.y - boundary.h))) {
            return true;
        }
        return false;
    }


    void SubDivide() {
        float x = boundary.x;
        float y = boundary.y;
        float h = boundary.h;
        float w = boundary.w;
        Rectangle nE{x + (w / 2), y + (h / 2), w / 2, h / 2};
        NorthEast = new QuadTree(nE, bucket);
        Rectangle nW{x - (w / 2), y + (h / 2), w / 2, h / 2};
        NorthWest = new QuadTree(nW, bucket);
        Rectangle sE{x + (w / 2), y - (h / 2), w / 2, h / 2};
        SouthEast = new QuadTree(sE, bucket);
        Rectangle sW{x - (w / 2), y - (h / 2), w / 2, h / 2};
        SouthWest = new QuadTree(sW, bucket);
    }

    bool insert(Point point) {
        if (!contains(point)) {
            return false;
        }

        if (arr.size() < bucket) {
            arr.push_back(point);
            return true;
        }

        if (!divided) {
            SubDivide();
            divided = true;
        }
        if (NorthEast->insert(point)) return true;
        if (NorthWest->insert(point)) return true;
        if (SouthEast->insert(point)) return true;
        if (SouthWest->insert(point)) return true;

        return false;
    }

    void traverse(QuadTree qt) {
        if (qt.arr.empty()) {
            return;
        }
        cout << qt.arr[0].x << " " << qt.arr[0].y << "\n";
        if (qt.NorthEast != nullptr) {
            QuadTree temp3 = *qt.NorthEast;
            traverse(temp3);
        }
        if (qt.NorthWest != nullptr) {
            QuadTree temp4 = *qt.NorthWest;
            traverse(temp4);
        }
        if (qt.SouthWest != nullptr) {
            QuadTree temp1 = *qt.SouthWest;
            traverse(temp1);
        }
        if (qt.SouthEast != nullptr) {
            QuadTree temp2 = *qt.SouthEast;
            traverse(temp2);
        }
    }


};

int main() {
    Rectangle boundary{0, 0, 500,
                       500}; //Any inserted coordinate => (x, y) should satisfy => (boundary.x - boundary.w <= x <= boundary.x + boundary.w) and (boundary.y - boundary.h <= y <= boundary.y + boundary.h)
    QuadTree QT = QuadTree(boundary, 1);
    QT.insert(Point{0, 0});
    QT.insert(Point{1, 1});
    QT.insert(Point{-1, -1});
    QT.insert(Point{1, -1});
    QT.insert(Point{-1, 1});
    QT.insert(Point{2, 2});
    QT.insert(Point{-2, 2});
    QT.insert(Point{2, -2});
    QT.insert(Point{-2, -2});
    QT.traverse(QT);
    return 0;
}
