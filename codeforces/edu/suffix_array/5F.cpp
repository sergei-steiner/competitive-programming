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
    s.push_back('$');
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

struct DSU {
    int n = 0;
    vector<set<int>> a;
    vector<vector<int>> lst;
    vector<int> parent;
    DSU(const vector<int>& p) {
        n = p.size();
        a.resize(n);
        lst.resize(n);
        for (int i = 1; i < n; ++i) {
            a[i].insert(p[i]);
            lst[i].push_back(i);
        }
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
           parent[i] = i;
        }
    }

    int FindSet(int x) {
        return parent[x];
    }

    int UnionSets(int x, int y) {

        x = FindSet(x);
        y = FindSet(y);

        if (a[x].size() < a[y].size()) {
            swap(x, y);
        }


        for (int i : lst[y]) {
            parent[i] = x;
            lst[x].push_back(i);
        }

        int ans = 1000000000;
        for (int i : a[y]) {
            auto it = (a[x].insert(i)).first;
            if (it != a[x].begin()) {
                auto it1 = it;
                --it1;
                // cout << "neighbors " << *it1 << " " << i << endl;
                ans = min(ans, i - *it1);
            }
            auto it2 = it;
            ++it2;
            if (it2 != a[x].end()) {
                // cout << "neighbors " << i << " " << *it2 << endl;
                ans = min(ans, *it2 - i);
            }
        }

        return ans;
    }


};

int main() {
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    int n = s.size();

    auto [p, c, lcp] = suffix_array(s);

    n = p.size();

    vector<pair<int, int>> a;
    for (int i = 1; i < n; ++i) {
        a.emplace_back(lcp[i], i);
    }
    sort(begin(a), end(a));
    reverse(begin(a), end(a));

    DSU dsu(p);

    int ans = 0;
    for (auto [lcp_val, i] : a) {
       int dist = dsu.UnionSets(i - 1, i);
       ans = max(ans, lcp_val / dist + 1);
    }

    cout << ans << endl;

    return 0;
}