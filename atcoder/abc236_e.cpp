// https://atcoder.jp/contests/abc236/tasks/abc236_e

/*

ideas:
 - binary search (obvious)
 - for average: check if you can get non-negative sum of a[i] - m
 - for median: check if you can get position sim of (1 if a[i] >= m else -1)
*/


#include <bits/stdc++.h>


using int64 = long long;

using namespace std;

int n;
vector<int> a;

bool check_median(int m) {

   vector<int> A(n + 1);
   for (int i = 1; i <= n; ++i) {
       if (a[i] >= m) {
           A[i] = 1;
       } else {
           A[i] = -1;
       }
   }

   vector<int> dp(n + 1, 0);
   for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + A[i];
       if (i >= 2) dp[i] = max(dp[i], dp[i - 2] + A[i]);
   }
   return dp[n] > 0 || dp[n - 1] > 0;
}

int64 median() {
    if (n == 1) return a[1];

    int64 l = 0;
    int64 r = 1000000000;

    while (r - l > 3) {
        int m = (l + r) / 2;
        if (check_median(m)) {
            l = m;
        } else {
            r = m - 1;
        }


    }
    for (int i = r; i >= l; --i) {
        if (check_median(i)) return i;
    }

}

double average() {
    if (n == 1) return a[1];
    double l = 0;
    double r = 1e9;

    for (int step = 0; step < 70; ++step) {
        vector<double> A(n + 1);
        double m = (l + r) / 2;
        for (int i = 1; i <= n; ++i) A[i] = a[i] - m;

        vector<double> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + A[i];
            if (i >= 2) dp[i] = max(dp[i], dp[i - 2] + A[i]);
        }
        if (dp[n] >= 0 || dp[n - 1] >= 0) {
            l = m;
        } else {
            r = m;
        }
    }

    return l;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    a.resize(n);
    a.push_back(0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }

    cout.precision(10);
    cout << average() << endl;
    cout << median() << endl;

    return 0;
}