#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// increase step by step technique

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    set<char> used;
    int i = 0;
    int j = 0;
    int ans = 0;
    while (j < n) {
        if (!used.count(s[j])) {
            used.insert(s[j]);
            ans = max(ans, j - i + 1);
            ++j;
        } else {
            used.erase(s[i]);
            ++i;
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}
