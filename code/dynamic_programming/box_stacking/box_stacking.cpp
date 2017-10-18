#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Box {
  
    int height, width, length;
    
    Box() {}
    Box(int h, int w, int l): height(h), width(w), length(l) {}
    
    int area() const {
        return this->width * this->length;
    }
    
    bool fitOn(const struct Box other) {
        return min(this->width, this->length) < min(other.width, other.length) &&
               max(this->width, this->length) < max(other.width, other.length);
    }
    
    bool operator<(const struct Box other) const {
        return this->area() < other.area();
    }
};

int maxHeight(vector<Box> boxes) {
  
    for(int i = 0, n = boxes.size(); i < n; ++i) {
        boxes.push_back(Box(boxes[i].width, boxes[i].length, boxes[i].height));
        boxes.push_back(Box(boxes[i].length, boxes[i].height, boxes[i].width));
    }
    
    sort(boxes.rbegin(), boxes.rend());
    
    int dp[boxes.size()], ans = 0;
    
    for(int i = 0; i < boxes.size(); ++i) {
        dp[i] = boxes[i].height;
        for(int j = 0; j < i; ++j)
            if(boxes[i].fitOn(boxes[j]))
                dp[i] = max(dp[i], boxes[i].height + dp[j]);
        ans = max(ans, dp[i]);
    }
    
    return ans;
}

int main() {
  
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
