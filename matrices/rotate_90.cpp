    
#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;


// https://leetcode.com/problems/rotate-image/submissions/

void rotate(vector<vector<int>>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0;  j < n; ++j) {
            if (i > j) continue;
            if (i >= n - j - 1) continue;
            int val = a[i][j];
            a[i][j] = a[n - j - 1][i];
            a[n - j - 1][i] = a[n - i - 1][n - j - 1];
            a[n - i - 1][n - j - 1] = a[j][n - i - 1];
            a[j][n - i - 1] = val;
        }
    }
}

int main() {

    return 0;
}
