#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://en.wikipedia.org/wiki/Maximum_subarray_problem#Kadane's_algorithm

int MaxSum(const vector<int>& a) {
    int ans = a[0];
    int sum = 0;
    for (int x : a) {
        sum += x;
        ans = max(ans, sum);
        sum = max(sum, 0);
    }
    return ans;
}

pair<size_t, size_t> MaxSumRange(const vector<int>& a) {
    int ans = a[0];
    int sum = 0;
    size_t ansLeft = 0;
    size_t ansRight = 0;
    size_t left = 0;
    for (size_t right = 0; right < a.size(); ++right) {
        sum += a[right];
        if (sum > ans) {
            ans = sum;
            ansLeft = left;
            ansRight = right;
        }
        if (sum < 0) {
            sum = 0;
            left = right + 1;
        }
    }
    return {ansLeft, ansRight};
}

int main() {

    return 0;
}
