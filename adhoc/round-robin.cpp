#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

vector<vector<pair<int, int>>> round_robin(int n) {
    int rowLen = (n + 1) / 2;
    vector<int> order;
    for (int i = 0; i < 2 * rowLen; ++i) {
        order.push_back(i + 1);
    }
    if (n % 2 == 1) order.back() = 0;
    vector<vector<pair<int, int>>> ans;
    for (int roundnum = 1; roundnum < order.size(); ++roundnum) {
        vector<pair<int, int>> round;
        for (int i = 0; i < rowLen; ++i) {
            round.emplace_back(order[i], order[order.size() - 1 - i]);
        }
        reverse(order.begin() + 2, order.end());
        reverse(order.begin() + 1, order.end());
    }
    return ans;
}
    
int main() {
    
    int n;
    cin >> n;
  
    for (const auto& round : round_robin(n)) {
        for (auto [first, second] : round) {
            cout << first << " vs " << second << " ; ";
        }
        cout << endl;
    }
    
    

    return 0;
}
