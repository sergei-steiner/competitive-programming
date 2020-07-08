#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/number-of-valid-subarrays

class Solution {
public:
    int validSubarrays(vector<int>& a) {
        int n = a.size();
        stack<int> st;
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && a[st.top()] >= a[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans += n - i;
            } else {
                ans += st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {

    return 0;
}
