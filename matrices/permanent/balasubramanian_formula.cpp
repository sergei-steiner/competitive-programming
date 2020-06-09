#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
    
// https://en.wikipedia.org/wiki/Computing_the_permanent#Balasubramanian–Bax–Franklin–Glynn_formula

int per(const vector<vector<int>>& a) {
    int n = a.size();
    int result = 0;
    for (int k = 0; k < (1 << (n - 1)); ++k) {   
        int mul = 1;
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
               if ((k << 1) & (1 << j)) {
                  sum -= a[i][j];
               } else {
                  sum += a[i][j];
               }
            }
            mul *= sum;
        }
        int cnt = __builtin_popcount(k);
        if (cnt % 2 == 1) mul *= -1;
        result += mul;
    }
    result >>= (n - 1);
    return result;
}
    
int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
  
    cout << per(a) << endl;
    
    return 0;
}
