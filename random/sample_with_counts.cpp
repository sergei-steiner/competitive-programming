#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

double random() {
    int inf = 100000;
    return 1.0 * (random() % inf + 1) / inf;
}

vector<string> sample(const vector<pair<string, int>>& cnt, int samples) {
    vector<pair<double, string>> a;
    for (auto& [k, v] : cnt) {
        a.emplace_back(log(random()) * v, k);
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
