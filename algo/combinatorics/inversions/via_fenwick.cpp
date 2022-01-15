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
        , t(n, 0)
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
};

long long inv_count(const vector<int>& p) {
     int ans = 0;
     int n = p.size();
     Fenwick t(n);
     for (int i = 0; i < n; ++i) {
         ans += t.sum(p[i] + 1, n - 1);
         t.inc(p[i], 1);
     }
     return ans;
}

int main() {
    vector<int> p = {5, 4, 3, 1, 2};
    cout << inv_count(p) << endl;

    return 0;
}
