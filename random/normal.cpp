#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://en.wikipedia.org/wiki/Box–Muller_transform

constexpr int N = 1000000;

double uniform() {
    return 1.0 * (rand() % (N + 1)) / N;
}

pair<double, double> box_muller() {
    double U1 = uniform();
    double U2 = uniform();
    return {sqrt(-2.0 * log(U1)) * cos(2 * pi * U2), sqrt(-2.0 * log(U1)) * sin(2 * pi * U2)};
}
    
int main() {

    cout << box_muller().first << endl;

    return 0;
}
