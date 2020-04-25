#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/bitwise-and-of-numbers-range

class Solution {
public:
    int rangeBitwiseOr(int m, int n) {
        long long ans = 0;
        for (long long i = 0; i < 31; ++i) {
            long long left = (long long)m >> i;
            long long right = (long long)n >> i;
            if (left != right || left & 1) ans += (1LL << i);
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
