#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (int x : left) ans = max(ans, x);
        for (int x : right) ans = max(ans, n - x);
        return ans;
    }
};
    
int main() {

    return 0;
}
