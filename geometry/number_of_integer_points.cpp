#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

struct Point {
    long long X = 0;
    long long Y = 0;
};

struct Segment {
    Point Left;
    Point Right;
};

long long NumberOfIntegerPoints(const Segment& segment) {
    return gcd(abs(segment.Right.X - segment.Left.X), abs(segment.Right.Y - segment.Left.Y)) + 1;
}
    
int main() {

    return 0;
}
