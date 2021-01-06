#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// example: https://leetcode.com/problems/magnetic-force-between-two-balls

class Solution {
public:
    int maxDistance(vector<int>& a, int m) {
        int n = a.size(); 
        sort(begin(a), end(a));
        int ans = 1;
        int l = 1;
        int r = 1000000000;
        while (l < r) {
            int mid = (l + r) / 2;
            int cnt = 0;
            int prev = numeric_limits<int>::min();
            for (int x : a) {
                if (prev + mid <= x) {
                    ++cnt;
                    prev = x;
                }
            }
            if (cnt >= m) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        return ans;
    }
};
    
int main() {

    return 0;
}
