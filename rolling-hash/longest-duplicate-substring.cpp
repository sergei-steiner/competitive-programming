#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/longest-duplicate-substring

class Solution {
public:
    using uint64 = unsigned long long;
    constexpr static int p = 31;
    vector<uint64> deg = {1};
    vector<uint64> get_hashes(const string& t) {
       int n = t.size();
       while (deg.size() <= n) {
           deg.push_back(deg.back() * p);
       }
       vector<uint64> ans;
       uint64 s = 0; 
       for (int i = 0; i < n; ++i) {
          s += deg[i] * (t[i] - 'a' + 1);
          ans.push_back(s);
       }
       return ans;
    }
    uint64 substr_hash(int i, int j, const vector<uint64>& h) {
        uint64 ans = h[j];
        if (i > 0) ans -= h[i - 1];
        return ans * deg[h.size() - 1 - i];
    }
    string longestDupSubstring(string S) {
        int n = S.size();
        auto h = get_hashes(S);
        int l = 0;
        int r = n;
        int from = 0;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            bool ok = false;
            unordered_map<uint64, int> a;
            if (m == 0) {
                ok = true;
            } else {
                for (int i = 0; i + m <= n; ++i) {
                    int hash = substr_hash(i, i + m - 1, h);
                    if (a.count(hash) && S.substr(i, m) == S.substr(a[hash], m)) {
                        ok = true;
                        from = i;
                        break;
                    }
                    a[hash] = i;
                }
            }
            if (ok) {
                l = m;
            } else {
                r = m;
            }
        }
        return S.substr(from, l);
    }
};
	
int main() {
    return 0;
}
