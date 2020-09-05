#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/

class Solution {
public:
    bool containsPattern(vector<int>& a, int m, int k) {
        int cnt = 0;
        int n = a.size();
        for (int i = 0; i + m < n; ++i) {
            if (a[i] != a[i + m]) {
                cnt = 0;
            } else {
                cnt++;
            }
            if (cnt == (k - 1) * m) return true;
        }
        return false ;
    }
};
    
int main() {

    return 0;
}
