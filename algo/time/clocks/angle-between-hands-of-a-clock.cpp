#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/angle-between-hands-of-a-clock

class Solution {
public:
    double angleClock(int h, int m) {
        if (h == 12) h = 0;
        double x = 1.0 * (h + 1.0 * m / 60)  / 12 * 360;
        double y = 1.0 * m / 60 * 360;
        double ans = abs(x - y);
        return min(ans, 360 - ans);
    }
};
    
int main() {

    return 0;
}
