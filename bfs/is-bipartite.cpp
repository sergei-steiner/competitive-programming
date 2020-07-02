#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& a) {
        vector<vector<int>> g(n);
        for (auto p : a) {
            int x = p[0];
            --x;
            int y = p[1];
            --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> color(n, 0);
        for (int j = 0; j < n; ++j) {
            if (color[j] != 0) continue; 
            queue<int> q;
            color[j] = 1;
            q.push(j);
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int y : g[x]) {
                    if (color[x] == color[y]) {
                        return false;
                    }
                    if (color[y] != 0) continue;
                    color[y] = 3 - color[x];
                    q.push(y);
                }
            }
        }
        return true;
    }
};


    
int main() {

    return 0;
}
