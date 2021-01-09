#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/escape-a-large-maze

// B = blocks.size()

// my solution
// just compress all the coordinates +- 1 and bfs or dfs
// O(B^2)

class Solution {
public:
    void add(set<int>& vals, int x) {
        if (x > 0) vals.insert(x - 1);
        vals.insert(x);
        if (x + 1 < 1000000) vals.insert(x + 1);
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int x1 = source[0];
        int y1 = source[1];
        int x2 = target[0];
        int y2 = target[1];
        set<int> vals;
        for (auto v : blocked) {
            add(vals, v[0]);    
        }
        for (auto v : blocked) {
            add(vals, v[1]);
        }
        add(vals, x1);
        add(vals, y1);
        add(vals, x2);
        add(vals, y2);
        vector<int> unique(begin(vals), end(vals));
        map<int, int> compressed;
        for (int i = 0; i < unique.size(); ++i) {
            compressed[unique[i]] = i;
        }
        int n = unique.size();
        vector<vector<int>> a(n, vector<int> (n, 0));
        for (auto v : blocked) {
            a[compressed[v[0]]][compressed[v[1]]] = 1;
        }
        x1 = compressed[x1];
        y1 = compressed[y1];
        x2 = compressed[x2];
        y2 = compressed[y2];
        if (a[x2][y2] == 1) a[x2][y2] = 0;
        queue<pair<int, int>> q;
        q.push({x1, y1});
        a[x1][y1] = 2;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == x2 && y == y2) return true;
            if (x + 1 < n && a[x + 1][y] == 0) {
                q.push({x + 1, y});
                a[x + 1][y] = 2;
            }
            if (x > 0 && a[x - 1][y] == 0) {
                q.push({x - 1, y});
                a[x - 1][y] = 2;
            }
            if (y + 1 < n && a[x][y + 1] == 0) {
                q.push({x, y + 1});
                a[x][y + 1] = 2;
            }
            if (y > 0 && a[x][y - 1] == 0) {
                q.push({x, y - 1});
                a[x][y - 1] = 2;
            }
        }
        return false;
    }
};

// https://leetcode.com/problems/escape-a-large-maze/discuss/974779/BFS-O(block2)
// O(B^2) as well, but the constant is smaller

class Solution2 {
public:
    int max_area = 0;
    bool is_valid(int x, int y) {
        return x >= 0 && y >= 0 && x < 1000000 && y < 1000000;
    }
    bool bfs(unordered_map<int, unordered_map<int, int>> a, int x1, int y1, int x2, int y2) {
        int cnt = 0;
        queue<pair<int, int>> q;
        q.push({x1, y1});
        a[x1][y1] = 2;
        while (!q.empty()) {
            ++cnt;
            if (cnt > max_area) return true;
            auto [x, y] = q.front();
            q.pop();
            if (x == x2 && y == y2) return true;
            if (is_valid(x + 1, y) && a[x + 1][y] == 0) {
                q.push({x + 1, y});
                a[x + 1][y] = 2;
            }
            if (is_valid(x - 1, y) && a[x - 1][y] == 0) {
                q.push({x - 1, y});
                a[x - 1][y] = 2;
            }
            if (is_valid(x, y + 1) && a[x][y + 1] == 0) {
                q.push({x, y + 1});
                a[x][y + 1] = 2;
            }
            if (is_valid(x, y - 1) && a[x][y - 1] == 0) {
                q.push({x, y - 1});
                a[x][y - 1] = 2;
            }
        }
        return false;
    }
    
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        max_area = blocked.size() * (blocked.size() - 1) / 2;
        
        int x1 = source[0];
        int y1 = source[1];
        int x2 = target[0];
        int y2 = target[1];
        
        unordered_map<int, unordered_map<int, int>> a;
        for (auto v : blocked) {
            a[v[0]][v[1]] = 1;    
        }
        a[x1][y1] = 0;
        a[x2][y2] = 0;
        
        
        
        return bfs(a, x1, y1, x2, y2) && bfs(a, x2, y2, x1, x1);
       
    }
};

int main() {

    return 0;
}
