/*

You are given two rooted trees with n vertices. Determine if they are isomorphic.

http://rng-58.blogspot.com/2017/02/hashing-and-probability-of-collision.html

*/

#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

using Tree = vector<vector<int>>;

class TreeHash {
    vector<int> x;

    pair<int, int> dfs(int v, const Tree& g, vector<bool>& used) {
        used[v] = true;
        vector<int> hashes;
        int d = 0;
        for (int to : g[v]) {
            if (!used[to]) {
                auto [h_child, d_child] = dfs(to, g, used);
                hashes.push_back(h_child);
                d = max(d, d_child + 1);
            }
        }
        while (d >= x.size()) x.push_back(rand());
        int h = 1;
        for (int h_child : hashes) {
            h *= (x[d] + h_child); 
        }
        return {h, d};
    }

    public:

    TreeHash() {
       x.push_back(1);
    }
    
    int hash(const Tree& g) {
       int n = g.size();
       vector<bool> used(n, false); 
       return dfs(0, g, used).second;
    }
    
};

void readTree(Tree& g) {
    int n = g.size();
    for (int i = 0; i + 1 < n; ++i) {
        int x;
        cin >> x;
        int y;
        cin >> y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(y);
    }
}


int main() {
    int n; 
    cin >> n;
    Tree a(n);
    readTree(a);
    Tree b(n);
    readTree(b);
    TreeHash treeHash;
    cout << (treeHash.hash(a) == treeHash.hash(b)) << endl;
    return 0;
}
