#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/validate-stack-sequences
// O(1) memory

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size();
    int i = 0;
    int j = 0;
    int cur = -1;
    for (int iter = 0; iter < 2 * n; ++iter) {
        if (j < n && cur >= 0 && pushed[cur] == popped[j]) {
            ++j;
            --cur;
            continue;
        }
        if (i < n) {
           ++cur;
           pushed[cur] = pushed[i]; 
           ++i;
           continue;
        }
        return false;
    }    
    return true;
}

int main() {

    return 0;
}
