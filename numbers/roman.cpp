#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

string roman(int n) {
    vector<pair<string, int>> a = {
        {"I", 1},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000}            
      
    };
    string ans;
    for (int i = a.size() - 1; i >= 0; --i) {
        while (n >= a[i].second) {
            n -= a[i].second;
            ans += a[i].first;
        }
    }
    return ans;
}

int main() {
   int n;
   cin >> n;
   cout << roman(n) << endl;
    
   return 0;
}
