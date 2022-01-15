#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

// https://leetcode.com/problems/shortest-path-in-a-hidden-grid/
// interactive problem
// one can move inside the grid
// the goal is to find the shortest path
// from one starting position to the exit 

// basic idea:
// dfs to reveal the grid first
// then bfs on top of that

/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     canMove(char direction);
 *     move(char direction);
 *     isTarget();
 * };
 */

class Solution {
public:
    int n = 0;
    vector<vector<int>> d;
    int x = -1;
    int y = -1;
    void dfs(int i, int j, GridMaster &master) {
        d[i][j] = -2;
        if (master.isTarget()) {
            x = i;
            y = j;
        }
        if (i > 0 && d[i - 1][j] == -1 && master.canMove('U')) {
            master.move('U');
            dfs(i - 1, j, master);
            master.move('D');
        }
        if (i + 1 < n && d[i + 1][j] == -1 && master.canMove('D')) {
            master.move('D');
            dfs(i + 1, j, master);
            master.move('U');
        }
        if (j > 0 && d[i][j - 1] == -1 && master.canMove('L')) {
            master.move('L');
            dfs(i, j - 1, master);
            master.move('R');
        }
        if (j + 1 < n && d[i][j + 1] == -1 && master.canMove('R')) {
            master.move('R');
            dfs(i, j + 1, master);
            master.move('L');
        }
    }
    
    int findShortestPath(GridMaster &master) {
        n = 1010;
        d.assign(n, vector<int>(n, -1));
        d[n / 2][n / 2] = -2;
        dfs(n / 2, n / 2, master);
        if (x == -1) return -1;
        queue<pair<int, int>> q;
        q.emplace(n / 2, n / 2);
        d[n / 2][n / 2] = 0;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            if (i == x && j == y) return d[i][j];
            if (i > 0 && d[i - 1][j] == -2) {
                d[i - 1][j] = d[i][j] + 1;
                q.emplace(i - 1, j);
            }
            if (i + 1 < n && d[i + 1][j] == -2) {
                d[i + 1][j] = d[i][j] + 1;
                q.emplace(i + 1, j);
            }
            if (j > 0 && d[i][j - 1] == -2) {
                d[i][j - 1] = d[i][j] + 1;
                q.emplace(i, j - 1);
            }
            if (j + 1 < n && d[i][j + 1] == -2) {
                d[i][j + 1] = d[i][j] + 1;
                q.emplace(i, j + 1);
            }
        }
        return 0;
    }
};
    
int main() {

    return 0;
}
