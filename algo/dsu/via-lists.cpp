#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://neerc.ifmo.ru/wiki/index.php?title=СНМ_(списки_с_весовой_эвристикой)
// tested on https://leetcode.com/problems/swim-in-rising-water

struct Item {
    int set = 0;
    Item* next = nullptr;
    Item* head = nullptr;
    Item* tail = nullptr;
    int count = 0;

    Item(int i) {
        set = i;
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
            s.emplace_back(new Item(i));
        }
    } 

    int FindSet(int v) {
        return s[v]->head->set;
    }

    bool Union(int u, int v) {
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
        y->tail = x->tail;
        y->count += x->count;
        return true;
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
