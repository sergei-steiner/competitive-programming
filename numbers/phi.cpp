#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
    
int phi(int n) {
   int result = n;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
        }
        result -= result / i;
    }
    if (n > 1) result -= result / n;
    return result;
}
   
int main() {
  
  
    int n;
    cin >> n;
    cout << phi(n) << endl;

    return 0;
}
