#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-number-of-frogs-croaking

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> ans;
        for (char ch : croakOfFrogs) {
            if (ch == 'c') {
                if (ans['k'] > 0) {
                    --ans['k'];
                    ++ans['c'];
                } else {
                    ++ans['c'];
                }
                continue;
            }
            if (ch == 'r') {
                if (ans['c'] == 0) return -1;
                --ans['c'];
                ++ans['r'];
                continue;
            }
            if (ch == 'o') {
                if (ans['r'] == 0) return -1;
                --ans['r'];
                ++ans['o'];
                continue;
            }
            if (ch == 'a') {
                if (ans['o'] == 0) return -1;
                --ans['o'];
                ++ans['a'];
                continue;
            }
            if (ch == 'k') {
                if (ans['a'] == 0) return -1;
                --ans['a'];
                ++ans['k'];
                continue;
            }
            return -1;
        }
        if (ans['c'] > 0) return -1;
        if (ans['r'] > 0) return -1;
        if (ans['o'] > 0) return -1;
        if (ans['a'] > 0) return -1;
        return ans['k'];
    }
};

int main() {

    return 0;
}
