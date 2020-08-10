#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/longest-well-performing-interval

// very nice idea, based on continuity of prefix sums, 
// for sum <= 0 we need only first occurence of sum - 1 
// (it would precede any occurences of sum - 2, sum - 3 etc. )
// for sum > 0 we always need the prefix itself

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) a[i] = 2 * (hours[i] > 8) - 1;
        int ans = 0;
        unordered_map<int, int> pos;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (sum > 0) {
                ans = i + 1;
            } else {
                if (pos.count(sum - 1)) {
                    ans = max(ans, i - pos[sum - 1]);
                }
            }
            if (pos.count(sum) == 0) pos[sum] = i;
        }
        return ans;
    }
};

// note: anyways, there is O(n) solution without this trick
// two pointers + max prefixes on suffix precalc

/*

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) a[i] = 2 * (hours[i] > 8) - 1;
        for (int i = 1; i < n; ++i) a[i] += a[i - 1];
        vector<pair<int, int>> prefix;
        for (int i = 0; i < n; ++i) {
            prefix.emplace_back(a[i], i + 1);
        }
        prefix.emplace_back(0, 0);
        sort(begin(prefix), end(prefix));
        vector<int> max_val(n + 1, 0);
        max_val[n] = prefix[n].second;
        for (int i = n - 1; i >= 0; --i) {
            max_val[i] = max(max_val[i + 1], prefix[i].second);
        }
        int ans = 0;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j <= n && prefix[j].first - prefix[i].first <= 0) ++j;
            if (j <= n && prefix[j].first - prefix[i].first > 0) {
                ans = max(ans, max_val[j] - prefix[i].second);
            }
        }
        return ans;
    }
};

*/

int main() {

    return 0;
}
