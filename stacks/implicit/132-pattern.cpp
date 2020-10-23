#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/132-pattern

// https://leetcode.com/problems/132-pattern/discuss/906876/Python-O(n)-solution-with-decreasing-stack-explained

class Solution {
public:
    bool find132pattern(vector<int>& a) {
        int n = a.size();
        vector<int> min_val = a;
        for (int i = 1; i < n; ++i) min_val[i] = min(min_val[i - 1], a[i]);
        stack<int> st;
        for (int j = n - 1; j > 0; --j) {
            if (min_val[j] == a[j]) continue;
            while (!st.empty() && min_val[j] >= st.top()) st.pop();
            if (!st.empty() && a[j] > st.top()) return true;
            st.push(a[j]);
        }
        return false;
    }
};
    
int main() {

    return 0;
}
