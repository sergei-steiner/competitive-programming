#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/shortest-way-to-form-string

class Solution {
public:
    int shortestWay(string s, string t) {
        int n = s.size();
        vector<vector<int>> next(n, vector<int>(26, -1));
        for (int j = 0; j < 26; ++j) {
            for (int i = n - 1; i >= 0; --i) {
                if (s[i] == 'a' + j) {
                    next[i][j] = i;
                } else {
                    if (i + 1 < n) next[i][j] = next[i + 1][j];
                }
            }
            for (int i = n - 1; i >= 0; --i) {
                if (next[i][j] != -1) break;
                next[i][j] = next[0][j];
            }
        }
        int ans =  0;
        int i = n - 1;
        for (char ch : t) {
            ++i;
            if (i == n) {
                ++ans;
                i = 0;
            }
            int j = ch - 'a';
            if (next[i][j] == -1) return -1;
            if (next[i][j] < i) ++ans;
            i = next[i][j];
        }
    
        return ans;
    }
};
    
int main() {

    return 0;
}
