//Time Complexity : O((n+q)*sqrt(n))
#include <bits/stdc++.h>

/* Part of Cosmos by OpenGenus Foundation */
using namespace std;
typedef struct query {
    int l;
    int r;
    int p;
}query;

int N, Q, size;
long long answers[100005];
int BLOCK_SIZE;
int A[100005];
int current[100005];
query queries[100005];

bool mo_cmp(const query x, const query y) {
    int block_x = x.l / BLOCK_SIZE;
    int block_y = y.l / BLOCK_SIZE;
    if(block_x != block_y) return block_x < block_y;
    return x.r < y.r;
}

// add element x to current mo-range
void add(int x) {
    if(current[x] == 0) {
        ++size;
    }
    ++current[x];
}

// remove element x from current mo-range
void remove(int x) {
    --current[x];
    if(current[x] == 0) {
        --size;
    }
}

int main() {
    // input number of array elements and number of queries
    cin >> N >> Q;
    BLOCK_SIZE = (int)(sqrt(N));

    // input array elements
    for(int i = 0; i < N; i++)
        cin >> A[i];

    for(int i = 0; i < Q; i++) {
        int l, r, p = i;

        // l, r, p are zero-indexed
        cin >> l >> r;
        queries[i].l = l;
        queries[i].r = r;
        queries[i].p = p;
    }

    sort(queries, queries + Q, mo_cmp);
    int mo_left = 0, mo_right = -1;
    for(int i = 0; i < Q; i++) {
        int left = queries[i].l;
        int right = queries[i].r;

        // move mo-range to solve for range [left, right]
        // and calculate number of distinct elements in this range
        while(mo_right < right) {
            mo_right++;
            add(A[mo_right]);
        }
        while(mo_right > right) {
            remove(A[mo_right]);
            mo_right--;
        }

        while(mo_left < left) {
            remove(A[mo_left]);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            add(A[mo_left]);
        }

        answers[queries[i].p] = size;
    }

    for(int i = 0; i < Q; i++) {
        cout << answers[i] << "\n";
    }
}
