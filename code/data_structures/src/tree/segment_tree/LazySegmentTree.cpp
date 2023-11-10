// There are generally three main function for lazy propagation in segment tree
// Lazy propagation is used when we have range update query too, without it only point 
// update is possible.

// Build function

// THE SEGMENT TREE WRITTEN HERE IS FOR GETTING SUM , FOR MINIMUM, MAXIMUM, XOR AND DISTINCT ELEMENT COUNT RESPECTIVE SEGMENT TREES 
// CAN BE MADE JUST BY REPLACING A FEW LINES

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5;

int seg[4*N],lazy[4*N];

vector<int> arr;

void build(int node, int st, int en) {
  if (st == en) {
    // left node ,string the single array element
    seg[node] = arr[st];
    return;
  }

  int mid = (st + en) / 2;

  // recursively call for left child
  build(2 * node, st, mid);

  // recursively call for the right child
  build(2 * node + 1, mid + 1, en);

  // Updating the parent with the values of the left and right child.
  seg[node] = seg[2 * node] + seg[2 * node + 1];
}

//Above, every node represents the sum of both subtrees below it. Build function is called once per array, and the time complexity of build() is O(N).

// Update Operation function

void update(int node, int st, int en, int l, int r, int val) {
  if (lazy[node] != 0) // if node is lazy then update it
  {
    seg[node] += (en - st + 1) * lazy[node];

    if (st != en) // if its children exist then mark them lazy
    {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0; // No longer lazy
  }
  if ((en < l) || (st > r)) // case 1
  {
    return;
  }
  if (st >= l && en <= r) // case 2
  {
    seg[node] += (en - st + 1) * val;
    if (st != en) {
      lazy[2 * node] += val; // mark its children lazy
      lazy[2 * node + 1] += val;
    }
    return;
  }

  // case 3
  int mid = (st + en) / 2;

  // recursively call for updating left child
  update(2 * node, st, mid, l, r, val);
  // recursively call for updating right child
  update(2 * node + 1, mid + 1, en, l, r, val);

  // Updating the parent with the values of the left and right child.
  seg[node] = (seg[2 * node] + seg[2 * node + 1]);
}

//Here above we take care of three cases for base case:

// Segment lies outside the query range: in this case, we can just simply return back and terminate the call.
// Segment lies fully inside the query range: in this case, we simply update the current node and mark the children lazy.
// If they intersect partially, then we all update for both the child and change the values in them.

// Query function

int query(int node, int st, int en, int l, int r) {
  /*If the node is lazy, update it*/
  if (lazy[node] != 0) {

    seg[node] += (en - st + 1) * lazy[node];
    if (st != en) //Check if the child exist
    {
      // mark both the child lazy
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    // no longer lazy
    lazy[node] = 0;
  }
  // case 1
  if (en < l || st > r) {
    return 0;
  }

  // case 2
  if ((l <= st) && (en <= r)) {
    return seg[node];
  }
  int mid = (st + en) / 2;

  //query left child 
  ll q1 = query(2 * node, st, mid, l, r);

  // query right child
  ll q2 = query(2 * node + 1, mid + 1, en, l, r);

  return (q1 + q2);
}

int main(){
    int n;
    cin >> n;
    arr=vector<int>(n+1);

    for(int i=1;i<=n;i++)cin >> arr[i];

    memset(seg,0,sizeof seg);
    memset(lazy,0,sizeof lazy);

    build(1,1,n);


    return 0;
}

// As compared to non-lazy code only lazy code in base case is added. Also one should remember the kazy implementation only as it can
// help u solve in non-lazy case too.

// Here the insertion, query both take O(logn) time.