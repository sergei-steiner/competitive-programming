#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/rank-transform-of-a-matrix/

// Solution 1: slow, O(nm*(n+m)), still somehow beats 100% solutions

class DSU {
    
int n = 0;
vector<int> p;
vector<int> rank;
public:
    DSU(int n, const vector<int>& rank)
       : n(n)
       , rank(rank)    
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
        rank[y] = max(rank[x], rank[y]);
        return true;
    }
    
    int GetRank(int x) {
        x = FindSet(x);
        return rank[x];
    }
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        map<int, vector<pair<int, int>>> order;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                order[matrix[i][j]].emplace_back(i, j);
            }
        }
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<int> rank(n + m, 0);
        for (auto& [k, v] : order) {
            DSU dsu(n + m, rank);
            for (auto [i, j] : v) {
                dsu.Union(i, j + n);
            }
            
            for (auto [i, j] : v) {
               ans[i][j] = dsu.GetRank(i) + 1;        
            }
            
            for (auto [i, j] : v) {
               rank[i] = rank[j + n] = ans[i][j];  
            }
        }
        return ans;
    }
};

// Solution2: use sparse DSU!
// For some reason runs way slower, probably due to weak tests
// complexity O(nmlog(n+m)) (of sorting)

class DSU {
    
int n = 0;
unordered_map<int, int> p;
unordered_map<int, int> rank;
public:
    DSU() = default;
    
    void MakeSet(int x, int r) {
        p[x] = x;
        rank[x] = r;
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
        rank[y] = max(rank[x], rank[y]);
        return true;
    }
    
    int GetRank(int x) {
        x = FindSet(x);
        return rank[x];
    }
};

class Solution2 {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        map<int, vector<pair<int, int>>> order;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                order[matrix[i][j]].emplace_back(i, j);
            }
        }
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<int> rank(n + m, 0);
        for (auto& [k, v] : order) {
            DSU dsu;
            for (auto [i, j] : v) {
                dsu.MakeSet(i, rank[i]);
                dsu.MakeSet(j + n, rank[j + n]);
            }
            for (auto [i, j] : v) {
                dsu.Union(i, j + n);
            }

            for (auto [i, j] : v) {
               ans[i][j] = dsu.GetRank(i) + 1;        
            }
            
            for (auto [i, j] : v) {
               rank[i] = rank[j + n] = ans[i][j];  
            }
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
