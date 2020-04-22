#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) return -1;
        int cnt = 1;
        int mod = 1 % K;
        while (true) {
            if (mod == 0) return cnt;
            mod = (10 * mod + 1) % K;
            ++cnt;
        }
        return -1;
    }
};
    
int main() {

    return 0;
}
