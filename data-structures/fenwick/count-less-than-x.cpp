include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

struct Fenwick {
    int n = 0;
    vector<int> t;

    Fenwick(int n)
        : n(n)
        , t(vector<int>(n, 0))
    {
    }

    int sum(int r) {
        int result = 0;
        while (r >= 0) {
            result += t[r];
            r = (r & (r + 1)) - 1;
        }
        return result;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void inc(int i, int delta) {
        while (i < n) {
            t[i] += delta;
            i |= (i + 1);
        }
    }
};

// https://leetcode.com/problems/create-sorted-array-through-instructions

// without compression

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int N = 100000;
        Fenwick f(N + 1);
        long long ans = 0;
        int cnt = 0;
        for (int x : instructions) {
            ans += min(f.sum(x - 1), f.sum(x + 1, N));
            f.inc(x, 1);
        }
        int mod = 1000000007;
        return ans % mod;
    }
};

// with compression

struct Fenwick {
    int n = 0;
    vector<int> t;

    Fenwick(int n)
        : n(n)
        , t(vector<int>(n, 0))
    {
    }

    int sum(int r) {
        int result = 0;
        while (r >= 0) {
            result += t[r];
            r = (r & (r + 1)) - 1;
        }
        return result;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void inc(int i, int delta) {
        while (i < n) {
            t[i] += delta;
            i |= (i + 1);
        }
    }
};

class Solution2 {
public:
    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();
        vector<int> a = instructions;
        sort(begin(a), end(a));
        map<int, int> ord;
        for (int i = 0; i < n; ++i) {
            ord[a[i]] = i;
        }
        Fenwick f(n);
        long long ans = 0;
        int cnt = 0;
        for (int x : instructions) {
            ans += min(f.sum(ord[x] - 1), f.sum(ord[x] + 1, n - 1));
            f.inc(ord[x], 1);
        }
        int mod = 1000000007;
        return ans % mod;
    }
};
int main() {

    return 0;
}
