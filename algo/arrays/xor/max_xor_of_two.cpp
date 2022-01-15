#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;


// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

class Solution {
public:
    int findMaximumXOR(vector<int>& a0, vector<int>& a1, int i) {
        if (a0.empty() || a1.empty()) return 0;
        if (i == -1) {
            return a0[0] ^ a1[0];
        }
        vector<int> a00;
        vector<int> a01;
        vector<int> a10;
        vector<int> a11;
        for (int x : a1) {
            if (x & (1 << i)) {
                a11.push_back(x);
            } else {
                a10.push_back(x);                    
            }
        }
        for (int y : a0) {
            if (y & (1 << i)) {
                a01.push_back(y);
            } else {
                a00.push_back(y);                    
            }
        }
        if (a00.empty()) {
            if (a10.empty()) return findMaximumXOR(a0, a1, i - 1);
            return findMaximumXOR(a0, a10, i - 1);
        }
        if (a01.empty()) {
            if (a11.empty()) return findMaximumXOR(a0, a1, i - 1);
            return findMaximumXOR(a0, a11, i - 1);
        }
        if (a10.empty()) {
            if (a00.empty()) return findMaximumXOR(a0, a1, i - 1);
            return findMaximumXOR(a00, a1, i - 1);
        }
        if (a11.empty()) {
            if (a01.empty()) return findMaximumXOR(a0, a1, i - 1);
            return findMaximumXOR(a01, a1, i - 1);
        
        }
        
        return max(findMaximumXOR(a00, a11, i - 1), findMaximumXOR(a01, a10, i - 1));
    }
    int findMaximumXOR(vector<int>& a) {
        for (int j = 31; j >= 0; --j) {
            vector<int> a0, a1;
            for (int x : a) {
                if (x & (1 << j)) {
                    a1.push_back(x);
                } else {
                    a0.push_back(x);
                }
            }
            if (!a0.empty() && !a1.empty()) return findMaximumXOR(a0, a1, j); 
        }
        return 0;
    }
    
};
    
int main() {

    return 0;
}
