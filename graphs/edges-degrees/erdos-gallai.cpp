#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://en.wikipedia.org/wiki/Erdős–Gallai_theorem
// very naive O(n^2)

bool can_constuct_graph(vector<int> d) {
    int sum = 0;
    for (int x : d) sum += x;
    if (sum % 2 == 1) return false;
    int n = d.size();
    sort(begin(d), end(d));
    reverse(begin(d), end(d));
    if (d.back() < 0) return false;
    for (int k = 1; k <= n; ++k) {
       int left = 0;
       for (int i = 0; i < k; ++i) {
           left += d[i];
       }
       int right = k * (k - 1);
       for (int i = k; i < n; ++i) {
           right += min(k, d[i]);
       }
       if (left > right) return false;
    }
    return true;
}
    
int main() {

    return 0;
}
