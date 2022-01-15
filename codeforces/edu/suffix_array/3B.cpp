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

vector<int> suffix_array(string& s) {
    s += "$";
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

    return p;
}

int compare(int m, const string& s, const vector<int>& p, const string& t) {
     int i = p[m];
     int cmp = 0;
     for (int j = 0; j < t.size(); ++j) {
         if (i + j >= s.size()) {
             cmp = 1;
             break;
         }
         if (s[i + j] < t[j]) {
             cmp = 1;
             break;
         }
         if (s[i + j] > t[j]) {
             cmp = -1;
             break;
         }
     }
     return cmp;
}

int main() {
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    int n;
    cin >> n;
    auto p = suffix_array(s);

    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        int l = 0;
        int r = p.size() - 1;
        while (l + 3 < r) {
            int m = (l + r) / 2;
            int cmp = compare(m, s, p, t);
            if (cmp == 0) {
                r = m;
            } else if (cmp == 1) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        int from = -1;
        for (int i = l; i <= r; ++i) {
            if (compare(i, s, p, t) == 0) {
                from = i;
                break;
            }
        }

        l = 0;
        r = p.size() - 1;
        while (l + 3 < r) {
            int m = (l + r) / 2;
            int cmp = compare(m, s, p, t);
            if (cmp == 0) {
                l = m;
            } else if (cmp == 1) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }



        int to = -1;
        for (int i = r; i >= l; --i) {
             if (compare(i, s, p, t) == 0) {
                 to = i;
                 break;
             }
        }

        if (from == -1) {
            cout << 0 << endl;
        } else {
            cout << to - from + 1 << endl;
        }

    }

    return 0;
}
