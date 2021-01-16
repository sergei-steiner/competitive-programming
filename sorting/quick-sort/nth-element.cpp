#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        int n = a.size();
        k = n - k;
        return findKthSmallest(a, k);
    }
    int findKthSmallest(vector<int>& a, int k, int l = 0, int r = numeric_limits<int>::max()) {
        int n = a.size();
        if (r >= n) r = n - 1;
        if (l == r) return a[l];
        int m = l + rand() % (r - l + 1);
        int x = a[m];
        int i = l;
        int j = r;
        while (i <= j) {
            while (a[i] < x) ++i;
            while (a[j] > x) --j;
            if (i <= j) {
                swap(a[i], a[j]);
                ++i;
                --j;
            }
        if (j - l >= k) return findKthSmallest(a, k, l, j);
        if (i - l <= k) return findKthSmallest(a, k - (i - l), i, r);
        return x;
    }
};
    
int main() {

    return 0;
}
