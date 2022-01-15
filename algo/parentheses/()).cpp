#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string

class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        string str;
        for (int i = 0; i < s.size(); ) {
            if (s[i] == '(') {
                str += s[i];
                ++i;
                continue;
            }
            str += s[i];
            if (i + 1 == s.size() || s[i + 1] == '(') {
                ++ans;
                ++i;
            } else {
                i += 2;
            }
        }
        
        int sum = 0;
        int min_val = 0;
        for (char ch : str) {
            if (ch == '(') {
                ++sum;
            } else {
                --sum;
            }
            min_val = min(min_val, sum);
        }
        if (min_val < 0) { 
            ans -= min_val;
            sum -= min_val;
        }
        ans += 2 * sum;
        return ans;
    }
};
    
int main() {

    return 0;
}
