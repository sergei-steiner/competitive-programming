#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://www.geeksforgeeks.org/the-celebrity-problem/

int find_celebrity(vector<vector<int>>& a) {
    int n = a.size();
    int i = 0;
    int j = n - 1;
    while (i < j) {
        if (a[i][j]) {
            ++i;
        } else {
            --j;
        }
    }
    return i;
}
    
int main() {

    return 0;
}
