#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

map<pair<int, int>, int> dp;
    
int C(int n, int k) {
    if (n < k) return 0;
 
    if (n == 0) return 1;
    if (k == 0) return 1;
        
    auto it = dp.find({n, k});
    if (it != dp.end()) return it->second;
    dp[{n, k}] = C(n - 1, k - 1) + C(n - 1, k);
    return dp[{n, k}];
}

// https://brilliant.org/wiki/egg-dropping/
// https://leetcode.com/problems/super-egg-drop/

  
int superEggDrop(int K, int N) {
    // can perform binary search here
    for (int d = 0; ; ++d) {
        int sum = 0;
        for (int i = 1; i <= K; ++i) {
            sum += C(d, i);
            if (sum >= N) return d;
        }
    }
    return -1;
}


int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    
    cout << superEggDrop(k, n) << endl;
    
    return 0;
}
