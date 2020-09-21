#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
    
int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
         cin >> a[i];
    }
    vector<int> sums(n, -1);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        sum %= n;
        if (sums[sum] >= 0) {
            for (int j = sums[sum]; j <= i; ++j) {
                cout << a[j] << " ";
            }
            cout << endl;
            return 0;
        }
        sums[sum] = i + 1;
    }

    return 0;
}
