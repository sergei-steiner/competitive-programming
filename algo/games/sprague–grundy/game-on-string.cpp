#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/flip-game-ii

class Solution {
public:
    unordered_map<string, int> dp;
    
    int solve(string s) {
        if (dp.count(s)) return dp[s];
        unordered_set<int> vals;
        int n = s.size();
        for (int i = 0; i + 1 < n; ++i) {
           if (s[i] == '+' && s[i + 1] == '+') {
               vals.insert(solve(s.substr(0, i)) ^ solve(s.substr(i + 2)));
           }
        }
        for (int i = 0; ; ++i) {
            if (vals.count(i) == 0) {
                dp[s] = i;
                return i;
            }
        }
    }
    
    bool canWin(string s) {
        return solve(s) != 0;
    }
};
  
int main() {

    return 0;
}
