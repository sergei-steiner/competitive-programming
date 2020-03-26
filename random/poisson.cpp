#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

constexpr int N = 10000; 

double uniform() {
    return 1.0 * (rand() % (N + 1)) / N;
}

int poisson(double lambda) {
    double L = exp(-lambda);
    double p = 1;
    int k = 0;
    do {
        ++k;
        p *= uniform01();
    } while (p > L);
    return k - 1;
}
    
int main() {
    double lambda;
    cin >> lambda;
    
    cout << poisson(lambda) << endl;

    return 0;
}
