#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

struct Fenwick {
    int n = 0;
    vector<int> t;

    Fenwick(int n)
        : n(n)
        , t(vector<int>(n, 0))
    {
    }

    int sum(int r) {
        int result = 0;
        while (r >= 0) {
            result += t[r];
            r = (r & (r + 1)) - 1;
        }
        return result;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void inc(int i, int delta) {
        while (i < n) {
            t[i] += delta;
            i |= (i + 1);
        }
    }
    
    void update(int i, int x) {
        inc(i, x - sum(i, i));
    }
};

int main() {
    int n;
    cin >> n;
    Fenwick f(n);
    while (true) {
        string s;
        cin >> s;
        if (s == "sum") {
            int l;
            int r;
            cin >> l >> r;
            cout << f.sum(l, r) << endl;
        }
        if (s == "inc") {
            int pos;
            int value;
            cin >> pos >> value;
            f.inc(pos, value);
        }
    }
    return 0;
}
