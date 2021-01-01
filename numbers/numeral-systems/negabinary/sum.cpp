#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/adding-two-negabinary-numbers/

// a bit memory-suboptimal
// could be easily optimized

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        reverse(begin(arr1), end(arr1));
        reverse(begin(arr2), end(arr2));
        while (arr1.size() < arr2.size()) arr1.push_back(0);
        while (arr2.size() < arr1.size()) arr2.push_back(0);
        vector<int> ans(arr1.size() + 2, 0);
        for (int i = 0; i + 1 < ans.size(); ++i) {
            if (i < arr1.size()) ans[i] += arr1[i] + arr2[i];
            if (ans[i] == 0 || ans[i] == 1) continue;
            if (ans[i] > 1) {
                ans[i + 1] -= ans[i] / 2;
                ans[i] = ans[i] % 2;
                continue;
            }
            if (ans[i] < 0) {
                ans[i + 1] += (-ans[i] + 1) / 2;
                ans[i] = -ans[i] % 2;
            }
        }
        while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
        reverse(begin(ans), end(ans));
        return ans;
    }
};
    
int main() {

    return 0;
}
