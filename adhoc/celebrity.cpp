#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://www.geeksforgeeks.org/the-celebrity-problem/

// https://leetcode.com/problems/find-the-celebrity

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int i = 0;
        int j = n - 1;
        while (i < j) {
            if (knows(i, j)) {
                ++i;
            } else {
                --j;
           }
        }
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (knows(i, j)) return -1;
            if (!knows(j, i)) return -1;
        }
        return i;
    }
};
    
int main() {

    return 0;
}
