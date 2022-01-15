#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

// https://leetcode.com/problems/count-submatrices-with-all-ones
// O(nm)

class Solution {
public:
    int numSubmat(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            stack<int> st;
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                if (i >= 1 && a[i][j] == 1) a[i][j] += a[i - 1][j];
                while (!st.empty() && a[i][st.top()] > a[i][j]) {
                    int k1 = st.top();
                    st.pop();
                    int k2 = -1;
                    if (!st.empty()) k2 = st.top();
                    cnt -= (k1 - k2) * (a[i][k1] - a[i][j]);
                    
                }
                st.push(j);
                cnt += a[i][j];
                ans += cnt;
            }
        }
        return ans;
    }
};



using namespace std;
    
int main() {

    return 0;
}
