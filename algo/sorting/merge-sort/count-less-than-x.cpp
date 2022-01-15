include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/create-sorted-array-through-instructions

// via fenwick

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

// via merge sort
// https://leetcode.com/problems/create-sorted-array-through-instructions/discuss/927702/Merge-Sort-Python-(nlogn)

// two merge sorts
// TLE 64/65 passed

class SolutionTLE {
public:
    vector<int> less;
    vector<int> greater;

    void merge_sort_less(vector<pair<int, int>>& a, int left, int right) {
        int len = right - left + 1;
        if (len <= 1) return;
        int middle = (left + right) / 2;
        merge_sort_less(a, left, middle);
        merge_sort_less(a, middle + 1, right);
        int i = left;
        int j = middle + 1;
        vector<pair<int, int>> ans;
        ans.reserve(len);
        for (int step = 0; step < len; ++step) {
            if (i > middle) {
                ans.push_back(a[j]);
                less[a[j].second] += i - left;
                ++j;
                continue;
            }
            if (j > right) {
                ans.push_back(a[i]);
                ++i;
                continue;
            }
            if (a[i].first < a[j].first) {
                ans.push_back(a[i]);
                 ++i;
            } else {
                less[a[j].second] += i - left;
                ans.push_back(a[j]);
                ++j;
            }
        }
        for (int step = left; step <= right; ++step) a[step] = ans[step - left];
    }
    
    void merge_sort_greater(vector<pair<int, int>>& a, int left, int right) {
        int len = right - left + 1;
        if (len <= 1) return;
        int middle = (left + right) / 2;
        merge_sort_greater(a, left, middle);
        merge_sort_greater(a, middle + 1, right);
        int i = left;
        int j = middle + 1;
        vector<pair<int, int>> ans;
        ans.reserve(len);
        for (int step = 0; step < len; ++step) {
            if (i > middle) {
                ans.push_back(a[j]);
                ++j;
                continue;
            }
            if (j > right) {
                ans.push_back(a[i]);
                ++i;
                continue;
            }
            if (a[i].first > a[j].first) {
                ans.push_back(a[j]);
                greater[a[j].second] += middle + 1 - i;
                ++j;
            } else {
                ans.push_back(a[i]);
                ++i;
            }
        }

        for (int step = left; step <= right; ++step) a[step] = ans[step - left];    }
    
    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();
        
        vector<pair<int, int>> a_less;
        for (int i = 0; i < n; ++i) {
            a_less.emplace_back(instructions[i], i);
        }
        less.assign(n, 0);
        merge_sort_less(a_less, 0, n - 1);
        
        vector<pair<int, int>> a_greater;
        for (int i = 0; i < n; ++i) {
            a_greater.emplace_back(instructions[i], i);
        }
        greater.assign(n, 0);
        merge_sort_greater(a_greater, 0, n - 1);
        
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(less[i], greater[i]);
        }
        int mod = 1000000007;
        return ans % mod;
    }
};

// with one merge sort


class Solution3 {
public:
    vector<int> less;
    vector<int> greater;

    void merge_sort(vector<pair<int, int>>& a, int left, int right) {
        int len = right - left + 1;
        if (len <= 1) return;
        int middle = (left + right) / 2;
        merge_sort(a, left, middle);
        merge_sort(a, middle + 1, right);
        int i = left;
        int j = middle + 1;
        vector<pair<int, int>> ans;
        ans.reserve(len);
        
        // we basically sort twice
        // but this can we done in more clever fashion
        // via handling equal values more carefully 
        for (int step = 0; step < len; ++step) {
            if (i > middle) {
                ans.push_back(a[j]);
                less[a[j].second] += i - left;
                ++j;
                continue;
            }
            if (j > right) {
                ans.push_back(a[i]);
                ++i;
                continue;
            }
            if (a[i].first < a[j].first) {
                ans.push_back(a[i]);
                 ++i;
            } else {
                less[a[j].second] += i - left;
                ans.push_back(a[j]);
                ++j;
            }
        }
        
        i = left;
        j = middle + 1;
        for (int step = 0; step < len; ++step) {
            if (i > middle) {
                ++j;
                continue;
            }
            if (j > right) {
                ++i;
                continue;
            }
            if (a[i].first > a[j].first) {
                greater[a[j].second] += middle + 1 - i;
                ++j;
            } else {
                ++i;
            }
        }
        
        for (int step = left; step <= right; ++step) a[step] = ans[step - left];
    }
    
    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();
        
        vector<pair<int, int>> a;
        for (int i = 0; i < n; ++i) {
            a.emplace_back(instructions[i], i);
        }
        less.assign(n, 0);
        greater.assign(n, 0);
        merge_sort(a, 0, n - 1);
        
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(less[i], greater[i]);
        }
        int mod = 1000000007;
        return ans % mod;
    }
};

int main() {

    return 0;
}
