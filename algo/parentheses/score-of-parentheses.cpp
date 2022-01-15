#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/score-of-parentheses/

// just simple linear solution instead of recursion

class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int ans = 0;
        int balance = 0;
        for (int i = 0; i + 1 < n; ++i) {
            if (s[i] == '(') {
                ++balance;
            } else {
                --balance;
            }
            if (s[i] == '(' && s[i + 1] == ')') {
                ans += 1 << (balance - 1);
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}
   
