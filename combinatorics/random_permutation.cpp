#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
    
vector<int> random_permutation(n) {
    vector<int> p(n, 0);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        int j = rand() % (i + 1);
        swap(p[i], p[j])
    }
    return p;
}
    
int main() 

    int n;
    cin >> n;

    return 0;
}
