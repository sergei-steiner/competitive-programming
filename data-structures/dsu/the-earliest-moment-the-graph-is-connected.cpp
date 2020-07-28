#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends

class Solution {
public:
    
    vector<int> p;
    int find_set(int x) {
        if (x == p[x]) return x;
        return p[x] = find_set(p[x]);
    }
    void union_sets(int x, int y) {
        x = find_set(x);
        y = find_set(y);
        if (x == y) return;
        if (rand() & 1) {
            swap(x, y);
        }
        p[x] = y;
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        p.resize(n);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        sort(begin(logs), end(logs));
        int cnt = n;
        for (auto v : logs) {
            int t = v[0];
            int x = v[1];
            int y = v[2];
            if (find_set(x) == find_set(y)) continue;
            --cnt;
            if (cnt == 1) return t;
            union_sets(x, y);
        }
        
        return -1;
    }
};
    
int main() {

    return 0;
}
