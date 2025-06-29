#include <iostream>
#include <vector>

class SegmentTree {
public:
    SegmentTree(const std::vector<int>& data);

    void update(int index, int value);
    int query(int left, int right);

private:
    void build(int node, int start, int end);
    void updateUtil(int node, int start, int end, int index, int value);
    int queryUtil(int node, int start, int end, int left, int right);

    int size_;
    std::vector<int> tree_;
    std::vector<int> data_;
};

SegmentTree::SegmentTree(const std::vector<int>& data)
    : size_{static_cast<int>(data.size())}, tree_(4 * size_), data_{data} {
    build(1, 0, size_ - 1);
}

void SegmentTree::build(int node, int start, int end) {
    if (start == end) {
        tree_[node] = data_[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree_[node] = tree_[2 * node] + tree_[2 * node + 1];
    }
}

void SegmentTree::update(int index, int value) {
    updateUtil(1, 0, size_ - 1, index, value);
}

void SegmentTree::updateUtil(int node, int start, int end, int index, int value) {
    if (start == end) {
        data_[index] = value;
        tree_[node] = value;
    } else {
        int mid = (start + end) / 2;
        if (index <= mid) {
            updateUtil(2 * node, start, mid, index, value);
        } else {
            updateUtil(2 * node + 1, mid + 1, end, index, value);
        }
        tree_[node] = tree_[2 * node] + tree_[2 * node + 1];
    }
}

int SegmentTree::query(int left, int right) {
    return queryUtil(1, 0, size_ - 1, left, right);
}

int SegmentTree::queryUtil(int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree_[node];
    }

    int mid = (start + end) / 2;
    int sumLeft = queryUtil(2 * node, start, mid, left, right);
    int sumRight = queryUtil(2 * node + 1, mid + 1, end, left, right);
    return sumLeft + sumRight;
}

int main() {
    std::vector<int> data{1, 3, 5, 7, 9, 11};
    SegmentTree st(data);

    std::cout << "Sum [1, 3]: " << st.query(1, 3) << "\n";
    st.update(1, 10);
    std::cout << "Sum [1, 3] after update: " << st.query(1, 3) << "\n";

    return 0;
}