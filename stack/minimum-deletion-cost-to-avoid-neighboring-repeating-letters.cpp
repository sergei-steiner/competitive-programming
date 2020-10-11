#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters

// this one is the simplest, but it modifies the cost array!
// I used stack first, but the you actually don't need one, 
// no while pop loop here, just one if is enough to go 

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = s.size();
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i - 1] == s[i]) {
                if (cost[i - 1] < cost[i]) {
                    ans += cost[i - 1];
                } else {
                    ans += cost[i];
                    cost[i] = cost[i - 1];
                }
            }
        }
        return ans;
    }
};

// the very same, but without modifying cost array

class Solution2 {
public:
    int minCost(string s, vector<int>& cost) {
        int n = s.size();
        int ans = 0;
        int prev = cost[0];
        for (int i = 1; i < n; ++i) {
            if (s[i - 1] == s[i]) {
                if (prev < cost[i]) {
                    ans += prev;
                    prev = cost[i];
                } else {
                    ans += cost[i];
                }
            } else {
                prev = cost[i];
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}
