#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;



// https://leetcode.com/problems/jump-game/

bool canJump(vector<int>& a) {
    int n = a.size();
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (cur < i) return false;
        cur = max(cur, i + a[i]);
    }
    return true;
}
  
int main() {

    return 0;
}
