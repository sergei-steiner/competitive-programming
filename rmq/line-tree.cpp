/*

https://codeforces.com/blog/entry/71568?#comment-559304

*/


#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

struct Item {
    int set = 0;
    int weight = 0;
    Item* next = nullptr;
    Item* head = nullptr;
    Item* tail = nullptr;
    int count = 0;

    Item(int i, int weight) {
        set = i;
        this->weight = weight;
        head = this;
        tail = this;
        count = 1;
    }
};

class DSU {
public:
   int n;
   vector<Item*> s;
   

    DSU(int n)
      : n(n)
    {
        for (int i = 0; i < n; ++i) {
            s.emplace_back(new Item(i, 0));
        }
    } 

    int FindSet(int v) {
        return s[v]->head->set;
    }

    bool Union(int u, int v, int w) {
        auto x = s[u]->head;
        auto y = s[v]->head;
       
        if (x == y) return false;
       
        if (x->count > y->count) {
           swap(x, y);
        }

        auto cur = x;
        while (cur != nullptr) {
            cur->head = y;
            cur = cur->next;
        }
        y->tail->next = x;
        y->tail->weight = w;
        y->tail = x->tail;
        y->count += x->count;
        return true;
   }


    vector<pair<int, int>> Print(int v) {
        vector<pair<int, int>> ans;
        auto node = s[v]->head;
        while (node) {
            ans.emplace_back(node->set, node->weight);
            node = node->next;
        }
        return ans;
    }
};

class SparseTable {
public:
    vector<vector<int>> t;
    int n;
    vector<int> log;

    SparseTable() = default;

    SparseTable(const vector<int>& a)
        : n(a.size())
        , log(n + 1, 0)
    {
        t.push_back(a);
        int len = 1;
        while (len * 2 <= n) {
            vector<int>& current = t.back();
            vector<int> next(n, 0);
            for (int i = 0; i + len < n; ++i) {
                next[i] = max(current[i], current[i + len]);
            }
            t.push_back(next);
            len *= 2;
        }
        for (int i = 2; i <= n; ++i) {
            log[i] = max(log[i - 1], log[i / 2] + 1);
        }
    }

    int get_max(int l, int r) const {
        int log2 = log[r - l + 1];
        return max(t[log2][l], t[log2][r + 1 - (1 << log2)]);
    }
};

using WeightedTree = vector<vector<pair<int, int>>>;

class LinearTree {
public:
    unordered_map<int, int> order;
    vector<int> weights;
    SparseTable st;

    LinearTree(const WeightedTree& g)
    {
        int n = g.size(); 
        // sort edges
        vector<tuple<int, int, int>> edges;
        for (int v = 0; v < n; ++v) {
            for (auto [u, w] : g[v]) {
                if (v < u) {
                    edges.emplace_back(w, v, u);
                }
            }
        }
        sort(begin(edges), end(edges));

        DSU dsu(n);

        for (auto [w, v, u] : edges) {
            dsu.Union(v, u, w);
        }

        auto dsuOrder = dsu.Print(0);
        for (auto [i, w] : dsuOrder) {
             order[i] = weights.size();
             weights.push_back(w);
        }

        st = SparseTable(weights);
    }

    int get_max(int u, int v) {
        return get_reordered_max(order[u], order[v]);
    }

    int get_reordered_max(int u, int v) {
        if (u > v) swap(u, v);

        /*
        naive for now
        int ans = weights[u];
        while (u < v) {
            ans = max(ans, weights[u]);
            ++u;
        }

        return ans;
        */

        return st.get_max(u, v - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    WeightedTree g(n);
    for (int i = 0; i + 1 < n; ++i) {
        int x;
        cin >> x;
        int y;
        cin >> y;
        int w;
        cin >> w;
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
    }

    LinearTree linearTree(g);
    // create linear tree

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u;
        cin >> u;
        int v;
        cin >> v;
        cout << linearTree.get_max(u, v);
    }

    

    return 0;
}