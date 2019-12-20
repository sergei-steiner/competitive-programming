#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int64 largestRectangleArea(vector<int>& h) {
    int n = h.size();
    if (n == 0) return 0;
    
    stack<int> st;
    
    vector<int> left(n, -1);
    st.push(0);
    for (int i = 1; i < n; ++i) {
        while (!st.empty() && h[st.top()] >= h[i]) st.pop();
        if (!st.empty()) left[i] = st.top();
        st.push(i);
    }
    
    st = {};
    st.push(n - 1);
    vector<int> right(n, n);
    for (int i = n - 2; i >= 0; --i) {
        while (!st.empty() && h[st.top()] >= h[i]) st.pop();
        if (!st.empty()) right[i] = st.top();
        st.push(i);
    }
    int64 ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, (int64)h[i] * (right[i] - left[i] - 1));
    }    
    return ans;
}

int64 largestRectangleArea(const vector<vector<int>>& a) {
    int64 n = a.size();
    if (n == 0) return 0;
    int64 m = a[0].size();
    if (m == 0) return 0;
    int64 ans = 0;
    vector<int> h(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '0') h[j] = 0;
            if (a[i][j] == '1') ++h[j];        
        }
        ans = max(ans, largestRectangleArea(h));
    }
    return ans;
}
    
int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> a(n, vector<int> (m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    
    cout << largestRectangleArea(a) << endl;
    
    return 0;
}
