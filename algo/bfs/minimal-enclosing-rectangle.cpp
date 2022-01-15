#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels

class Solution {
public:
    int minArea(vector<vector<char>>& a, int x, int y) {
        int min_x = x;
        int max_x = x;
        int min_y = y;
        int max_y = y;
        queue<pair<int, int>> q;
        q.push({x, y});
        a[x][y] = '0';
        int n = a.size();
        int m = a[0].size();
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            max_x = max(max_x, i);
            min_x = min(min_x, i);
            max_y = max(max_y, j);
            min_y = min(min_y, j);
            if (i + 1 < n && a[i + 1][j] == '1') {
                a[i + 1][j] = '0';
                q.push({i + 1, j});
            }
            if (i > 0 && a[i - 1][j] == '1') {
                a[i - 1][j] = '0';
                q.push({i - 1, j});
            }
            if (j + 1 < m && a[i][j + 1] == '1') {
                a[i][j + 1] = '0';
                q.push({i, j + 1});
            }
            if (j > 0 && a[i][j - 1] == '1') {
                a[i][j - 1] = '0';
                q.push({i, j - 1});
            }
        }
        return (max_x - min_x + 1) * (max_y - min_y + 1);
    }
};

  
int main() {

    return 0;
}
