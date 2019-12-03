#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

class SparseTable {
public:
    vector<vector<int>> t;
    int n;
    vector<int> log;

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
                next[i] = min(current[i], current[i + len]);
            }
            t.push_back(next);
            len *= 2;
        }
        for (int i = 2; i <= n; ++i) {
            log[i] = max(log[i - 1], log[i / 2] + 1);
        }
    }

    int get_min(int l, int r) const {
        int log2 = log[r - l + 1];
        return min(t[log2][l], t[log2][r + 1 - (1 << log2)]);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
		cin >> a[i];
    }
	SparseTable table(a);
    while (true) {
        int l;
        int r;
        cin >> l >> r;
        cout << table.get_min(l, r) << endl;
    }
    return 0;
}
