// dynamic programming | box stacking | C++
// Part of Cosmos by OpenGenus Foundation

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Struct to represent the boxes
struct Box
{

    int height, width, length;

    // Initializer
    Box()
    {
    }
    Box(int h, int w, int l) : height(h), width(w), length(l)
    {
    }

    // Return the area of the box
    int area() const
    {
        return this->width * this->length;
    }

    // Return true if current box can be put
    // on the other, and false otherwise
    bool fitOn(const struct Box other)
    {
        return min(this->width, this->length) < min(other.width, other.length) &&
               max(this->width, this->length) < max(other.width, other.length);
    }

    // Compare the boxes based on their area
    bool operator<(const struct Box other) const
    {
        return this->area() < other.area();
    }
};

/**
 *  Return the maximum height that can be
 *  obtained by stacking the available boxes.
 *  Time complexity: O(n^2), n = size of boxes
 */
int maxHeight(vector<Box> boxes)
{

    // Get the rotations of current boxes
    for (int i = 0, n = boxes.size(); i < n; ++i)
    {
        boxes.push_back(Box(boxes[i].width, boxes[i].length, boxes[i].height));
        boxes.push_back(Box(boxes[i].length, boxes[i].height, boxes[i].width));
    }

    // Sort the boxes by decreasing order of area
    sort(boxes.rbegin(), boxes.rend());

    int dp[boxes.size()], ans = 0;

    // Find the longest increasing sequence of boxes
    for (size_t i = 0; i < boxes.size(); ++i)
    {
        dp[i] = boxes[i].height;
        for (size_t j = 0; j < i; ++j)
            if (boxes[i].fitOn(boxes[j]))
                dp[i] = max(dp[i], boxes[i].height + dp[j]);
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main()
{

    // Using C++11 initializer
    vector<Box> boxes1 = {
        Box(4, 6, 7),
        Box(1, 2, 3),
        Box(4, 5, 6),
        Box(10, 12, 32)
    };

    vector<Box> boxes2 = {
        Box(1, 2, 3),
        Box(4, 5, 6),
        Box(3, 4, 1)
    };

    cout << maxHeight(boxes1) << endl; // Expected output: 60
    cout << maxHeight(boxes2) << endl; // Expected output: 15
}
