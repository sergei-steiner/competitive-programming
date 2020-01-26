#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/merge-intervals

vector<vector<int>> merge(vector<vector<int>>& a) {
    int n = a.size();
    if (n == 0) return {};
    vector<pair<int, int>> b;
    for (int i = 0; i < n; ++i) {
        b.emplace_back(a[i][0], -1);
        b.emplace_back(a[i][1], 1);
    }
    sort(b.begin(), b.end());
    vector<vector<int>> ans;
    int sum = 0;
    int prev = b[0].first;
    for (int i = 0; i < b.size(); ++i) {
        auto& [x, val] = b[i];
        sum += val;
        if (sum == 0) {
             ans.push_back({prev, x});
             if (i + 1 < b.size()) prev = b[i + 1].first;
        }
    }
    return ans;
}
   
int main() {

    return 0;
}
