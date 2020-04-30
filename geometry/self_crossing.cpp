    
#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/self-crossing

class Solution {
public:
    bool isSelfCrossingSmall(vector<int>& d) {
        int n = d.size();
        vector<tuple<int, int, int>> v;
        vector<tuple<int, int, int>> h;
        int x = 0;
        int y = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 4 == 0) {
                v.push_back({x, y, y + d[i]});
                y += d[i];
            }
            if (i % 4 == 1) {
                h.push_back({y, x, x + d[i]});
                x += d[i];
            }
            if (i % 4 == 2) {
                v.push_back({x, y - d[i], y});
                y -= d[i];
            }
            if (i % 4 == 3) {
                h.push_back({y, x - d[i], x});
                x -= d[i];
            }
        }
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < h.size(); ++j) {
                if (i == j || j + 1 == i) {
                    continue;
                }
                auto [x1, y2, y3] = v[i];
                auto [y1, x2, x3] = h[j];
                if (x1 < x2 || x1 > x3) continue;
                if (y1 < y2 || y1 > y3) continue;
                return true;
            }
        }
        
        for (int i = 0; i < v.size(); ++i) {
            for (int j = i + 1; j < v.size(); ++j) {
                auto [level1, li, ri] = v[i];
                auto [level2, lj, rj] = v[j];
                if (level1 != level2) continue;
                if (max(li, lj) <= min(ri, rj))
                return true;
            }
        }
        for (int i = 0; i < h.size(); ++i) {
            for (int j = i + 1; j < h.size(); ++j) {
                auto [level1, li, ri] = h[i];
                auto [level2, lj, rj] = h[j];
                if (level1 != level2) continue;
                if (max(li, lj) <= min(ri, rj))
                return true;
            }
        }
        
        return false;
    }
    bool isSelfCrossing(vector<int>& x) {
       int n = x.size();
       for (int i = 0; i < n; ++i) {
           vector<int> p;
           for (int j = 0; j < 6 && i + j < n; ++j) { 
               p.emplace_back(x[i + j]);
           }
           if (isSelfCrossingSmall(p)) return true;
       }
       return false;
    }
};
    
int main() {

    return 0;
}
