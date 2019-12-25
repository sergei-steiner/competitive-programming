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

int gcd (int a, int b, int& x, int& y) {
    if (a == 0) {
       x = 0;
       y = 1;
       return b;
    }
    int x1, y1;
    int d = gcd (b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}




int main() {
    int a;
    int b;
    
    cin >> a >> b;
    
    cout << gcd(a, b) << " " << lcm(a, b) << endl;
    
    return 0;
}
