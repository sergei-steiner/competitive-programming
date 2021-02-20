#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/design-most-recently-used-queue

struct Fenwick {
    vector<int> t;
    int n = 0;
    Fenwick(int n) {
        this->n = n;
        t.assign(n, 0);
    }
    
    int sum(int r) {
        int result = 0;
        for ( ; r >= 0; r = (r & (r + 1)) - 1) {
            result += t[r]; 
        }
        return result;
    }
    
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    
    void add(int i, int val) {
        for ( ; i < n; i = (i | (i + 1))) {
            t[i] += val;
        }
    }
    
    void update(int i, int val) {
        add(i, val - sum(i, i));
    }
};

class MRUQueue {
public:
    vector<int> a;
    Fenwick f;
    MRUQueue(int n)
     : f(n + 2010)
    {
        for (int i = 0; i < n; ++i) {
            a.push_back(i + 1);
            f.add(i, 1);
        }
    }
    
    int fetch(int k) {
        int l = 0;
        int r = a.size() - 1;
        while (r - l > 3) {
            int m = (l + r) / 2;
            if (f.sum(m) >= k) {
                r = m;
            } else {
                l = m;
            }
        }
        for (int i = l; i <= r; ++i) {
            if (f.sum(i) == k) {
                f.add(i, -1);
                f.add(a.size(), 1);
                a.push_back(a[i]);
                return a[i];
            }
        }
        return -1;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
    
int main() {

    return 0;
}
