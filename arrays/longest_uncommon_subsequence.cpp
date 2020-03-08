#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;


// https://leetcode.com/problems/longest-uncommon-subsequence-ii

class Solution {
public:
    bool subsequence(const string& s, const string& t) {
        int n = s.size();
        int m = t.size();
        if (n < m) return false;
        int i = 0;
        for (int j = 0; j < m; ++j) {
            while (i < n && s[i] != t[j]) ++i;
            if (i >= n) return false;
            ++i;
        }
        return true;
    }
    int findLUSlength(vector<string>& a) {
        int n = a.size();
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            bool ok = true;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (subsequence(a[j], a[i])) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans = max(ans, (int)a[i].size());
        }
        return ans;
    }
};
int main() {

    return 0;
}
