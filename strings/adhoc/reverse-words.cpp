#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/reverse-words-in-a-string-ii
// Given an input string , reverse the string word by word

class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size();
        int j = -1;
        for (int i = 0; i <= n; ++i) {
            if (i == n || s[i] == ' ') {
                if (j != -1) {
                    reverse(begin(s) + j, begin(s) + i);
                    j = -1;
                }
            } else {
                if (j == -1) j = i;
            }
        }
        reverse(begin(s), end(s));
    }
};
    
int main() {

    return 0;
}
