#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/reach-a-number/

// basic idea:
// we sweep the whole [-n * (n + 1) / 2, n * (n + 1) / 2] segment with respect to oddity
// so reach the needed n, than wait for the same value % 2


// O(sqrt(n))

class Solution {
public:
    int reachNumber(int target) {
        if (target < 0) target *= -1;
        long long n  = 0;
        while (n * (n + 1) / 2 < target) {
            ++n;
        }
        while ((n * (n + 1) / 2) % 2 != target % 2) ++n;
        return n;
        
    }
};

// O(1)

class Solution {
public:
    int reachNumber(int target) {
        if (target < 0) target *= -1;
        long long n  = ceil((sqrt(1 + 8.0 * target) - 1) / 2);
        while ((n * (n + 1) / 2) % 2 != target % 2) ++n;
        return n;
        
    }
};
    
int main() {

    return 0;
}
