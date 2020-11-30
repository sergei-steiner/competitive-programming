#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/find-the-most-competitive-subsequence

// kind of straightforward
// O(n log n)

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> a;
        for (int i = 0; i + k <= n; ++i) {
            a.insert(nums[i]);
        }
        int j = n - k + 1;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (ans.size() == k) {
                break;
            }
            if (nums[i] == *(a.begin())) {
                ans.push_back(nums[i]);
                if (j < n) a.insert(nums[j]);
                ++j;
            }
            a.erase(a.find(nums[i]));
        }
        return ans;
    }
};

// stack based
// O(n)

class Solution2 {
public:
    vector<int> mostCompetitive(vector<int>& a, int k) {
        int n = a.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            while (!ans.empty() && ans.back() > a[i] && ans.size() - 1 + n - i >= k) {
                ans.pop_back();
            }
            if (ans.size() < k) ans.emplace_back(a[i]);
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
