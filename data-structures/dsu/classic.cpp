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
   vector<int> rank;
   

   DSU(int n)
       : n(n)
       , parent(n)
       , rank(n, 0)
   {
       for (int i = 0; i < n; ++i) parent[i] = i;
   }

   virtual size_t FindSet(size_t v) {
       if (v == parent[v]) return v;
       return parent[v] = FindSet(parent[v]);
   }

   virtual size_t Union(size_t a, size_t b) {
       a = FindSet(a);
       b = FindSet(b);
       
       if (a == b) return a;
       
       if (rank[a] < rank[b]) swap(a, b);
       parent[b] = a;
       
       if (rank[a] == rank[b]) ++rank[a];
       return a;
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
