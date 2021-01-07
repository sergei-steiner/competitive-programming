#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/

class Solution {
public:
    int lis(const vector<int>& a) {
        int inf = 1000000010;
        int n = a.size();
        vector<int> d(n + 1, inf);
        d[0] = -inf;
        for (int x : a) {
            int j = upper_bound(begin(d), end(d), x) - d.begin();
            if (x > d[j - 1]) {
                d[j] = x;
            }
        }
        for (int i = n; i >= 0; --i) {
            if (d[i] < inf) return i;
        }
        return 0;
    }
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, vector<int>> pos;
        for (int i = arr.size() - 1; i >= 0; --i) {
            pos[arr[i]].push_back(i);
        }
        
        vector<int> a;
        for (int x : target) {
            for (int val : pos[x]) {
                a.push_back(val);
            }
        }
        return target.size() - lis(a);
    }
};


int main() {

    return 0;
}
