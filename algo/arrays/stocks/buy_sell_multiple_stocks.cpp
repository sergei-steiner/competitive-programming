    
#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

int maxProfit(const vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0; 
    vector<int> dp1(n);
    vector<int> dp2(n);
    dp1[0] = 0;
    dp2[0] = -prices[0];
    for (int i = 1; i < n; ++i) {
         dp1[i] = max(dp1[i - 1], dp2[i - 1] + prices[i]);
         dp2[i] = max(dp2[i - 1], dp1[i - 1] - prices[i]);
    }
    return dp1[n - 1];
 }

int maxProfitValleyPeak(const vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    int i = 0;
    int valley = prices[0];
    int peak = prices[0];
    int ans = 0;
    while (i + 1 < n) {
        while (i + 1 < n && prices[i] >= prices[i + 1]) ++i;
        valley = prices[i];
        while (i + 1 < n && prices[i] <= prices[i + 1]) ++i;
        peak = prices[i];
        ans += peak - valley;
    }
    return ans;
}


int maxProfitSimplest(const vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0; 
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (prices[i + 1] > prices[i]) {
            ans += prices[i + 1] - prices[i];
        }
    }
    return ans;
 }


int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << maxProfit(a) << " " << maxProfitValleyPeak(a) << " " << maxProfitSimplest(a) << endl;
    return 0;
}
