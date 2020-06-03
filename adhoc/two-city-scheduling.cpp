#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;


// really nice idea
// https://leetcode.com/problems/two-city-scheduling

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& a) {
        int ans = 0;
        for (auto x : a) ans += x[0];
        vector<int> b;
        for (auto x : a) b.push_back(x[1] - x[0]);
        sort(b.begin(), b.end());
        for (int i = 0; i < a.size() / 2; ++i) 
            ans += b[i];
        return ans;
    }
};
    
int main() {

    return 0;
}
