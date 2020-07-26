#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/add-digits

class Solution {
public:
    int addDigits(int n) {
        if (n == 0) return 0;
        return n % 9 == 0 ? 9 : n % 9;
    }
};
    
int main() {

    return 0;
}
