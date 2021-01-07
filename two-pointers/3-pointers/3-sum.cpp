#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/3sum/

vector<vector<int>> threeSum(vector<int>& a) {
    int n = a.size();
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    for (int i = 0; i + 2 < n; ++i) {
         if (i > 0 && a[i] == a[i - 1]) continue;
         int j = i + 1;
         int k = n - 1;
         while (j < k) {
            if (j > i + 1 && a[j] == a[j - 1]) {
                ++j;
                continue;
            }
            if (k + 1 < n && a[k] == a[k + 1]) {
                --k;
                continue;
            }
            int sum = a[i] + a[j] + a[k]; 
            if (sum > 0) {
                --k;
            } else if (sum < 0) {
                 ++j;
            } else {
                ans.push_back({a[i],  a[j],  a[k]});
                ++j;
                --k;
            }
        }
    }
    return ans;
}

int main() {

    return 0;
}
