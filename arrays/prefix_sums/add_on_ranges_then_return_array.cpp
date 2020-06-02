#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/corporate-flight-bookings
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& add, int n) {
        vector<int> ans(n, 0);
        for (auto q : add) {
            int i = q[0];
            int j = q[1];
            int k = q[2];
            --i;
            --j;
            ans[j] += k;
            if (i > 0) ans[i - 1] -= k;
        }
        for (int i = n - 1; i > 0; --i) {
            ans[i - 1] += ans[i];
        }
        return ans;
    }
};

int main() {

    return 0;
}
