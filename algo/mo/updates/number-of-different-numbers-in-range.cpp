#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

/*

https://codeforces.com/blog/entry/44711?#comment-292040

The model problem: we have N numbers and Q query of two types:

1) get amount of distinct numbers in range [l, r]

2) update the i-th number

N ~= Q

The following Mo-like solution works in O(N^{5/3})

*/

void erase(unordered_map<int, int>& counts, int val) {
    --counts[val];
    if (counts[val] == 0) {
        counts.erase(val);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int q;
    cin >> q;

    vector<tuple<int, int, int>> queries;
    for (int j = 0; j < q; ++j) {
        int type;
        cin >> type;
        // update
        if (type == 1) {
            int i;
            cin >> i;
            int x;
            cin >> x;
            queries.emplace_back(type, i, x);
        }
        // query
        if (type == 2) {
            int l;
            cin >> l;
            int r;
            cin >> r;
            queries.emplace_back(type, l, r);
        }
    }

    vector<int> ans(q, -1);
    // block size
    int m = pow(n, 2.0 / 3.0);
    for (int i = 0; i < n; i += m) {
        for (int j = i; j < n; j += m) {
            // blocks pair:
            // l \in [i, i + m)
            // r \in [j, j + m)
            vector<int> b = a; // just a copy
            
            unordered_map<int, int> counts;
            
            // just add everything
            // not really necessary
            int L = i;
            int R = min(j + m - 1, n - 1);
            for (int k = i; k < min(j + m, n); ++k) {
                ++counts[b[k]];
            }            

            for (int k = 0; k < q; ++k) {
                auto query = queries[k];
                auto [type, skip1, skip2] = query;
                if (type == 1) {
                    auto [type, i, x] = query;
                    if (L <= i && i <= R) {
                        erase(counts, b[i]);
                        ++counts[x];    
                    }
                    b[i] = x;
                }
                if (type == 2) {
                    auto [type, l, r] = query;
                    if (i <= l && l < i + m && j <= r && r < j + m) {
                        while (L != l || R != r) {
                           if (R < r) {
                               ++R;
                               ++counts[b[R]];
                               continue;
                           }
                           if (L > l) {
                               --L;
                               ++counts[b[L]];
                               continue;
                           }
                           // L <= l
                           if (R > r) {
                               erase(counts, b[R]);
                               --R;
                               continue;
                           }
                           // R >= r
                           if (L < l) {
                               erase(counts, b[L]);
                               ++L;
                               continue;
                           }
                        }

                        ans[k] = counts.size();
                    }
                }
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << " ";
    }

    return 0;
}
