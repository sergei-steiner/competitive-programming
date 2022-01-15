#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/distant-barcodes/

class Solution {
public:
    
    vector<int> rearrangeBarcodes(vector<int>& a) {
        int n = a.size();
        unordered_map<int, int> cnt;
        for (int x : a) {
            ++cnt[x];
        }
        vector<pair<int, int>> b;
        for (auto [k, v] : cnt) {
            b.emplace_back(v, k);
        }
        sort(begin(b), end(b));
        reverse(begin(b), end( b));
        vector<int> ans(n, 0);
        int i = 0;
        for (int j = 0; j < n; j += 2) {
            if (b[i].first == 0) {
                ++i;
            }
            --b[i].first;
            ans[j] = b[i].second;
        }
        for (int j = 1; j < n; j += 2) {
            if (b[i].first == 0) {
                ++i;
            }
            --b[i].first;
            ans[j] = b[i].second;
        }
        return ans;
        
        
    }
};
    
int main() {

    return 0;
}
