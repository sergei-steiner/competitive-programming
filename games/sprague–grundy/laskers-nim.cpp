#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int g(int n) {
   if (n == 0) return 0;
   if (n % 4 == 0) return n - 1;
   if (n % 4 == 1 || n % 4 == 2) return n;
   if (n % 4 == 3) return n + 1;
}

bool canWin(const vector<int>& a) {
    int ans = 0;
    for (auto x : a) ans ^= g(x);
    return ans != 0;
}
    
int main() {

    return 0;
}
