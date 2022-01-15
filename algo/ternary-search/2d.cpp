#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/best-position-for-a-service-centre

class Solution {
public:
    vector<vector<int>> p;
    double f(double x, double y) {
        double ans = 0;
        for (auto v : p) {
            ans += sqrt(sqr(v[0] - x) + sqr(v[1] - y));
        }
        return ans;
    }
    
    double sqr(double x) {
        return x * x;
    }
    
    double g(double x) {
        double l = 0;
        double r = 100;
        for (int step = 0; step < 42; ++step) {
            double y1 = (l + r) / 2 - (r - l) / 30;
            double y2 = (l + r) / 2 + (r - l) / 30;
            double diff = f(x, y1) - f(x, y2);
            if (diff > 0) {
                l = y1;
            } else {
                r = y2;
            }
            if (abs(diff) < 1e-9) break;
        }
        return f(x, l);
    }
    
    double getMinDistSum(vector<vector<int>>& p) {
        this->p = p;
        double l = 0;
        double r = 100;
        for (int step = 0; step < 42; ++step) {
            if (r - l < 1e-7) break;
            double x1 = (l + r) / 2 - (r - l) / 30;
            double x2 = (l + r) / 2 + (r - l) / 30; 
            double diff = g(x1) - g(x2);
            if (diff > 0) {
                l = x1;
            } else {
                r = x2;
            }
        }
        return g(l);
    }
};
    
int main() {

    return 0;
}
