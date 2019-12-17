#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

string largestNumber(vector<int> a) {
    sort(a.begin(), a.end(), [](int x, int y) { 
        stringstream sx;
        sx << x;
        stringstream sy;
        sy << y;
        return sx.str() + sy.str() >= sy.str() + sx.str();
    });
    string ans;
    for (int x : a) {
        stringstream sx;
        sx << x;
        ans += sx.str();
    }
    return ans;
}
    
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << largestNumber(a) << endl;
    
    return 0;
}
