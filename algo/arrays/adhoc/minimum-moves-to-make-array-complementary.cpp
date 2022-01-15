  
#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-moves-to-make-array-complementary

// basically enumerate all targets
// and try to figure out the number of moves contantly

class Solution {
public:
    int minMoves(vector<int>& a, int limit) {
        int n = a.size();
        vector<int> cnt(2 * limit + 1, 0);
        vector<int> l(2 * limit + 1, 0);
        vector<int> r(2 * limit + 1, 0);
        for (int i = 0; i < n / 2; ++i) {
            ++cnt[a[i] + a[n - i - 1]];
            int left = min(a[i], a[n - i - 1]) + 1;
            int right = max(a[i], a[n - i - 1]) + limit;
            ++l[left];
            ++r[right];
        }
        
        int cur = 0;
        int ans = n;
        for (int i = 2; i <= 2 * limit; ++i) {
            cur += l[i];
            int cur0 = cnt[i];
            int cur1 = cur - cur0;
            int cur2 = n / 2 - cur1 - cur0;
            ans = min(ans, cur1 + 2 * cur2);
            cur -= r[i];
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
