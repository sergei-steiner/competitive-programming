#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = s.size();
        int ans = 0;
        string result_s; // "stack"
        vector<int> result_cost; // "cost stack"
        for (int i = 0; i < n; ++i) {
            while (!result_s.empty() && result_s.back() == s[i]) {
                if (result_cost.back() < cost[i]) {
                    ans += result_cost.back();
                } else {
                    ans += cost[i];
                    cost[i] = result_cost.back();
                }
                result_s.pop_back();
                result_cost.pop_back();
            }
            result_s.push_back(s[i]);
            result_cost.push_back(cost[i]);
        }
        return ans;
    }
};

int main() {

    return 0;
}
