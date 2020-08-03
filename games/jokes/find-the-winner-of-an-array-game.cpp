#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/find-the-winner-of-an-array-game
// max(a) always wins, if it's its turn
// so no need for complex simulation
// just a single array scan should be enough

class Solution {
public:
    int getWinner(vector<int>& a, int k) {
        int n = a.size();
        int cnt = 0;
        int cur = a[0];
        for (int i = 1; i < n; ++i) {
            if (cur < a[i]) {
                cur = a[i];
                cnt = 0;
            }
            ++cnt;
            if (cnt == k) return cur;
        }
        return cur;
    }
};
    
int main() {

    return 0;
}
