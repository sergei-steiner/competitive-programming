#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

void shift(vector<int>& a, int k) {
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());
}
    
int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    shift(a, k);
  
    for (int i = 0; i < n; ++i) {
       cout << a[i] << " ";
    }

    return 0;
}
