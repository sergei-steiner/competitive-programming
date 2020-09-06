#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& a) {
        int n = a.size();
        bool sorted = true;
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] > a[i + 1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            return 0;
        }
        vector<int> l;
        l.push_back(a[0]);
        for (int i = 1; i < n; ++i) {
            if (a[i - 1] <= a[i]) {
                l.push_back(a[i]);
            } else {
                break;
            }
        }
        vector<int> r;
        r.push_back(a[n - 1]);
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] <= a[i + 1]) {
                r.push_back(a[i]);
            } else {
                break;
            }
        }        
        reverse(begin(r), end(r));
        int ans = r.size();
        int j = 0;
        for (int i = 0; i < l.size(); ++i) {
            while (j < r.size() && l[i] > r[j]) ++j;
            ans = max(ans, i + 1 + (int)r.size() - j);
        }
        ans = n - ans;
        return ans;
    }
};
    
int main() {

    return 0;
}
