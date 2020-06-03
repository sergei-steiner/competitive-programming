#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// weirdly simple idea
// https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings

class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        vector<int> ans;
        int cur = 1;
        for (char ch : s) {
            if (ch == '(') {
                cur ^= 1;
                ans.push_back(cur);
            } else {
                ans.push_back(cur);
                cur ^= 1;
            }
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
