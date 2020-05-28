#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        for (char ch : s1) {
            if (ch == 'x') {
                ++x1;
            }
            if (ch == 'y') {
                ++y1;
            }
        }
        for (char ch : s2) {
            if (ch == 'x') {
                ++x2;
            }
            if (ch == 'y') {
                ++y2;
            }
        }
        if ((x1 + x2) % 2 == 1) return -1;
        if ((y1 + y2) % 2 == 1) return -1;
        
        int ans1 = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == 'x' && s2[i] == 'y') {
                ++ans1;
            }
        }
        
        
        int ans2 = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == 'y' && s2[i] == 'x') {
                ++ans2;
            }
        }
        
        return (ans1 / 2) + (ans2 / 2) + (ans1 % 2 == 1 ? 2 : 0);
        
    }
};
    
int main() {

    return 0;
}
