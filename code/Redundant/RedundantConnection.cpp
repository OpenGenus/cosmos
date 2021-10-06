#include <bits/stdc++.h>
using namespace std;
void print_vector(vector v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << v[i] << ", ";
   }
   cout << "]"<<endl;
}
const int N = 1000;
class Solution {
public:
   int parent[N + 5];
   int rank[N + 5];
   int getParent(int n){
      if (parent[n] == -1)
         return n;
      return parent[n] = getParent(parent[n]);
   }
   bool unionn(int a, int b){
      int pa = getParent(a);
      int pb = getParent(b);
      if (pa == pb)
         return false;
      if (rank[pa] > rank[pb]) {
         rank[pa] += rank[pb];
         parent[pb] = pa;
      }
      else {
         rank[pb] += rank[pa];
         parent[pa] = pb;
      }
      return true;
   }
   vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      int n = edges.size();
      for (int i = 0; i < n; i++) {
         parent[edges[i][0]] = parent[edges[i][1]] = -1;
         rank[edges[i][0]] = rank[edges[i][1]] = 1;
      }
      vector<int> ans;
      for (int i = 0; i < n; i++) {
         int u = edges[i][0];
         int v = edges[i][1];
         if (!unionn(u, v)) {
            ans = edges[i];
         }
      }
      return ans;
   }
};
main(){
   Solution ob;
   vector<vector<int>> v = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
   print_vector(ob.findRedundantConnection(v));
}
