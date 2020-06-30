#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
    
// https://leetcode.com/problems/beautiful-array

class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<vector<int>> ans(N + 10);
        ans[1] = {1};
        ans[2] = {1, 2};
        for (int i = 3; i <= N; ++i) {
            if (i % 2 == 0) {
                for (int j = 0; j < i / 2; ++j) {
                    ans[i].push_back(2 * ans[i / 2][j] - 1);
                }
                for (int j = 0; j < i / 2; ++j) {
                    ans[i].push_back(2 * ans[i / 2][j]);
                }
            } else {
                for (int j = 0; j < i / 2 + 1; ++j) {
                    ans[i].push_back(2 * ans[i / 2 + 1][j] - 1);
                }
                for (int j = 0; j < i / 2; ++j) {
                    ans[i].push_back(2 * ans[i / 2][j]);
                }
            }
        }
        return ans[N];
    }
};

int main() {

    return 0;
}
