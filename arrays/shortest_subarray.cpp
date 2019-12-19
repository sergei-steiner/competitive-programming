#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

/*

can try here:
https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k

*/

int ShortestSubarray(vector<int>& a, int k) {
    int n = a.size();
    int ans = -1;
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + a[i];
    deque<int> d;
    for (int i = 0; i <= n; ++i) {
        while (!d.empty() && prefix[d.back()] >= prefix[i]) d.pop_back();
        d.push_back(i);
        while (!d.empty() && prefix[d.front()] + k <= prefix[i]) {
            if (ans == -1 || ans > i - d.front()) ans = i - d.front();
            d.pop_front();
        }
    }
    return ans;
}
    
int main() {
    int n;
    cin >> n;
    int k;
    cin > k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << ShortestSubarray(a, k) << endl;
    return 0;
}
