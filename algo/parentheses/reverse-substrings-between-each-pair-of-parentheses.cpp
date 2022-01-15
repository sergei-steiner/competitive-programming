#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// O(n) idea https://developersinspired.com/2020/04/05/reverse-substrings-between-each-pair-of-parentheses/

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> st;
        vector<int> p(n, -1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            }
            if (s[i] == ')') {
                int j = st.top();
                p[i] = j;
                p[j] = i;
                st.pop();
            }
        }
        string ans;
        int d = 1;
        for (int i = 0; i < n; i += d) {
            if (s[i] == '('  || s[i] == ')') {
                i = p[i];
                d = -d;
            } else {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
