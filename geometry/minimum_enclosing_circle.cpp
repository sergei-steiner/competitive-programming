#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

typedef long double lld;

using namespace std;


// https://atcoder.jp/contests/abc151/tasks/abc151_f

lld _abs(lld x) {
    if (x < 0) return -x;
    return x;
}

lld sqr(lld x) {
   return x * x;
}

lld det(const vector<vector<lld>> a) {
    return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
           a[1][0] * (a[0][1] * a[2][2] - a[2][1] * a[0][2]) +
           a[2][0] * (a[0][1] * a[1][2] - a[0][2] * a[1][1]);
}

pair<lld, lld> find_center(lld x1, lld y1, lld x2, lld y2, lld x3, lld y3) {
    // https://en.wikipedia.org/wiki/Circumscribed_circle#Cartesian_coordinates
    lld len1 = sqr(x1) + sqr(y1);
    lld len2 = sqr(x2) + sqr(y2);
    lld len3 = sqr(x3) + sqr(y3);    
    vector<vector<lld>> a = { {len1, y1, 1}, {len2, y2, 1}, {len3, y3, 1} };
    vector<vector<lld>> b = { {x1, len1, 1}, {x2, len2, 1}, {x3, len3, 1} };
    vector<vector<lld>> c = { {x1, y1, 1}, {x2, y2, 1}, {x3, y3, 1} };
    lld sx = 0.5 * det(a);
    lld sy = 0.5 * det(b);
    lld A = det(c);
    if (_abs(A) < 1e-9) return {0, 0};
    sx /= A;
    sy /= A;
    return {sx, sy};
}    

int main() {
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<lld> x(n);
    vector<lld> y(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    
    lld ans = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n;  ++j) {
            lld xr = (x[i] + x[j]) / 2;
            lld yr = (y[i] + y[j]) / 2;
            lld res = 0;
            for (int l = 0; l < n; ++l) {
                res = max(res, sqr(xr - x[l]) + sqr(yr - y[l]));
            }
            if (ans < 0 || ans >= res) {
                ans = res;
            }
            
            for (int k = j + 1; k < n; ++k) {
                auto p = find_center(x[i], y[i], x[j], y[j], x[k], y[k]);
                lld xr = p.first;
                lld yr = p.second;
                lld res = 0;
            
                for (int l = 0; l < n; ++l) {
                      res = max(res, sqr(xr - x[l]) + sqr(yr - y[l]));
                }
                if (ans < 0 || ans >= res) {
                    ans = res;
                }
            }
        }
    }

    cout.precision(15);
    cout << sqrt(ans) << endl;

    return 0;
}
