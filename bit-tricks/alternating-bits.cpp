#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

// https://leetcode.com/problems/binary-number-with-alternating-bits/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        return (n & (n >> 1)) != 0 && (n & (n >> 2)) == (n >> 2);
    }
};
    
int main() {

    return 0;
}
