#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges

class Solution {
public:
    unordered_map<int, int> dp;
    int minDays(int n) {  
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (dp.count(n)) return dp[n];
        int ans = 1000000000;
        if (n % 2 == 0) ans = min(ans, minDays(n / 2) + 1);
        if (n % 2 == 1) ans = min(ans, minDays(n / 2) + 2);
        if (n % 3 == 0) ans = min(ans, minDays(n / 3) + 1);
        if (n % 3 == 1) ans = min(ans, minDays(n / 3) + 2);
        if (n % 3 == 2) ans = min(ans, minDays(n / 3) + 3);        
        dp[n] = ans;
        return ans;
    }
};

int main() {

    return 0;
}
