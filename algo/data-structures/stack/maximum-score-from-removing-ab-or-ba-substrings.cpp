#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/maximum-score-from-removing-substrings

// my approach: rather wordy, but straightforward
// based on greedy belief
// that we can first erase all ab then all ba
// or vice versa

class Solution {
public:
    int ABFirst(string s, int x, int y) {
        int ans = 0;
        string t;
        for (char ch : s) {
            if (ch == 'b') {
                if (!t.empty() && t.back() == 'a') {
                    t.pop_back();
                    ans += x;
                } else {
                    t.push_back('b');
                }
            } else {
                t.push_back('a');
            }
        }
        string u;
        for (char ch : t) {
            if (ch == 'a') {
                if (!u.empty() && u.back() == 'b') {
                    u.pop_back();
                    ans += y;
                } else {
                    u.push_back('a');
                }
            } else {
                u.push_back('b');
            }
        }
        return ans;
    }
    
    int BAFirst(string s, int x, int y) {
        int ans = 0;
        string t;
        for (char ch : s) {
            if (ch == 'a') {
                if (!t.empty() && t.back() == 'b') {
                    t.pop_back();
                    ans += y;
                } else {
                    t.push_back('a');
                }
            } else {
                t.push_back('b');
            }
        }
        string u;
        for (char ch : t) {
            if (ch == 'b') {
                if (!u.empty() && u.back() == 'a') {
                    u.pop_back();
                    ans += x;
                } else {
                    u.push_back('b');
                }
            } else {
                u.push_back('a');
            }
        }
        return ans;
    }
    
    int maximumGainAB(string s, int x, int y) {
        int n = s.size();
        return max(ABFirst(s, x, y), BAFirst(s, x, y));
    }
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        int ans = 0;
        string cur;
        for (int i = 0; i <= n; ++i) {
            if (i == n || s[i] != 'a' && s[i] != 'b') {
                ans += maximumGainAB(cur, x, y);
                cur.clear();
            } else {
                cur += s[i];
            }
        }
        return ans;
    }
};



int main() {

    return 0;
}
