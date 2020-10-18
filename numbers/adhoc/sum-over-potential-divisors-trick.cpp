
/*

The whole idea is that cycles
    for all d in [1, n]:
        for all i * d in [0, n]

work in O(n log n) time, 
because n + n/2 + n/3 + ... = n(1 + 1/2 + 1/3 + ...) = n * O(log n)

*/

#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/graph-connectivity-with-threshold

class DSU {
    
int n = 0;
vector<int> p;
    
public:
    
    DSU(int n)
       : n(n)
    {
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
    }
    
    int FindSet(int x) {
        if (x == p[x]) return x;
        return p[x] = FindSet(p[x]);
    }
    
    bool Union(int x, int y) {
        x = FindSet(x);
        y = FindSet(y);
        if (x == y) return false;
        if (rand() % 1) swap(x, y);
        p[x] = y;
        return true;
    }
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU dsu(n + 1);
        for (int i = threshold + 1; i <= n; ++i) {
            for (int j = 2 * i; j <= n; j += i) {
                dsu.Union(j - i, j);
            }
        }
        
        vector<bool> ans;
        for (auto q : queries) {
            int x = q[0];
            int y = q[1];
            ans.push_back(dsu.FindSet(x) == dsu.FindSet(y));
        }
        
        return ans;
    }
};
    
int main() {

    return 0;
}
