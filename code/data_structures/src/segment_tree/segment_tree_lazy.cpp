#include <iostream>
#include <vector>

class SegmentTreeLazy {
public:
    SegmentTreeLazy(const std::vector<int>& data);

    void updateRange(int l, int r, int val);
    int queryRange(int l, int r);

private:
    void build(int node, int start, int end);
    void updateRangeUtil(int node, int start, int end, int l, int r, int val);
    int queryRangeUtil(int node, int start, int end, int l, int r);

    int size_;
    std::vector<int> tree_;
    std::vector<int> lazy_;
    std::vector<int> data_;
};

SegmentTreeLazy::SegmentTreeLazy(const std::vector<int>& data)
    : size_{static_cast<int>(data.size())},
      tree_(4 * size_),
      lazy_(4 * size_, 0),
      data_{data} {
    build(1, 0, size_ - 1);
}

void SegmentTreeLazy::build(int node, int start, int end) {
    if (start == end) {
        tree_[node] = data_[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree_[node] = tree_[2 * node] + tree_[2 * node + 1];
    }
}

void SegmentTreeLazy::updateRange(int l, int r, int val) {
    updateRangeUtil(1, 0, size_ - 1, l, r, val);
}

void SegmentTreeLazy::updateRangeUtil(int node, int start, int end, int l, int r, int val) {
    if (lazy_[node] != 0) {
        tree_[node] += (end - start + 1) * lazy_[node];
        if (start != end) {
            lazy_[2 * node] += lazy_[node];
            lazy_[2 * node + 1] += lazy_[node];
        }
        lazy_[node] = 0;
    }

    if (start > end || start > r || end < l) {
        return;
    }

    if (start >= l && end <= r) {
        tree_[node] += (end - start + 1) * val;
        if (start != end) {
            lazy_[2 * node] += val;
            lazy_[2 * node + 1] += val;
        }
        return;
    }

    int mid = (start + end) / 2;
    updateRangeUtil(2 * node, start, mid, l, r, val);
    updateRangeUtil(2 * node + 1, mid + 1, end, l, r, val);
    tree_[node] = tree_[2 * node] + tree_[2 * node + 1];
}

int SegmentTreeLazy::queryRange(int l, int r) {
    return queryRangeUtil(1, 0, size_ - 1, l, r);
}

int SegmentTreeLazy::queryRangeUtil(int node, int start, int end, int l, int r) {
    if (start > end || start > r || end < l) {
        return 0;
    }

    if (lazy_[node] != 0) {
        tree_[node] += (end - start + 1) * lazy_[node];
        if (start != end) {
            lazy_[2 * node] += lazy_[node];
            lazy_[2 * node + 1] += lazy_[node];
        }
        lazy_[node] = 0;
    }

    if (start >= l && end <= r) {
        return tree_[node];
    }

    int mid = (start + end) / 2;
    int p1 = queryRangeUtil(2 * node, start, mid, l, r);
    int p2 = queryRangeUtil(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
}

int main() {
    std::vector<int> data{1, 3, 5, 7, 9, 11};
    SegmentTreeLazy st(data);

    std::cout << "Sum [1, 3]: " << st.queryRange(1, 3) << "\n";
    st.updateRange(1, 5, 10);
    std::cout << "Sum [1, 3] after update: " << st.queryRange(1, 3) << "\n";

    return 0;
}