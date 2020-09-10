#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable

class Solution {
public:
    struct DSU {
        int n = 0;
        int count = 0;
        vector<int> p;
        DSU(int n) {
            count = n;
            p.assign(n, 0);
            for (int i = 0; i < n; ++i) p[i] = i;
        }
        
        int find_set(int x) {
            if (x == p[x]) return x;
            return p[x] = find_set(p[x]);
        }
        
        bool union_sets(int x, int y) {
            x = find_set(x);
            y = find_set(y);
            if (x == y) return false;
            if (rand() & 1) {
                swap(x, y);
            }
            p[x] = y;
            --count;
            return true;
        }
        
    };
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU a(n);
        DSU b(n);
        
        int ans = 0;
        for (auto edge : edges) {
            int num = edge[0];
            int x = edge[1];
            int y = edge[2];
            --x;
            --y;
            if (num != 3) {
                continue;
            }
            if (!a.union_sets(x, y)) {
                ++ans;
            }
            b.union_sets(x, y);
        }
        for (auto edge : edges) {
            int num = edge[0];
            int x = edge[1];
            --x;
            int y = edge[2];
            --y;
            if (num == 3) {
                continue;
            }
            if (num == 1) {
                if (!a.union_sets(x, y)) {
                    ++ans;
                }
            }
            if (num == 2) {
               if (!b.union_sets(x, y)) {
                   ++ans;
               }
            }
        }
        if (a.count != 1 || b.count  != 1) return -1;
        return ans;
    }
};
    
int main() {

    return 0;
}
