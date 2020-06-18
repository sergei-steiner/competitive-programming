#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

vector<string> comb3(int n) {
   vector<string> ans;
   for (int m = 0; m < (1 << n); ++m) {
       for (int s = m; ; s = (s - 1) & m) {
            string str;
            for (int j = 0; j < n; ++j) {
                if (s & (1 << j)) {
                    str.push_back('a');
                    continue;
                }
                if (m & (1 << j)) {
                   str.push_back('b');
                   continue;
                }
                str.push_back('c');
            }
            if (s == 0) break;
            ans.push_back(str);
        }
    }
    return ans;
}
    
int main() {

    return 0;
}
