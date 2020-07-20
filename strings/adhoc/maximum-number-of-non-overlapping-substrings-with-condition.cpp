#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> x(26, -1);
        vector<int> y(26, -1);
        
        int n = s.size();
        for (int j = 0; j < 26; ++j) {
            int from = -1;
            int to = -1;
            for (int i = 0; i < n; ++i) {
                if (s[i] != 'a' + j) continue;
                if (from == -1) from = i;
                to = i;
            }
            x[j] = from;
            y[j] = to;
        }
        
        vector<vector<int>> prefix(26, vector<int>(n, 0));
        for (int j = 0; j < 26; ++j) {
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'a' + j) {
                    prefix[j][i] = 1;
                }
                if (i > 0) {
                    prefix[j][i] += prefix[j][i - 1];
                }
            }
        }
        
        vector<string> ans;
        
        int prev = -1;
        for (int i = 0; i < n; ++i) {
            int j = s[i] - 'a';
            int from = x[j];
            int to = i;   
            bool can = true;
            while (true) {
                bool changed = false;
                for (int k = 0; k < 26; ++k) {
                    int sum = prefix[k][to];
                    if (from > 0) sum -= prefix[k][from - 1];
                    if (sum == 0) continue;
                    if (y[k] > to) {
                        can = false;
                        break;
                    }
                    if (x[k] < from) {
                        from = x[k];
                        changed = true;
                    }
                }
                if (!changed || !can) break;
            }
            if (!can) continue;
            if (from < prev) continue;
            prev = to;
            ans.push_back(s.substr(from, to - from + 1));
        }
        
        return ans;
    }
};
    
int main() {

    return 0;
}
