#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int64 less_with_prefix(int64 n, int64 prefix) {
    int64 ans = 0;
    int64 left = prefix;
    int64 right = prefix + 1;
    while (left <= n) {
        ans += min(right, n + 1) - left;
        left *= 10;
        right *= 10;
    }
    return ans;
}

int64 findKthNumber(int64 n, int64 k) {
    int64 ans = 1;
    while (k > 1) {
        int64 with_prefix_ans = less_with_prefix(n, ans);
        if (with_prefix_ans < k) {
            ++ans;
            k -= with_prefix_ans;
        } else {
            ans *= 10;
            --k;
        }
    }
    return ans;
}

int main() {
    int64 n, k;
    cin >> n >> k;
    cout << findKthNumber(n, k) << endl;
    return 0;
}
