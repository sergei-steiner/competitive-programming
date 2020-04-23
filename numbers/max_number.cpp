#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/create-maximum-number

class Solution {
public:
    vector<int> max1(int k, vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            while (!result.empty() && result.size() + nums.size() - i - 1 >= k && result.back() < nums[i]) {
                result.pop_back();
            }
            if (result.size() < k) result.push_back(nums[i]);
        }
        return result;
    }
    
    vector<int> max2(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        while (i < n || j < m) {
            if (i == n) {
                result.push_back(nums2[j]);
                ++j;
                continue;
            }
            if (j == m) {
                result.push_back(nums1[i]);
                ++i;
                continue;
            }
            int i1 = i;
            int j1 = j;
            while (i1 < n && j1 < m && nums1[i1] == nums2[j1]) {
                ++i1;
                ++j1;
            }
            if (i1 == n) {
                result.push_back(nums2[j]);
                ++j;
                continue;
            }
            if (j1 == m) {
                result.push_back(nums1[i]);
                ++i;
                continue;
            }
            if (nums1[i1] <= nums2[j1]) {
                result.push_back(nums2[j]);
                ++j;
                continue;
            }
            if (nums1[i1] > nums2[j1]) {
                result.push_back(nums1[i]);
                ++i;
                continue;
            }
        }
        return result;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result;
        for (int i = 0; i <= k; ++i) {
            if (nums1.size() < i) continue;
            if (nums2.size() < k - i) continue;
            auto res1 = max1(i, nums1);
            auto res2 = max1(k - i, nums2);
            auto res12 = max2(res1, res2);
            result = max(result, res12);
        }
        
        return result;
        
     
    }

};
    
int main() {

    return 0;
}
