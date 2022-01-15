#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        for (int k = n + m - 1; k >= 0; --k) {
            if (i < 0) {
                nums1[k] = nums2[j];
                --j;
                continue;
            }
            if (j < 0) {
                nums1[k] = nums1[i];
                --i;
                continue;
            }
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                --i;
                continue;
            }
            nums1[k] = nums2[j];
            --j;
        }
    }
};
    
int main() {

    return 0;
}
