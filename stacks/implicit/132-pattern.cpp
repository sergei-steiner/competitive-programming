#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/132-pattern

// https://leetcode.com/problems/132-pattern/discuss/906876/Python-O(n)-solution-with-decreasing-stack-explained
// enumerating middle element, min array + stack

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

// https://leetcode.com/problems/132-pattern/discuss/906789/Short-Java-O(N)-Solution-with-Detailed-Explanation-and-Sample-Test-Case-or-Stack-or-100
// enumerating first element, just one stack

class Solution2 {
public:
    bool find132pattern(vector<int>& a) {
        int n = a.size();
        int second = numeric_limits<int>::min();
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] < second) return true;
            while (!st.empty() && a[i] > st.top()) {
                second = st.top();
                st.pop();
            }
            st.push(a[i]);
        }
        return false;
    }
};
    
int main() {

    return 0;
}
