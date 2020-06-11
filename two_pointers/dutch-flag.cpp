#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://en.wikipedia.org/wiki/Dutch_national_flag_problem
// https://leetcode.com/problems/sort-colors
class Solution {
public:
    
    // the main function
    // invariants
    // - entries from 0 up to (but not including) i are values less than mid,
    // - entries from i up to (but not including) j are values equal to mid,
    // - entries from j up to (but not including) k are values not yet sorted, and
    // - entries from k to the end of the array are values greater than mid.
    void threeWayPartition(vector<int>& a, int mid) {
        int n = a.size();
        int i = 0;
        int j = 0;
        int k = n;
        while (j < k) {
          if (a[j] < mid) {
                swap(a[i], a[j]);
                ++i;
                ++j;
            } else if (a[j] > mid) {
                --k;
                swap(a[j], a[k]);
            } else {
                ++j;
            }
        }
    }
    void sortColors(vector<int>& a) {
        threeWayPartition(a, 1);
    }
};
    
int main() {

    return 0;
}
