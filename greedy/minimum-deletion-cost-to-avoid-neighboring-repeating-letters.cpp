#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters

// very simple problem


// the first two solutions are very straightforward
// if we have two equals, just delete the cheapest
// no need for stack, just one comparison is somehow always enough

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

// now, in a nutshell
// we just need to substract sum of all max costs for groups of equals from sum of all numbers

class Solution3 {
public:
    int minCost(string s, vector<int>& cost) {
        int n = s.size();
        int sum = 0;
        int sum_max = 0;
        int max_val = 0; 
        for (int i = 0; i < n; ++i) {
            sum += cost[i];
            if (i == 0 || s[i] == s[i - 1]) {
                max_val = max(max_val, cost[i]);
            } else {
                sum_max += max_val;
                max_val = cost[i];
            }
        } 
        sum_max += max_val;
        return sum - sum_max;
    }
};

int main() {

    return 0;
}
