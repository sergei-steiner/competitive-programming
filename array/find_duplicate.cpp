#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int findDuplicate(const vector<int>& a) {
    int x = a.size() - 1;
    int y = a.size() - 1;
    while (true) {
        x = a[x] - 1;
        y = a[y] - 1;
        y = a[y] - 1;
        if (x == y) break;
    }
    x = a.size() - 1;
    while (true) {
        if (x == y) {
            return x + 1;
        }
        x = a[x] - 1;
        y = a[y] - 1;
    }
}
    
int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << findDuplicate(a) << endl;
    
    return 0;
}
