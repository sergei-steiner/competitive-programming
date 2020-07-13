#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        if (reader.get(0) == target) return 0;
        
        int left = 0;
        int right = 1;
        while (reader.get(right) < target) {
            left = right;
            right *= 2;
        }
        
        while (left <= right) {
            int m = left + (right - left) / 2;
            int num = reader.get(m);
            if (num == target) return m;
            if (num > target) {
                right = m - 1;
            } else {
                left = m + 1;
            }
        }
        
        return -1;
    }
};
    
int main() {

    return 0;
}
