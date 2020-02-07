#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

template<typename T>
long long merge_sort(vector<T>& a, int left, int right) {
    long long inversions = 0;
    int len = right - left + 1;
    if (len <= 1) return;
    int middle = (left + right) / 2;
    inversions += merge_sort(a, left, middle);
    inversions += merge_sort(a, middle + 1, right);
    int i = left;
    int j = middle + 1;
    vector<T> ans;
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
        if (a[i] <= a[j]) {
            ans.push_back(a[i]);
            ++i;
        } else {
            inversions += middle - i + 1;
            ans.push_back(a[j]);
            ++j;
        }
    }
    for (int step = left; step <= right; ++step) a[step] = ans[step - left];
    return inversions;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long inversions = merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << endl;
    cout << inversions << endl;
    return 0;
}
