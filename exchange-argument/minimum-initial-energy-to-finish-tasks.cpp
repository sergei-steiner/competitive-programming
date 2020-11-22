#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks

/* 

The basic idea is to sort everything by m - a

I came up with it via exchange argument method

*/

// so no we can just perform binary search
// only to get TLE

class SolutionTLE {
public:
    bool ok(int total, const vector<vector<int>>& tasks) {
        for (auto v : tasks) {
            int a = v[0];
            int m = v[1];
            if (total < m) return false;
            total -= a;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(begin(tasks), end(tasks), [=](auto x, auto y) {
            return x[0] - x[1] < y[0] - y[1];
        });
        int l = 0;
        int r = 1000000000;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (ok(m, tasks)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        for (int i = l; i <= r; ++i) {
            if (ok(i, tasks)) {
                return i;
            }
        }
        return -1;
        
    }
};

// the next idea: calculate answer from reverse!
// still TLE

class SolutionTLE2 {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(begin(tasks), end(tasks), [=](auto x, auto y) {
            return x[0] - x[1] > y[0] - y[1];
        });
        int ans = 0;
        for (auto v : tasks) {
            int a = v[0];
            int m = v[1];
            ans = max(ans + a, m);
        }
        return ans;
    }
};

// ok, just sort in linear time now

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int N = 10000;
        vector<vector<pair<int, int>>> sorted(N + 1);
        for (const auto& v : tasks) {
            int a = v[0];
            int m = v[1];
            sorted[m - a].emplace_back(a, m);
        }
        int ans = 0;
        for (int i = 0; i <= N; ++i) {
            for (const auto& [a, m] : sorted[i]) {
                ans = max(ans + a, m);
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}
