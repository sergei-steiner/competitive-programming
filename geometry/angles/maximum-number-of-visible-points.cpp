#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/maximum-number-of-visible-points

class Solution {
public:
    double pi = 4.0 * atan(1.0); 
    double get_angle(int x, int y) {
        return atan2(y, x) / pi * 180;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> a;
        int add = 0;
        for (auto p : points) {
            int x = p[0] - location[0];
            int y = p[1] - location[1];
            if (x == 0 && y == 0) {
                ++add;
                continue;
            }
            a.push_back(get_angle(x, y));
        }
        int n = a.size();
        for (int i = 0; i < n; ++i) {
            a.push_back(a[i] + 360);
        }
        sort(begin(a), end(a));
        n = a.size();
        int j = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && a[j] - a[i] <= angle) ++j;
            ans = max(ans, j - i);
        }
        return ans + add;
    }
};

    
int main() {

    return 0;
}
