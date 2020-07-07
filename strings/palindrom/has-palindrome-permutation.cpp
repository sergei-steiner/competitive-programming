#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/palindrome-permutation

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> a;
        for (char ch : s) {
            ++a[ch];
        }
        int cnt = 0;
        for (auto [k, v] : a) {
            if (v % 2 == 1) ++cnt;
        }
        return cnt <= 1;
    }
};
    
int main() {

    return 0;
}
