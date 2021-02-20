#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/range-sum-query-2d-mutable

class NumMatrix {
public:
    
    class Fenwick_2d {
    
        vector<vector<int>> t;
        int n = 0;
        int m = 0;
        
    public:
        
        Fenwick_2d(int n, int m)
            : n(n)
            , m(m)
        {
            t.assign(n, vector<int>(m,  0));
        }
        
        Fenwick_2d(const vector<vector<int>>& a)
        {
            n = a.size();
            if (n == 0) return;
            m = a[0].size();
            if (m == 0) return;
            t.assign(n, vector<int>(m,  0));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    inc(i, j, a[i][j]);
                }
            }
        }
        
        
        int sum(int x, int y) {
            int result = 0;
            for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
                for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
                    result += t[i][j];
                }
            }
            return result;
        }
        
        int sum(int x1, int y1, int x2, int y2) {
            int result = sum(x2, y2);
            if (x1 > 0) result -= sum(x1 - 1, y2);
            if (y1 > 0) result -= sum(x2, y1 - 1);
            if (x1 > 0 && y1 > 0) result += sum(x1 - 1, y1 - 1);
            return result;
        }
        
        
        void inc(int x, int y, int add) {
            for (int i = x; i < n; i = (i | (i + 1))) {
                for (int j = y; j < m; j = (j | (j + 1))) {
                    t[i][j] += add;
                }
            }
        }
        
        void update(int x, int y, int val) {
            inc(x, y, val - sum(x, y, x, y));
        }
    };
        
    Fenwick_2d f;
    NumMatrix(vector<vector<int>>& a)
        : f(a)
    {
    }
    
    void update(int i, int j, int val) {
        f.update(i, j, val);
    }
    
    int sumRegion(int i1, int j1, int i2, int j2) {
        return f.sum(i1, j1, i2, j2);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
 
int main() {
    return 0;
}
