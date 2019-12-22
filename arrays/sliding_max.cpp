#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

vector<int> max_sliding_window(vector<int>& a, int k) {
    int n = sz(a);
    if (n == 0) return {};
    vector<int> prefix = a;
    for (int i = 1; i < n; ++i) {
        if (i % k == 0) continue;
        prefix[i] = max(prefix[i], prefix[i - 1]);
    }
    vector<int> suffix = a;
    for (int i = n - 2; i >= 0; --i) {
        if (i % k == k - 1) continue;
        suffix[i] = max(suffix[i], suffix[i + 1]);
    }
    vector<int> ans;
    for (int i = 0; i + k <= n; ++i) {
        ans.push_back(max(suffix[i], prefix[i + k - 1]));
    }
    return ans;
}

struct MaxQueue {
    deque<pair<int, int>> d;
    
    void push(int val) {
        int cnt = 1;
        while (!d.empty() && d.back().first <= val) {
            cnt += d.back().second;
            d.pop_back();
        }
        d.emplace_back(val, cnt);
    }

    void pop() {
        int val = d.front().first;
        int cnt = d.front().second - 1;
        d.pop_front();
        if (cnt > 0) {
            d.emplace_front(val, cnt);
        }
    }
    
    bool empty() const {
        return d.empty();
    }
    
    int max() const {
        return d.front().first;
    }
};

vector<int> max_sliding_window_max_queue(vector<int>& a, int k) {
    int n = a.size();
    if (n == 0) return {};
    MaxQueue q;
    for (int i = 0; i + 1 < k; ++i) {
        q.push(a[i]);
    }
    vector<int> ans;
    for (int i = k - 1; i < n; ++i) {
        q.push(a[i]);
        if (i >= k) q.pop();
        ans.push_back(q.max());
    }
    return ans;
}


struct MaxStack {
    stack<pair<int, int>> st;
    
    void push(int val) {
        using std::max;
        int maxval = val;
        if (!st.empty()) {
            maxval = max(maxval, st.top().second);
        }
        st.push({val, maxval});
    }

    int pop() {
        int val = st.top().second;
        st.pop();
        return val;
    }

    bool empty() const {
        return st.empty();
    }
    
    int max() const {
        return st.top().second;
    }
    
};

struct MaxQueueStacks {
    MaxStack first;
    MaxStack second;

    void push(int val) {
        first.push(val);
    }

    void pop() {
        if (second.empty()) {
            while (!first.empty()) {
                 second.push(first.pop());
            }
        }
        second.pop();
    }
    
    bool empty() const {
        return first.empty() && second.empty();
    }
    
    int max() const {
        return max(first.max(), second.max());
    }
};

vector<int> max_sliding_window_max_queue_two_stacks(vector<int>& a, int k) {
    int n = a.size();
    if (n == 0) return {};
    MaxQueueStacks q;
    for (int i = 0; i + 1 < k; ++i) {
        q.push(a[i]);
    }
    vector<int> ans;
    for (int i = k - 1; i < n; ++i) {
        q.push(a[i]);
        if (i >= k) q.pop();
        ans.push_back(q.max());
    }
    return ans;
}


int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int x : max_sliding_window(a, k)) cout << x << " ";
    cout << endl;
    for (int x : max_sliding_window_max_queue(a, k)) cout << x << " ";
    cout << endl;
    for (int x : max_sliding_window_max_queue_two_stacks(a, k)) cout << x << " ";
    cout << endl;
    
    
    
    return 0;
}
