#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/missing-ranges

class Solution {
public:
    string toStr(int lower, int upper) {
        if (lower == upper) {
            stringstream ss;
            ss << lower;
            return ss.str();
        }
        stringstream ss;
        ss << lower;
        ss << "->";
        ss << upper;
        return ss.str();
    }
    vector<string> findMissingRanges(vector<int>& nums, int lo, int up) {
        long long lower = lo;
        long long upper = up;
        vector<string> ans;
        for (long long x : nums) {
            if (lower < x) {
                ans.push_back(toStr(lower, x - 1));
            }
            lower = x + 1;
        }
        if (lower <= upper) {
            ans.push_back(toStr(lower, upper));
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
