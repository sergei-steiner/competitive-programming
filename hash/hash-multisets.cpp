/*

You are given two (multi)sets A = {a_1, ...., a_n} and B = {b_1, ..., b_n}. n <= 10^5 and each element is in the interval [0, MOD). Determine if they are the same.

http://rng-58.blogspot.com/2017/02/hashing-and-probability-of-collision.html

*/

#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int hash_multiset(const vector<int> a) {
    int x = 43; // some random number
    int ans = 1;
    for (int y : a) {
        ans *= (x + y);
    }
    // modulo prime number would be better
    return ans;
}

int main() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    cout << (hash_multiset(a) == hash_multiset(b)) << endl;
    return 0;
}
