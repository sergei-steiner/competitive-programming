#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string t;
        int cnt = 0;
        for (char ch : s) {
            if (ch == ')') {
                if (cnt == 0) continue;
                --cnt;
            }
            if (ch == '(') {
                ++cnt;
            }
            t.push_back(ch);
        }
        s = t;
        t = "";
        reverse(begin(s), end(s));
        cnt = 0;
        for (char ch : s) {
            if (ch == '(') {
                if (cnt == 0) continue;
                --cnt;
            }
            if (ch == ')') {
                ++cnt;
            }
            t.push_back(ch);
        }
        s = t;
        reverse(begin(s), end(s));
        return s;
    }
};
    
int main() {

    return 0;
}
© 2020 GitHub, Inc.
