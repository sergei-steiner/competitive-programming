#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

class Solution {
public:
    bool subfolder(string t, string s) {
        int n = t.size();
        int m = s.size();
        if (n > m) return false;
        if (t != s.substr(0, n)) return false;
        if (n == m) return true;
        return s[n] == '/';
    }
    vector<string> removeSubfolders(vector<string>& a) {
        sort(begin(a), end(a));
        vector<string> ans;
        for (string s : a) {
            if (!ans.empty() && subfolder(ans.back(), s)) {
            } else {
                ans.push_back(s);
            }
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
