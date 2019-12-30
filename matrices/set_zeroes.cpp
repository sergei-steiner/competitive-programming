#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/set-matrix-zeroes

void setZeroes(vector<vector<int>>& a) {
    int n = a.size();
    int m = a[0].size();
    bool firstColumn = false;
    bool firstRow = false;
    for (int i = 0; i < n; ++i) {
        if (a[i][0] == 0) {
            firstColumn = true;
            break;
        }
    }
    for (int j = 0; j < m; ++j) {
        if (a[0][j] == 0) {
            firstRow = true;
            break;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 0) {
                a[i][0] = 0;
                a[0][j] = 0;
            }
        }
    }
        
    for (int i = 1; i < n; ++i) {
        if (a[i][0] == 0) {
            for (int j = 1; j < m; ++j) a[i][j] = 0;
        }
    }
        
    
    for (int j = 1; j < m; ++j) {
        if (a[0][j] == 0) {
            for (int i = 1; i < n; ++i) a[i][j] = 0;
        }
    }
        
    if (firstColumn) {
        for (int i = 0; i < n; ++i) a[i][0] = 0;
    }
    if (firstRow) {
        for (int j = 0; j < m; ++j) a[0][j] = 0;
    }
}
    
int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> a(n, vector<int> (m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    
   
    setZeros(a);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
