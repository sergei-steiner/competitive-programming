#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
 
// https://leetcode.com/problems/number-of-days-in-a-month

class Solution {
public:
    bool isLeap(int Y) {
        if (Y % 400 == 0) return true;
        if (Y % 100 == 0) return false;
        if (Y % 4 == 0) return true;
        return false;
        
    }
    int numberOfDays(int Y, int M) {
        vector<int> m = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeap(Y)) ++m[2];
        return m[M];
    }
};
 
int main() {

    return 0;
}
