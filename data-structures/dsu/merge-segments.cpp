#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/find-latest-group-of-size-m

class Solution {
public:
    vector<int> p;
    vector<int> cnt;
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
        cnt[y] += cnt[x]; 
    }
    void make_set(int x) {
        p[x] = x;
        cnt[x] = 1;
    }
    int size(int x) {
        return cnt[find_set(x)];
    }
    
    int findLatestStep(vector<int>& a, int m) {
        int n = a.size();
        unordered_multiset<int> b;
        int ans = -1;
        p.assign(n, -1);
        cnt.assign(n, 0);
        for (int j = 0; j < n; ++j) {
            int i = a[j] - 1;
            make_set(i);
            if (i > 0 && p[i - 1] != -1) {
                auto it = b.find(size(i - 1));
                b.erase(it);
                union_sets(i - 1, i);
            }
            if (i + 1 < n && p[i + 1] != -1) {
                auto it = b.find(size(i + 1));
                b.erase(it);
                union_sets(i, i + 1);
            }
            b.insert(size(i));
            if (b.count(m)) ans = j + 1;
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
