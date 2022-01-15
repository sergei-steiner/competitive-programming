#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/prison-cells-after-n-days

class Solution {
public:
    int toInt(vector<int> cells) {
        int ans = 0;
        int deg = 1;
        for (int i = 0; i < 8; ++i) {
            ans += cells[i] * deg;
            deg *= 2;
        }
        return ans;
    }
    
    vector<int> fromInt(int n) {
        vector<int> ans(8, 0);
        for (int i = 0; i < 8; ++i) {
            ans[i] = n % 2;
            n /= 2;
        }
        return ans;
    }
    
    
    vector<int>  next(vector<int> cells) {
        vector<int> ans(8, 0);
        for (int i = 1; i < 7; ++i) {
            if (cells[i + 1] == cells[i - 1]) ans[i] = 1;
        }
        return ans;
    }
    
    int next(int n) {
        return toInt(next(fromInt(n)));
    }

    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> num(256, -1);
        int start = toInt(cells);
        int cur = start;
        bool ok = true;
        for (int i = 0; i < N; ++i) {
            if (num[cur] != -1 && ok) {
                int step = i - num[cur];
                N %= step;
                while (N <= i) N += step;
                ok = false;
            }
            num[cur] = i;
            cur = next(cur);
        }
        return fromInt(cur);
    }
};

int main() {

}
