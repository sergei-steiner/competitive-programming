#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence
// naive solution is O(n log n)
// but O(n) is also very simple

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& a) {
        int n = a.size();
        unordered_set<int> b(begin(a), end(a));
        int min_val = *min_element(begin(a), end(a));
        int max_val = *max_element(begin(a), end(a));
        int d = max_val - min_val;
        if (d % (n - 1) != 0) return false;
        d /= n - 1;
        for (int i = 0; i < n; ++i) {
            if (b.count(min_val + i * d) == 0) return false;
        }
        return true;
    }
};
    
int main() {

    return 0;
}
