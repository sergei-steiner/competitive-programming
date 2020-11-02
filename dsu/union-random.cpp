/*

The main implementation of DSU I use!

*/

#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// tested on https://leetcode.com/problems/graph-connectivity-with-threshold/

class DSU {
    
int n = 0;
vector<int> p;
    
public:
    
    DSU(int n)
       : n(n)
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
        return true;
    }
};

int main() {
    int n;
    cin >> n;
    DSU dsu(n);
    while (true) {
        string s;
        cin >> s;
        if (s == "union") {
            int u;
            int v;
            cin >> u >> v;
            dsu.Union(u, v);
        }
        if (s == "findset") {
            int v;
            cin >> v;
            cout << dsu.FindSet(v) << endl;
        }
    }
    return 0;
}
