/*

https://youtu.be/jqJ5s077OKo

There are N≤5000 workers.

Each worker is available during some days of the year (which has 365 days).

For each worker, you are given a set of numbers, each from interval [1,365], representing his/her availability.

You need to assign an important project to two workers but they will be able to work on the project only when they are both available.

Find two workers that are best for the job — maximize the number of days when both these workers are available.

*/


#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
    
int main() {
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<bitset<365>> b(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            b[i][x - 1] = true;
        }
    }

    int best_i = 0;
    int best_j = 1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int cur = (b[i] & b[j]).count();
            if (ans < cur) {
                ans = cur;
                best_i = i;
                best_j = j;
            }
        }
    } 

    cout << best_i + 1 << " " << best_j + 1 << endl; 

    return 0;
}