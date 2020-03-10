#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/reorganize-string/

string reorganizeString(string s) {
    int n = s.size();
    unordered_map<char, int> count;
    for (char ch : s) ++count[ch];
    vector<pair<int, char>> a;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        a.emplace_back(count[ch], ch);
    }
    sort(begin(a), end(a));
    reverse(begin(a), end(a));
    vector<char> result(n);
    int j = 0;
    for (auto [cnt, ch] : a) {
        for (int i = 0; i < cnt; ++i) {
            result[j] = ch;
            j += 2;
            if (j >= n) j = 1;
        }
    }
    string ans;
    for (int i = 0; i < n; ++i) {
        ans.push_back(result[i]);
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (ans[i] == ans[i+1]) return "";
    }
    return ans;
}
    
int main() {

    return 0;
}
