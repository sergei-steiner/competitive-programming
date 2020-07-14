#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/encode-and-decode-strings

class Codec {
public:
    int N = 8;

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for (auto s : strs) {
            stringstream ss;
            ss << s.size();
            string len = ss.str();
            while (len.size() < N) len = "0" + len;
            ans += len + s;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.size()) {
            int len = stoi(s.substr(i, N));
            i += N;
            string add;
            for (int j = 0; j < len; ++j) {
                add += s[i + j];
            }
            ans.push_back(add);
            i += len;
        }
        
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
    
int main() {

    return 0;
}
