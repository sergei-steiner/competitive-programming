#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/the-maze-iii

class Solution {
public:     
    int inf = 1000000000;

    vector<pair<int, string>> dijkstra_set(int s, const vector<vector<pair<int, pair<int, string>>>>& g) {
    int n = g.size();
    vector<pair<int, string>> d(n, make_pair(inf, ""));
    d[s] = make_pair(0, "");
    set<pair<pair<int, string>, int>> q;
    q.insert(make_pair(d[s], s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto [to, len] : g[v]) {
            if (d[v].first + len.first < d[to].first ||
                (d[v].first + len.first == d[to].first &&
                d[v].second + len.second < d[to].second)
               ) {
                q.erase(make_pair(d[to], to));
                d[to].first = d[v].first + len.first;
                d[to].second = d[v].second + len.second;
                q.insert(make_pair(d[to], to));
            }
        }
    }
    return d;
}
    string findShortestWay(vector<vector<int>>& a, vector<int>& start, vector<int>& destination) {
        int n = a.size();
        int m = a[0].size();
        int sx = start[0];
        int sy = start[1];
        int dx = destination[0];
        int dy = destination[1];
        vector<vector<int>> up = a;
        vector<vector<int>> down = a;
        vector<vector<int>> left = a;
        vector<vector<int>> right = a;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 1) continue;
                if (i == 0 || a[i - 1][j] == 1 || (i == dx && j == dy)) {
                    up[i][j] = i;
                } else {
                    up[i][j] = up[i - 1][j];
                }
                if (j == 0 || a[i][j - 1] == 1 || (i == dx && j == dy)) {
                    left[i][j] = j;
                } else {
                    left[i][j] = left[i][j - 1];
                }
            } 
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (a[i][j] == 1) continue;
                if (i + 1 == n || a[i + 1][j] == 1 || (i == dx && j == dy)) {
                    down[i][j] = i;
                } else {
                    down[i][j] = down[i + 1][j];
                }
                if (j + 1 == m || a[i][j + 1] == 1 || (i == dx && j == dy)) {
                    right[i][j] = j;
                } else {
                    right[i][j] = right[i][j + 1];
                }
            }
        }
        int N = n * m;
        vector<vector<pair<int, pair<int, string>>>> g(N);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 1) continue;
                int  from = i * m + j;
                if (up[i][j] != i) {
                    int to = up[i][j] * m + j;
                    int dist = i - up[i][j];
                    g[from].emplace_back(to, make_pair(dist, string(1, 'u')));
                }
                if (down[i][j] != i) {
                    int to = down[i][j] * m + j;
                    int dist = down[i][j] - i;
                    g[from].emplace_back(to,  make_pair(dist, string(1, 'd')));
                }
                if (left[i][j] != j) {
                    int to = i * m + left[i][j];
                    int dist = j- left[i][j];
                    g[from].emplace_back(to,  make_pair(dist, string(1, 'l')));
                }
                if (right[i][j] != j) {
                    int to = i * m + right[i][j];
                    int dist = right[i][j] - j;
                    g[from].emplace_back(to,  make_pair(dist, string(1, 'r')));
                }
            }
        }
                 
        int s = sx * m + sy;
        int to = dx * m + dy;
        auto [len, ans] = dijkstra_set(s, g)[to];
        if (len > inf / 2) return "impossible";
        return ans;
        
    }
};

    
int main() {

    return 0;
}
