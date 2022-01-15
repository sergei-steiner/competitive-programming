#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array
// https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

int search(vector<int>& a, int val, int l = 0, int r = numeric_limits<int>::max()) {
    int n = a.size();
    if (n == 0) return -1;
    if (r >= n) r = n - 1;
    if (l > r) return -1;
    int mid = (l + r) / 2;
    if (a[mid] == val) return mid;
    if (a[l] <= a[mid]) {
         if (a[l] <= val && val < a[mid]) {
             return search(a, val, l, mid - 1);
         } else {
             return search(a, val, mid + 1, r);
         }
    }
    if (val <= a[r] && val > a[mid]) {
         return search(a, val, mid + 1, r);
    } else {
         return search(a, val, l, mid - 1);
    }
        
    return 0;
}

int main() {

    return 0;
}
