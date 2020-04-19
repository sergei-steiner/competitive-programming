#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n = a.size();
        for (int i = 1; i < n; ++i) a[i] += a[i - 1];
        int ans = 0;
        int i = 0;
        int j = 0;
        while (j < n) {
            int sum = a[j];
            if (i > 0) sum -= a[i - 1];
            if (sum + k >= j - i + 1) {
                ++j;
                ans = max(ans, j - i);
            } else {
                ++i;
                if (j < i) j = i;
            }
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
