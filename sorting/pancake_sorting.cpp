#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/pancake-sorting

// naive 2 * n
class Solution1 {
public:
    vector<int> pancakeSort(vector<int>& a) {
        int n = a.size();
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            int k = 0;
            for (int j = 0; j < n - i; ++j) {
                if (a[j] > a[k]) {
                    k = j;
                }
            }
            result.push_back(k + 1);
            reverse(begin(a), begin(a) + k + 1);
            result.push_back(n - i);
            reverse(begin(a), begin(a) + n - i);
        }
    
        return result;
    }
};

int main() {

    return 0;
}
