#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/find-longest-awesome-substring

class Solution {
public:
    int longestAwesome(string s) {
        int ans = 0;
        int n = s.size();
        int m = 10;
        int inf = 1000000000;
        vector<int> prev((1 << m), inf);
        prev[0] = -1;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            cur ^= (1 << d);
            ans = max(ans, i - prev[cur]);
            for (int odd = 0; odd < m; ++odd) {
                ans = max(ans, i - prev[cur ^ (1 << odd)]);
            }
            
            if (prev[cur] == inf) prev[cur] = i;
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
