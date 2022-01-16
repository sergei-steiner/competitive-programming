#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

void count_sort(vector<int>& p, const vector<int>& c) {
     int n = p.size();

     vector<int> cnt(n, 0);
     for (int x : c) {
         ++cnt[x];
     }

     vector<int> pos(n, 0);
     for (int i = 1; i < n; ++i) {
          pos[i] = pos[i - 1] + cnt[i - 1];
     }
     vector<int> new_p(n);
     for (int x : p) {
          int i = c[x];
          new_p[pos[i]] = x;
          ++pos[i];
     }
     p = new_p;
}

tuple<vector<int>, vector<int>, vector<int>> suffix_array(string s) {
    s.push_back(1);
    int n = s.size();

    vector<int> p(n);
    vector<int> c(n);

    {
       // k = 0;
       vector<pair<char, int>> a;
       for (int i = 0; i < n; ++i) a.emplace_back(s[i], i);
       sort(begin(a), end(a));
       for (int i = 0; i < n; ++i) p[i] = a[i].second;
       c[p[0]] = 0;
       for (int i = 1; i < n; ++i) {
           if (a[i].first == a[i - 1].first) {
               c[p[i]] = c[p[i - 1]];
           } else {
               c[p[i]] = c[p[i - 1]] + 1;
           }
       }
    }

    int k = 0;

    while ((1 << k) < n) {
        for (int i = 0; i < n; ++i) {
            p[i] = (p[i] - (1 << k) + n) % n;
        }

        count_sort(p, c);

        vector<int> new_c(n);
        new_c[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
            pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            if (now == prev) {
                new_c[p[i]] = new_c[p[i - 1]];
            } else {
                new_c[p[i]] = new_c[p[i - 1]] + 1;
            }
        }
        ++k;

        c = new_c;
    }

    vector<int> lcp(n, 0);
    k = 0;
    for (int i = 0; i + 1 < n; ++i) {
        int pi = c[i];
        int j = p[pi - 1];
        while (s[i + k] == s[j + k]) {
            ++k;
        }
        lcp[pi] = k;
        k = max(k - 1, 0);
    }

    return {p, c, lcp};
}

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

    int getMin(int l, int r) const {
        int log2 = log[r - l + 1];
        return min(t[log2][l], t[log2][r + 1 - (1 << log2)]);
    }
};


int main() {
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    auto [p, c, lcp] = suffix_array(s);

    int n = p.size();

    SparseTable sparseTable(lcp);

    int q;
    cin >> q;
    vector<pair<int, int>> a;
    for (int i = 0; i < q; ++i) {
        int l;
        cin >> l;
        --l;
        int r;
        cin >> r;
        --r;
        a.emplace_back(l, r);
    }

    sort(begin(a), end(a), [&] (pair<int, int> s1, pair<int, int> s2) {

         auto [l1, r1] = s1;
         auto [l2, r2] = s2;

         if (l1 == l2) {
             return r1 < r2;
         }

         int i1 = c[l1];
         int i2 = c[l2];
         if (i1 > i2) {
             int len = sparseTable.getMin(i2 + 1, i1);
             int len1 = r1 - l1 + 1;
             int len2 = r2 - l2 + 1;
             if (len1 <= len && len2 > len) {
                 return true;
             }
             if (len1 > len && len2 <= len) {
                 return false;
             }

             if (len1 > len && len2 > len) {
                 return false;
             }

             if (len1 < len2) return true;
             if (len1 > len2) return false;
             return l1 < l2;
         }

         int len = sparseTable.getMin(i1 + 1, i2);
         int len1 = r1 - l1 + 1;
         int len2 = r2 - l2 + 1;
         if (len1 <= len && len2 > len) {
             return true;
         }
         if (len1 > len && len2 <= len) {
             return false;
         }

         if (len1 > len && len2 > len) {
             return true;
         }

         if (len1 < len2) return true;
         if (len1 > len2) return false;
         return l1 < l2;
    });

    for (int i = 0; i < q; ++i) {
        auto [l, r] = a[i];
        cout << l + 1 << " " << r + 1 << endl;
    }

    return 0;
}