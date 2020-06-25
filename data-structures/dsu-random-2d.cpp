#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

class DSU {
public:
    int n = 0;
    int m = 0;
    vector<vector<pair<int, int>>> p;
    DSU(int n, int m)
       : n(n)
       , m(m)
       , p(n, vector<int>(m))
    {
       for (int i = 0; i < n; ++i) {
           for (int j = 0; j < m; ++j) {
               p[i][j] = {i, j};
           }   
       }
    }
    
    pair<int, int> FindSet(int i, int j) {
        if (p[i][j] == make_pair(i, j)) return p[i][j];
        auto [pi, pj] = p[i][j];
        return p[i][j] = FindSet(pi, pj);
    }
   

   void Union(size_t a, size_t b) {
       auto [i1, j1] = FindSet(x1, y1);
        auto [i2, j2] = FindSet(x2, y2);
        if (i1 == i2 && j1 == j2) return;
        if (rand() & 1) {
            swap(i1, i2);
            swap(j1, j2);
        }
        p[i1][j1] = {i2, j2};
   }
};

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    DSU d(n, m);
    while (true) {
        string s;
        cin >> s;
        if (s == "union") {
            int i1, j1;
            cin >> i1 >> j1;
            int i2, j2;
            cin >> i2 >> j2;
            d.Union(i1, j1, i2, j2;
        }
        if (s == "findset") {
            int i, j;
            cin >> i >> j;
            cout << d.FindSet(i, j).first << " " << d.FindSet(i, j).second << endl;
        }
    }
    return 0;
}
