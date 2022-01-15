#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/numbers-with-repeated-digits

// naive
class Solution {
public:
    int cnt = 0;
    int n = 0;
    void rec(long long x, int mask) {
        if (x > n) return;
        ++cnt;
        if (mask == 1023) {
            return;
        }
        for (int i = 0; i < 10; ++i) {
            if (mask & (1 << i)) {
               continue;  
            }
            rec(10 * x + i, mask ^ (1 << i));
        }
    }
    int numDupDigitsAtMostN(int N) {
        n = N;
        for (int i = 1; i <= 9; ++i) {
            rec(i, 1 << i);
        }
        return n - cnt;
    }
};

int main() {
}
