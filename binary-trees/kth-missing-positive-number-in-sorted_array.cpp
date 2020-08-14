#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        int n = a.size();
        int l = 0;
        int r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (a[m] - 1 - m < k) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l + k;
    }
};

    
int main() {

    return 0;
}
