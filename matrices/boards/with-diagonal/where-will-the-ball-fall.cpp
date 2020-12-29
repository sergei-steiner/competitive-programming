#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/where-will-the-ball-fall

// obvious observation: we can just iterate over all possible entry points
// and simulate it
// cause no two paths intersect

// my solution: keep track of x, y and up/down state

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        vector<int> ans(n, -1);
        for (int j = 0; j < n; ++j) {
            int x = 0;
            int y = j;
            bool up = true;
            while (true) {
                if (x == m) {
                    ans[j] = y;
                    break;
                }
                if (y < 0 || y >= n) {
                    break;
                }
                if (a[x][y] == 1) {
                    if (up) {
                        if (y + 1 < n && a[x][y + 1] != -1) {
                            ++y;
                            up = false;
                        } else {
                            break;
                        }
                    } else {
                        ++x;
                        up = true;
                    }
                } else {
                    if (up) {
                        if (y > 0 && a[x][y - 1] != 1) {
                            --y;
                            up = false;
                        } else {
                            break;
                        }
                    } else {
                        ++x;
                        up = true;
                    }
                }
            }
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
