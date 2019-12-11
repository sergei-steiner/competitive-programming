#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int64 max_product_3(const vector<int>& a) {
    int n = a.size();
    int min1 = numeric_limits<int>::max();
    int min2 = numeric_limits<int>::max();
    int max1 = numeric_limits<int>::min();
    int max2 = numeric_limits<int>::min();
    int max3 = numeric_limits<int>::min();
    for (int x : a) {
        if (x <= min1) {
            min2 = x;
            min1 = x;
        } else if (x <= min2) {
            min2 = x;
        }
        if (x >= max1) {
            max3 = max2;
            max2 = max1;
            max1 = x;
        
        } else if (x >= max2) {
            
            max3 = max2;
            max2 = x;
        } else if (x >= max3) {
            max3 = x;
        }
    }
    return max((int64)min1 * min2 * max1, (int64)max1 * max2 * max3));
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << max_product_3(a) << endl;
    return 0;
}
