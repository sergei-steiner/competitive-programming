#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
    
bool two_squares(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                ++cnt;
            }
            if (i % 4 == 3 && cnt % 2 == 1) return false;
        }
    }
    if (n > 1 && n % 4 == 3) return false;
    return true;
}
    
int main() {

    return 0;
}
