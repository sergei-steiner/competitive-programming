#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> has;
        for (auto edge : edges) {
            has.insert(edge[1]);
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (has.count(i)) continue;
            ans.push_back(i);
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
