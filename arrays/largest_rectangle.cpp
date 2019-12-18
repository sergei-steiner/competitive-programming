#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int64 largestRectangleAreaTwoStacks(vector<int>& h) {
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
    
int main() {
    int n;
    cin >> n;
    
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    cout << largestRectangleAreaTwoStacks(h) << endl;
    
    return 0;
}
