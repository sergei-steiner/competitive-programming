#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/one-edit-distance

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n > m) return isOneEditDistance(t, s);
        if (abs(n - m) > 1) return false;
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                if (n == m) return s.substr(i + 1) == t.substr(i + 1);
                if (n != m) return s.substr(i) == t.substr(i + 1);
            }
        }
        return n + 1 == m;
    }
};


    
int main() {

    return 0;
}
