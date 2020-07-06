#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/di-string-match

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int min_val = 0;
        int max_val = 0;
        vector<int> ans;
        ans.push_back(0);
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == 'D') {
                ans.push_back(min_val - 1);
                --min_val;
            } else {
                ans.push_back(max_val + 1);
                ++max_val;
            }
        }
        for (int i = 0; i < ans.size(); ++i) ans[i] -= min_val;
        return ans;
    }
};
    
int main() {

    return 0;
}
