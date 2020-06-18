#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// http://e-maxx.ru/algo/floyd_warshall_algorithm
 
vector<vector<int>> floyd(const vector<vector<int>>& a) {
    vector<vector<int>> d = a;
    int n = a.size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                 // if (d[i][k] < inf && d[k][j] < inf) to cope with negative cycles
                 d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    return d;
}
 
int main() {

    return 0;
}
