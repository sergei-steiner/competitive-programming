#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/next-permutation

void nextPermutation(vector<int>& p) {
    int n = p.size();
    if (n <= 1) return;
    int i = n - 2;
    while (i >= 0 && p[i] >= p[i + 1]) {
        --i;
    }
    if (i >= 0) {
        int j = n - 1;
        while (j >= i && p[j] <= p[i]) {
            --j;
        }
        swap(p[j], p[i]);
    }
    reverse(begin(p) + i + 1, end(p));


int main() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    nextPermutation(p);
    for (int i = 0; i < n; ++i) cout << p[i] << " ";
    cout << endl;
    return 0;
}
