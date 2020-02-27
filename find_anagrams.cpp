#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/find-all-anagrams-in-a-string

vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> a;
    for (char ch : p) --a[ch];
    vector<int> ans;
    int m = p.size();
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        ++a[s[i]];
        if (a[s[i]] == 0) {
            a.erase(s[i]);
        }
        if (i >= m) {
            --a[s[i - m]];
            if (a[s[i - m]] == 0) {
                a.erase(s[i - m]);
            }
        }
        if (a.empty()) {
            ans.push_back(i - m + 1);
        }
    }
    return ans;
}
    
int main() {

    return 0;
}
