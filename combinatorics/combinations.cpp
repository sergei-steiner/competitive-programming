#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

bool nextCombination(const vector<int>& c, int n) {
    int k = c.size();
    int next = n;
    for (int i = k - 1; i >= 0; --i) {
        if (c[i] + 1 < next) {
            ++c[i];
            for (int j = i + 1; j < k; ++j) {
                c[j] = c[j - 1] + 1;
            }
            return true;
        }
        next = c[i];
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> c(k);
    for (int i = 0; i < k; ++i) c[i] = i;
    while (true) {
        for (int j = 0; j < k; ++j) cout << c[j] << " ";
        cout << endl;
        if (!nextCombination(c)) {
            break; 
        }
    }
    return 0;
}
