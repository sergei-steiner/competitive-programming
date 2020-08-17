    
#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int buy1 = numeric_limits<int>::max();
        int sell1 = 0;
        int buy2 = numeric_limits<int>::max();
        int sell2 = 0;
        for (int x : p) {
            sell2 = max(sell2, x - buy2);
            buy2 = min(buy2, x - sell1);
            sell1 = max(sell1, x - buy1);
            buy1 = min(buy1, x);
        }
        return sell2;
    }
};

int main() {

    return 0;
}
