#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
// very nice yet simple trickery

class Solution {
public:
    int findTheLongestSubstring(string s) {
        string v = "aeiou";
        int n = s.size();
        unordered_map<int, int> a;
        a[0] = -1;
        vector<int> cnt(5, 0);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int profile = 0;
            for (int j = 0; j < 5; ++j) {
                if (s[i] == v[j]) {
                    cnt[j] ^= 1;
                }
                if (cnt[j]) profile += (1 << j);
            }
            if (a.count(profile)) {
                ans = max(ans, i - a[profile]);
            } else {
                a[profile] = i;
            }
        }
        
        return ans;
    }
};
    
int main() {

    return 0;
}
