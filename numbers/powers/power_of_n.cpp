#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/power-of-two/

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    if (n & (n - 1)) return false;
    return true;
}

int main() {

    return 0;
}
