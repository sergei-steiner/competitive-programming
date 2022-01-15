#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/connecting-cities-with-minimum-cost
// https://neerc.ifmo.ru/wiki/index.php?title=Алгоритм_Краскала
// O(ElogE)

class Solution {
public:

    int n;
    vector<int> p;

    int findset(int v) {
        if (v == p[v]) return v;
        return p[v] = findset(p[v]);
    }

    void unionsets(int u, int v) {
        u = findset(u);
        v = findset(v);
        if (u == v) return;
        if (rand() & 1) swap(u, v);
        p[u] = v;
     }

     int spanning_tree_length(int n, vector<vector<int>> e) {
        int ans = 0;
        p.assign(n, 0);
        for (int i = 0; i < n; ++i) p[i] = i;
        sort(begin(e), end(e), [](auto x, auto y){ return x[2] < y[2]; });
        for (auto edge : e) {
           int x = edge[0] - 1;
           int y = edge[1] - 1;
           int w = edge[2];
           if (findset(x) == findset(y)) continue;
           ans += w;
           unionsets(x, y);
         }
         for (int i = 0; i < n; ++i) {
             if (findset(0) != findset(i)) {
                 return -1;
             }
         }
         return ans;
      }
    
    
    int minimumCost(int N, vector<vector<int>>& connections) {
        return spanning_tree_length(N, connections);
    }
};
    
    
int main() {
 
    return 0;
}
