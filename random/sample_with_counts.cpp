#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

vector<string> sample(const vector<pair<string, string>>& cnt, int samples) {
    vector<pair<double, string>> a;
    for (auto& [k, v] : cnt) {
        a.emplace_back(log(random(0, 1)) * v, k);
    }
    sort(begin(a), end(a));
    reverse(begin(a), end(a));
    vector<string> ans;
    for (int i = 0; i < min(samples, (int)a.size()); ++i) {
         ans.push_back(a[i].second);
    }
    return ans;
}

int main() {

    return 0;
}
