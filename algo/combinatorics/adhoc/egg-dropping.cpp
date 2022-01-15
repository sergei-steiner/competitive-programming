#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://brilliant.org/wiki/egg-dropping/
// https://leetcode.com/problems/super-egg-drop/
// O(K log N) without taking C(n, k) into account

class Solution {
public:
    map<pair<int, int>, int> C_dp;
    int C(int n, int k) {
        if (k < 0) return 0;
        if (k > n) return 0;
        if (n == 0) return 1; // k = 0
        if (C_dp.count({n, k})) return C_dp[{n, k}];
        int ans = C(n - 1, k - 1) + C(n - 1, k);
        C_dp[{n, k}] = ans;
        return ans;
    }
    
    int superEggDrop(int K, int N) {
        int left = 0;
        int right = N;
        while(right - left > 1) {
            int d = left + (right - left) / 2;
            int sum = 0;
            for (int i = 1; i <= K; ++i) {
                sum += C(d, i);
                if (sum >= N) break;
            }
            if (sum < N) {
                left = d;
            } else {
                right = d;
            }
        }
        return left + 1;
    }
};

int main() {
    
    return 0;
}
