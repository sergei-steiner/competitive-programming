#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/poor-pigs

class Solution {
public:
    int poorPigs(int n, int minutesToDie, int minutesToTest) {
        int steps = (minutesToTest + minutesToDie - 1) / minutesToDie;
        return ceil(log(n) / log(steps + 1));
    }
};
    
int main() {

    return 0;
}
