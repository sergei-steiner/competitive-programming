#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/random-pick-with-weight

class Solution {
public:
    int n;
    vector<int> prefix;
    Solution(vector<int>& a) {
        n = a.size();
        prefix = a;
        for (int i = 1; i < n; ++i) {
            prefix[i] += prefix[i - 1];
        } 
    }
    
    int pickIndex() {
        return upper_bound(begin(prefix), end(prefix), random() % prefix.back()) - begin(prefix);
    }
};


int main() {

    return 0;
}
