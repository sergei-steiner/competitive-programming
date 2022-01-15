#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range

class Solution {
public:
    int count(int n) {
        if (n < 0) return 0;
        return (n + 1) / 2;
    }
    int countOdds(int l, int h) {
        return count(h) - count(l - 1);
    }
};
    
int main() {

    return 0;
}
