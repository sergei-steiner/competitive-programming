#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/broken-calculator/

// just go backwards

class Solution {
public:
    int brokenCalc(int X, int Y) {
        
        int ans = 0;
        while (true) {
            if (X >= Y) return ans + X - Y;
            if (Y % 2 == 1) {
                ++ans;
                ++Y;
                continue;
            }
            Y /= 2;
            ++ans;
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
