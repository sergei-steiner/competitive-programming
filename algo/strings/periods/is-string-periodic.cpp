#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/repeated-substring-pattern
// O(n * number_of_divisors_of(n))

class Solution {
public:
    
    bool repeatedSubstringPattern(string s) {
         int n = s.size();
         for (int i = 1; i < n; ++i) {
             if (n % i == 0) {
                 bool ok = true;
                 for (int j = 0; j + i < n; ++j) {
                      if (s[j] != s[i + j]) {
                          ok = false;
                          break;
                      }
                 }  
                 if (ok) return true;
             }
         }
         return false;
    }
};

int main() {

    return 0;
}
