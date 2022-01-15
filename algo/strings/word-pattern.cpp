#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/word-pattern

class Solution {
public:
    vector<string> split(const string& str) {
        vector<string> ans;
        stringstream ss;
        ss << str;
        string s;
        while (ss >> s) {
            ans.push_back(s);
        }
        return ans;
    }
    
    vector<int> canonize(string s) {
        vector<string> chars;
        for (char ch : s) {
            chars.push_back(string(1, ch));
        }
        return canonize(chars);
    }
    vector<int> canonize(const vector<string>& s) {
        vector<int> ans;
        unordered_map<string, int> pos;
        for (int i = 0; i < s.size(); ++i) {
            if (!pos.count(s[i])) {
                pos[s[i]] = i;
            }
            ans.push_back(pos[s[i]]);
        }
        return ans;
    }
    
    bool wordPattern(string pattern, string str) {
        return canonize(pattern) == canonize(split(str));
    }
};
    
int main() {

    return 0;
}
