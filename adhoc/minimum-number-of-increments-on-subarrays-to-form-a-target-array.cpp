#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array

class Solution {
public:
    int minNumberOperations(vector<int>& a) {
        int n = a.size();
        int ans = a[0];
        for (int i = 1; i < n; ++i) {
            ans += max(0, a[i] - a[i - 1]);
        }
        
        return ans;
    }
};
    
int main() {

    return 0;
}
