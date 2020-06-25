#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

class DSU {
public:
   int n;
   vector<int> parent;

   DSU(int n)
       : n(n)
       , parent(n)
   {
       for (int i = 0; i < n; ++i) parent[i] = i;
   }

   size_t FindSet(size_t v) {
       if (v == parent[v]) return v;
       return parent[v] = FindSet(parent[v]);
   }

   void Union(size_t a, size_t b) {
       a = FindSet(a);
       b = FindSet(b);
       if (rand() & 1) swap(a, b);
       parent[b] = a;
   }

};

int main() {
    int n;
    cin >> n;
    DSU d(n);
    while (true) {
        string s;
        cin >> s;
        if (s == "union") {
            int u;
            int v;
            cin >> u >> v;
            d.Union(u, v);
        }
        if (s == "findset") {
            int v;
            cin >> v;
            cout << d.FindSet(v) << endl;
        }
    }
    return 0;
}
