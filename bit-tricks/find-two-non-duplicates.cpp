#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

using int64 = long long;

// https://leetcode.com/problems/single-number-iii/

class Solution {
public:
    vector<int> singleNumber(vector<int>& a) {
        int xor_sum = 0;
        for (int x : a) xor_sum ^= x;
        int set_bit = (int64)xor_sum & ~((int64)xor_sum - 1);
        int ans1 = 0;
        int ans2 = 0;
        for (int x : a) {
            if (x &  set_bit) {
                 ans1 ^= x;
            } else {
                 ans2 ^= x;
            }
        }
        return {ans1, ans2};
    }
};
    
int main() {

    return 0;
}
