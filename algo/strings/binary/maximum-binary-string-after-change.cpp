#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/maximum-binary-string-after-change

// adhoc
// good explanation is here:
// https://leetcode.com/problems/maximum-binary-string-after-change/discuss/987335/JavaC%2B%2BPython-Solution-with-Explanation

class Solution {
public:
    string maximumBinaryString(string s) {
        int n = s.size();
        int leadingOnes = n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                leadingOnes = i;
                break;
            }
        }
        int zeros = 0;
        for (char ch : s) {
            if (ch == '0') ++zeros;
        }
        int ones = n - zeros - leadingOnes;
        string ans = string(leadingOnes, '1');
        if (zeros) ans += string(zeros - 1, '1');
        if (zeros) ans += '0';
        ans += string(ones, '1');
        return ans;
    }
};
    
int main() {

    return 0;
}
