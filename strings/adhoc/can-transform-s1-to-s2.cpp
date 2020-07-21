#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/string-transforms-into-another-string

class Solution {
public:
    bool canConvert(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) {
            return false;
        }
        unordered_map<char, char> a;
        unordered_set<char> b;
        for (int i = 0; i < s1.length(); ++i) {
            if (a.count(s1[i]) == 0) {
                a[s1[i]] = s2[i];
            }
            if (a[s1[i]] != s2[i]) {
                return false;
            }
            b.insert(s2[i]);
        }
        if (a.size() == 26 && b.size() == 26) return false;
        return true;
    }
};
    
int main() {

    return 0;
}
