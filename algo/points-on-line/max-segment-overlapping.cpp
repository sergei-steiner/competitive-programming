#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/meeting-rooms-ii

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& a) {
        vector<pair<int, int>> p;
        for (auto& v : a) {
            p.emplace_back(v[0], 1);
            p.emplace_back(v[1], -1);
        }
        sort(begin(p), end(p));
        int sum = 0;
        int ans = 0;
        for (auto [k, v] : p) {
            sum += v;
            ans = max(ans, sum);
        }
        return ans;
    }
};

int main() {

    return 0;
}
