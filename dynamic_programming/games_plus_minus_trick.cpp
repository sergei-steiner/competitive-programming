#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;


// https://leetcode.com/problems/stone-game-iii

class Solution {
public:
    string stoneGameIII(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = a[i] - dp[i + 1];
            if (i + 2 <= n) dp[i] = max(dp[i], a[i] + a[i + 1] - dp[i + 2]);
            if (i + 3 <= n) dp[i] = max(dp[i], a[i] + a[i + 1] + a[i + 2] - dp[i + 3]);
        }
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie" ;  
    }
};
    
int main() {

    return 0;
}
