#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<int> bought(n, 0);
        vector<int> free(n, 0);
        bought[0] = - prices[0];
        for (int i = 1; i < n; ++i) {
            bought[i] = bought[i - 1];
            int add = 0;
            if (i >= 2) add = free[i - 2];
            bought[i] = max(bought[i], -prices[i] + add);
            free[i] = max(bought[i - 1] + prices[i], free[i - 1]);
        }
        return max(bought[n - 1], free[n - 1]);
    }
};   
  
int main() {

    return 0;
}
