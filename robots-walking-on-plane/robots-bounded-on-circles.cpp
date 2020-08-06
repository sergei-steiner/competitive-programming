#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/robot-bounded-in-circle

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        int dx = 1;
        int dy = 0;
        string s = instructions;
        s += s;
        s += s;
        for (char ch : s) {
            if (ch == 'G') {
                x += dx;
                y += dy;
            }
            if (ch == 'L') {
                int ndx = dy;
                int ndy = -dx;
                dx = ndx;
                dy = ndy;
            }
            if (ch == 'R') {
                int ndx = dy;
                int ndy = dx;
                dx = ndx;
                dy = ndy;
            }
        }
        return x == 0 && y == 0;
    }
};
    
int main() {

    return 0;
}
