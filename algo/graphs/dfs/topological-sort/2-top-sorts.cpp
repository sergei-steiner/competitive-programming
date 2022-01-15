#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies

class Solution {
public:
    vector<vector<int>> g_group;
    vector<int> order_group;
    vector<bool> used_group;
    
    void dfs_group(int v) {
        used_group[v] = true;
        for (int w : g_group[v]) {
            if (!used_group[w]) {
                dfs_group(w);
            }
        }
        order_group.push_back(v);
    }
    
    
    vector<vector<int>> g;
    vector<int> order;
    vector<bool> used;
    
    void dfs(int v) {
        used[v] = true;
        for (int w : g[v]) {
            if (!used[w]) {
                dfs(w);
            }
        }
        order.push_back(v);
    }
    
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_map<int, int> prev;
        unordered_map<int, int> num;
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                num[i] = i;
                continue;
            }
            if (prev.count(group[i])) {
                num[i] = prev[group[i]];
            } else {
                prev[group[i]] = i;
                num[i] = i;
            }
        }
        
        
        m = n;
        g_group.resize(m);
        g.resize(n);
        for (int i = 0; i < n; ++i) {
            for (int j : beforeItems[i]) {
                g[j].push_back(i);
                g_group[num[j]].push_back(num[i]);
            }
        }
        
                              
        used_group.assign(m, false);
        for (int i = 0; i < m; ++i) {
            if (!used_group[i]) dfs_group(i);
        }
        reverse(begin(order_group), end(order_group));
        
        used.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (!used[i]) dfs(i);
        }
        reverse(begin(order), end(order));
                              
        unordered_map<int, int> reverse_order_group;
        for (int i = 0; i < m; ++i) {
            reverse_order_group[order_group[i]] = i;
        }
        
        unordered_map<int, int> reverse_order;
        for (int i = 0; i < n; ++i) {
            reverse_order[order[i]] = i;
        }
                              
        unordered_map<int, int> rank;
        for (int i = 0; i < n; ++i) {
            rank[i] = reverse_order[i] + 50000 * reverse_order_group[num[i]];
        }
                              
        for (int i = 0; i < n; ++i) {
            for (int j : beforeItems[i]) {
                if (rank[j] > rank[i]) return {};
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) ans.push_back(i);
        sort(begin(ans), end(ans), [&](int i, int j) { return rank[i] < rank[j] ;});
        return ans;   
    }
};
    
int main() {

    return 0;
}
