#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/cheapest-flights-within-k-stops

// nice and simple O(E * k)
// first reconstruct graph by adding k layers on top
// then wen can do dijkstra on it
// but the graph is now acyclic
// so wen can use simple dp and avoid building the graph in memory at all
// we can also save memory by storing only two last layers of dp

// now we can notice that it is actually Bellman-Ford with k iterations
// but we can't use one array as Bellman-Ford does (!)
// we still have to use two (prev and current)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> flights, int src, int dst, int k) {
        int inf = 1000000000;
        ++k;
        vector<int> dp(n, inf);
        dp[src] = 0;
        for (int j = 1; j <= k; ++j) {
            vector<int> next(dp);
            for (auto v : flights) {
                int x = v[0];
                int y = v[1];
                int cost = v[2];
                next[y] = min(next[y], dp[x] + cost);
            } 
            swap(next, dp);
        }
        if (dp[dst] > inf / 2) return -1;
        return dp[dst];
    }
};

int main() {

    return 0;
}
