#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-factorization

class Solution {
public:
    int smallestFactorization(int a) {
        if (a == 1) return 1;
        long long ans = 0; 
        long long d = 1;
        for (int i = 9; i >= 2; --i) {
            while (a % i == 0) {
                a /= i;
                ans += d * i;
                if (ans > numeric_limits<int>::max()) {
                    return 0;
                }
                d *= 10;
            }
        }
        if (a > 1) return 0;
        return ans;
    }
};
    
int main() {

    return 0;
}
