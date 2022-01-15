#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) a[i] = gas[i] - cost[i];
        int sum = 0;
        for (int item : a) sum += item;
        if (sum < 0) return -1;
        vector<int> sums(n, 0);
        sums[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            sums[i] = a[i] + sums[i + 1];
        }
        
        int j = 0;
        for (int i = 1 ; i < n; ++i) {
            if (sums[j] < sums[i]) {
                j = i;
            }
        }
        return j;
    }
};


int main() {

    return 0;
}
