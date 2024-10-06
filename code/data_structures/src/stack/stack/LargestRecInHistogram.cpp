#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;  // Stack to store indices of the bars
    int maxArea = 0;  // Variable to store the maximum area
    int n = heights.size();

    // Traverse all bars of the histogram
    for (int i = 0; i < n; i++) {
        // If this bar is lower than the bar at the stack's top, pop the stack and calculate area
        while (!s.empty() && heights[s.top()] > heights[i]) {
            int h = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, h * width);
        }
        s.push(i);  // Push the current bar index onto the stack
    }

    // Process the remaining bars in the stack
    while (!s.empty()) {
        int h = heights[s.top()];
        s.pop();
        int width = s.empty() ? n : n - s.top() - 1;
        maxArea = max(maxArea, h * width);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = largestRectangleArea(heights);
    cout << "The largest rectangle area is: " << result << endl;
    return 0;
}
