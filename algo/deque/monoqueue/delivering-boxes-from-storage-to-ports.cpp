#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/delivering-boxes-from-storage-to-ports

// https://leetcode.com/problems/delivering-boxes-from-storage-to-ports/discuss/969560/Python-O(n).-DP-%2B-Monotonic-Queue-(Sliding-Window)-with-Full-Explanation

class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        deque<pair<int, int>> d;
        d.push_front({-1, 0});
        int prev = -1;
        int weight = 0;
        for (int i = 0; i < n; ++i) {
            weight += boxes[i][1];
            while (i - prev > maxBoxes || weight > maxWeight) {
                ++prev;
                weight -= boxes[prev][1];
            }
            while (d.front().first < prev) {
                d.pop_front();
            }
            int cost = 1;
            if (i + 1 < n && boxes[i][0] == boxes[i + 1][0]) cost = 2;
            cost += d.front().second;
            while (!d.empty() && d.back().second >= cost) {
                d.pop_back();
            }
            d.push_back({i, cost});
        }
        int ans = 1;
        for (int i = 0; i + 1 < n; ++i) {
            if (boxes[i][0] != boxes[i + 1][0]) ++ans;
        }
        return ans + d.back().second;
    }
};
    
int main() {

    return 0;
}
