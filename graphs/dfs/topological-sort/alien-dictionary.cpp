#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/alien-dictionary

class Solution {
public:
    int n = 26;
    vector<vector<int>> g;
    vector<int> color;
    vector<int> order;
    bool cycle = false;
    unordered_set<char> used;
    void dfs(int v) {
        color[v] = 1;
        for (int to : g[v]) {
            if (color[to] == 0) {
                dfs(to);
            }
            else if (color[to] == 1) {
                cycle = true;
            }
        }
        color[v] = 2;
        order.push_back(v);
    }
    string alienOrder(vector<string>& words) {
        vector<set<int>> g_set(26);
        for (int i = 1; i < words.size(); ++i) {
            bool diff = false;
            for (int j = 0; j < min(words[i - 1].size(), words[i].size()); ++j) {
                if (words[i - 1][j] == words[i][j]) continue;
                g_set[words[i - 1][j] - 'a'].insert(words[i][j] - 'a');
                diff = true;
               
                break;
            }
            if (!diff && words[i - 1].size() > words[i].size()) {
                return "";
            }
        }
        g.resize(n);
        for (int i = 0; i < 26; ++i) {
            for (int j : g_set[i]) {
                g[i].push_back(j);
            }
        }
        color.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                dfs(i);
            }
        }
        if (cycle) return "";
        reverse(begin(order), end(order));
        for (auto& word : words) {
            for (char ch : word) {
                used.insert(ch);
            }
        }
        string ans;
        for (int i : order) {
            if (used.count('a' + i)) {
                ans.push_back('a' + i);
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}
