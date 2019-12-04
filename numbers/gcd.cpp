#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;


int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}




int main() {
    int a;
    int b;
    
    cin >> a >> b;
    
    cout << gcd(a, b) << " " << lcm(a, b) << endl;
    
    return 0;
}
