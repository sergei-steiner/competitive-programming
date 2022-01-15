/*

https://youtu.be/jqJ5s077OKo?t=786

Given a graph with n ≤ 2000 vertices and m ≤ n⋅(n−1)/2 edges, 
count triples of vertices a, b, c
such that there are edges a − b, a − c and b − c.

*/


#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
    
constexpr int N = 2000;

int main() {
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<bitset<N>> g(n);

    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        --x;
        int y;
        cin >> y;
        --y;
        g[x][y] = true;
        g[y][x] = true;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (g[i][j]) {
                ans += (g[i] & g[j]).count();
            }
        }
    }

    ans /= 3;

    cout << ans;

    return 0;
}