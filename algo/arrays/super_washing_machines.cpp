#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/super-washing-machines/

int findMinMoves(vector<int>& A) {
    int n = A.size();
    int sum = 0;
    for (int x : A) sum += x;
    if (sum % n != 0) return -1;
    int target = sum / n;
    int cur = 0;
    int ans = 0;
    for (int x : A) {
        cur += (x - target);
        ans = max(ans, abs(cur));
        ans = max(ans, x - target);
    }
    return ans;
}
    
int main() {

    return 0;
}
