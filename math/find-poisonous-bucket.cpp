#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/poor-pigs

// https://leetcode.com/problems/poor-pigs/discuss/935112/Python-Math-solution-detailed-expanations

// (t + 1)^ans >= n

// I kind of knew the solution for one turn
// so I came up with inductive step for two turn
// wich turned out to be binomial formula for (1 + 2)^n
// the subsequent steps are kind of obvious

// but the solution above is easier to digest
// the key point is that you can actually get it AC in 2 minutes
// but assessing the max amount of information one can get
// which is exactly (t + 1)^ans
// (then you'd better prove you can actually get it)

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
