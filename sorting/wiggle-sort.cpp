#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/wiggle-sort

class Solution {
public:
    void wiggleSort(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i + 1 < n; ++i) {
            if (i % 2 == 0 && a[i] > a[i + 1]) swap(a[i], a[i + 1]);
            if (i % 2 == 1 && a[i] < a[i + 1]) swap(a[i], a[i + 1]);
        }
    }
};
    
int main() {

    return 0;
}
