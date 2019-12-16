#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int longestConsecutive(const vector<int>& a) {
    unordered_set<int> b(all(a));
    int ans = 0;
    for (int x : b) {
        if (b.count(x - 1)) continue;
        int cur = 0;
        while (b.count(x)) {
            ++cur;
            ++x;
        }
        ans = max(ans, cur);
    }
    return ans;
}
    
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << longestConsecutive(a) << endl;
    
    return 0;
}
