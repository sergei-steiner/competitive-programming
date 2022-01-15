#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/line-reflection/
// O(n) if one adds hash function for pairs 

class Solution {
public:
    bool isReflected(vector<vector<int>>& p) {
        int x_min = numeric_limits<int>::max();
        int x_max = numeric_limits<int>::min();
        for (auto v : p) {
            x_min = min(x_min, v[0]);
        }
        for (auto v : p) {
            x_max = max(x_max, v[0]);
        }
        int x = (x_min + x_max);
        set<pair<int, int>> a;
        for (auto v : p) {
            a.emplace(2 * v[0], v[1]);
        }
        for (auto v : p) {
            if (a.count({x - (2 * v[0] - x), v[1]}) == 0) return false;
        }
        return true;
    }
};
    
int main() {

    return 0;
}
