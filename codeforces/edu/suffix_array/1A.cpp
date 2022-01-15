#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
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
        vector<pair<pair<int, int>, int>> a;

        for (int i = 0; i < n; ++i) a.push_back({{c[i], c[(i + (1 << k)) % n]}, i});
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
        ++k;
    }

    for (int i = 0; i < n; ++i) cout << p[i] << " ";

    return 0;
}