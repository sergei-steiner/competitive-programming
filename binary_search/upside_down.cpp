#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int leftestOne(const vector<int>& a) {
    int n = a.size();
    int ans = n;
    int d = 1;
    while (d * 2 <= n) d *= 2; 
    while (d > 0) {
        if (ans - d >= 0) {
            if (a[ans - d]) {
                ans -= d;
            }
        }
        d /= 2;
    }
    if (ans == n) return -1;
    return ans;
}
    
int main() {

    return 0;
}
