#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;


// qsort via three way partition aka dutch flag problem 
// not the simplest implementation
// but the one I am confident I can implement in time scramble
// check https://github.com/sergei-steiner/competitive-programming/blob/master/two_pointers/dutch-flag.cpp for details
// https://leetcode.com/problems/sort-an-array
class Solution {
public:
    pair<int, int> threeWayPartition(vector<int>& a, int l, int r, int mid) {
        int i = l;
        int j = l;
        int k = r + 1;
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
        return {i, j};
    }

    void qsort(vector<int>& a, int l = 0, int r = numeric_limits<int>::max()) {
        int n = a.size();
        if (r > n) r = n - 1;
        if (r <= l) return;
        int mid = a[l + rand() % (r - l + 1)];
        auto [i, j] = threeWayPartition(a, l, r, mid);
        qsort(a, l, i - 1);
        qsort(a, j, r);
    }
    
    vector<int> sortArray(vector<int>& nums) {
       qsort(nums);
       return nums;
    }
};
    
int main() {

    return 0;
}
