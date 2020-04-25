#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        while (i < n) {
            while (j < n && nums[j] == 0) ++j;
            if (j < n) swap(nums[i], nums[j]);
            ++j;
            ++i;
        }
    }
};
    
int main() {

    return 0;
}
