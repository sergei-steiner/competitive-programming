#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

/*
can try here:
https://leetcode.com/problems/valid-parentheses
*/

bool isValid(const string& s) {
    stack<char> a;
    for (char ch : s) {
        if (ch == ')') {
            if (a.empty() || a.top() != '(') return false;
            a.pop();
            continue;
        }
        if (ch == '}') {
            if (a.empty() || a.top() != '{') return false;
            a.pop();
            continue;
        }
        if (ch == ']') {
            if (a.empty() || a.top() != '[') return false;
            a.pop();
            continue;
        }
        a.push(ch);
    }
    return a.empty();
}
    
int main() {
    string s;
    cin >> s;
    
    cout << isValid(s) << endl;
    
    return 0;
}

