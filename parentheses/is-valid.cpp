#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// (a * (b + c))
bool isValid1(const string& s) {
    int sum = 0;
    for (char ch : s) {
        if (ch == '(') ++sum;
        if (ch == ')') --sum;
        if (sum < 0) return false;
    }
    return sum == 0;
}

bool isValid3(const string& s) {
    stack<char> a;
    for (char ch : s) {
        if (ch == '[' || ch == '{' || ch == '(') {
            a.push(ch);
            continue;
        }
        if (ch == ']') {
            if (a.empty() || a.top() != '[') return false;
            a.pop();
        }
        if (ch == '}') {
            if (a.empty() || a.top() != '{') return false;
            a.pop();
        }
        if (ch == ')') {
            if (a.empty() || a.top() != '(') return false;
            a.pop();
        }
   }
   return a.empty();
}

// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        return isValid3(s);
    }
};
int main() {

    return 0;
}
