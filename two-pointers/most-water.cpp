#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;


// https://leetcode.com/problems/container-with-most-water/

int maxArea(vector<int>& a) {
    int ans = 0;
    int i = 0;
    int j = a.size() - 1;
    while (i < j) {
        ans = max(ans, min(a[i], a[j]) * (j - i));
        if (a[i] < a[j]) {
            ++i;
        } else {
            --j;
        }
     }
     return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << maxArea(a) << endl;

    return 0;
}
