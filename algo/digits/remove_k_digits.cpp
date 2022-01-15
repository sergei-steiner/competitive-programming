#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
    
//https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for (int i = 0; i < num.size(); ++i) {
            while (ans.size() > 0 && k > 0 && ans.back() > num[i]) {
                ans.pop_back();
                --k;
            }
            ans.push_back(num[i]);
        }
        while (k > 0) {
            ans.pop_back();
            --k;
        }
        while (ans.size() > 1 && ans[0] == '0') ans = ans.substr( 1 );
        if (ans.empty()) ans = "0";
        return ans;
    }
};
int main() {

    return 0;
}
