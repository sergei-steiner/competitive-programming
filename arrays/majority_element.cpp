#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

vector<int> majority(const vector<int>& a, int k) {
    int n = a.size();
    unordered_map<int, int> cands;
    for (int x : a) {
        ++cands[x];
        if (cands.size() == k) {
            for (auto it = cands.begin(); it != cands.end(); ) {
                --it->second;
                if (it->second == 0) {
                    it = cands.erase(it);
                } else {
                    ++it;
                }
            }
        }
    }
    
    unordered_map<int, int> counts;
    for (int x : a) {
        if (cands.count(x)) {
            ++counts[x];
        }
    }
    vector<int> ans;
    for (auto [key, value] : counts) {
        if (value * k > n) {
            ans.push_back(key);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int x : majority(a, k)) cout << x << " ";
    cout << endl;

    return 0;
}
