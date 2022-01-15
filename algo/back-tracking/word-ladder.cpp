#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/word-ladder-ii

// perform bfs backwards, then backstrack forward

class Solution {
public:
    int n = 0;
    int m = 0;
    vector<vector<int>> a;
    vector<int> d;
    vector<string> wordList;
    static constexpr int inf = 1000000000;
    vector<vector<string>> dfs(int from, int to) {
        vector<vector<string>> ans;
        if (from == to) {
            ans.push_back({wordList[to]});
            return ans;
        }
        for (int i = 0; i < n; ++i) {
            if (a[from][i] == 1 && d[from] == d[i] + 1) {
                for (auto v : dfs(i, to)) {
                    vector<string> add;
                    add.push_back(wordList[from]);
                    for (string w : v) {
                        add.push_back(w);
                    }
                    ans.push_back(add);
                }
            }
        }
        return ans;
    }
    
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        this->wordList = wordList;
        n = wordList.size();
        m = endWord.size();
        a.assign(n, vector<int>(n, inf));
        for (int i = 0; i < n; ++i) a[i][i] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < m; ++k) {
                     cnt += (wordList[i][k] != wordList[j][k]);
                }
                if (cnt == 1) {
                    a[i][j] = 1;
                    a[j][i] = 1;
                }
            }
        }
        int from = n - 1;
        int to = -1;
        for (int i = 0; i < n; ++i) {
            if (wordList[i] == endWord) {
                to = i;
                break;
            }
        }
        vector<vector<string>> ans;
        if (to == -1) return ans;
        d.assign(n, inf);
        queue<int> q;
        q.push(to);
        d[to] = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == 1 && d[j] == inf) {
                    q.push(j);
                    d[j] = d[i] + 1;
                }
            }
        }
        if (d[from] == inf) return ans;
        return dfs(from, to);
    }
};
    
int main() {

    return 0;
}
