#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/add-bold-tag-in-string

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<pair<int, int>> a;
        for (string str : dict) {
            int from = 0;
            while (true) {
                int pos = s.find(str, from);
                if (pos == string::npos) break;
                a.emplace_back(pos, -1);
                a.emplace_back(pos + str.size(), 1);
                from = pos + 1;
            }
        }
        sort(begin(a), end(a));
        int n = s.size();
        vector<int> markup(n + 1, 0);
        int sum = 0;
        for (auto [x, add] : a) {
            if (sum == 0) {
                markup[x] = 1;
            }
            sum -= add;
            if (sum == 0) {
                markup[x] = -1;
            }
        }
        string ans;
        for (int i = 0; i <= n; ++i) {
            if (markup[i] == 1) {
                ans += "<b>";
            }
            if (markup[i] == -1) {
                ans += "</b>";
            }
            if (i < n) ans += s[i];
        }
        return ans;
    }
};

int main() {

    return 0;
}
