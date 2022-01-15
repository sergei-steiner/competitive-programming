#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/number-of-islands-ii

class Solution {
public:
    class DSU {
    public:
       int n;
       vector<int> parent;
       int count = 0;
        
       DSU(int n)
           : n(n)
           , parent(n, -1)
       {
       }

       void Set(int i) {
            if (IsSet(i)) return;
            parent[i] = i;
            ++count;
       }
       bool IsSet(int i) {
           return parent[i] !=  -1;
       }
       size_t FindSet(size_t v) {
           if (v == parent[v]) return v;
           return parent[v] = FindSet(parent[v]);
       }

       void Union(size_t a, size_t b) {
           a = FindSet(a);
           b = FindSet(b);
           if (a != b) --count;
           if (rand() & 1) swap(a, b);
           parent[b] = a;
       }
        
       int Count() const {
           return count;
       }

    };

    vector<int> numIslands2(int n, int m, vector<vector<int>>& positions) {
        vector<int> ans;
        DSU dsu(n * m);
        for (auto v : positions) {
            int i = v[0];
            int j = v[1];
            dsu. Set(i * m + j);
            if (i > 0 && dsu.IsSet((i - 1) * m + j)) dsu.Union(i * m + j, (i - 1) * m + j);
            if (i + 1 < n && dsu.IsSet((i + 1) * m + j)) dsu.Union(i * m + j, (i + 1) * m + j);
            if (j > 0 && dsu.IsSet(i * m + j - 1)) dsu.Union(i * m + j, i * m + j - 1);
            if (j + 1 < m && dsu.IsSet(i * m + j + 1)) dsu.Union(i * m + j, i * m + j + 1);
            ans.push_back(dsu.Count());
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
