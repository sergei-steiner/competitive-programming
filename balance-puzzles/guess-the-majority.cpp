#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/guess-the-majority-in-a-hidden-array

// my solution \theta(N)
// just find majority along first 5
// then query every other

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int query(ArrayReader &reader, int x, int y, int z, int w) {
        vector<int> a = {x, y, z, w};
        sort(begin(a), end(a));
        return reader.query(a[0], a[1], a[2], a[3]);
    }
    int guessMajority(ArrayReader &reader) {
        int n = reader.length();
        vector<int> a;
        a.push_back(reader.query(1, 2, 3, 4));
        a.push_back(reader.query(0, 2, 3, 4));
        a.push_back(reader.query(0, 1, 3, 4));
        a.push_back(reader.query(0, 1, 2, 4));
        a.push_back(reader.query(0, 1, 2, 3));

        int x = -1;
        int y = -1;
        int z = -1;
        
        for (int i = 0; i < 5; ++i) {
            if (a[i] == 4) {
                vector<int> rest;
                for (int j = 0; j < 5; ++j) {
                    if (i == j) continue;
                    rest.push_back(j);
                }
                x = rest[0];
                y = rest[1];
                z = rest[2];
            }
        }
        
        if (x == -1)
        for (int i = 0; i < 5; ++i) {
            if (a[i] == 2) {
                for (int j = 0; j < 5; ++j) {
                    if (i != j && a[j] == 2) {
                        vector<int> rest;
                        for (int k = 0; k < 5; ++k) {
                            if (k == i || k == j) continue;
                            rest.push_back(k);
                        }
                        x = rest[0];
                        y = rest[1];
                        z = rest[2];
                    }
                }
            }
        }
        vector<int> val(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i == x) continue;
            if (i == y) continue;
            if (i == z) continue;
            int result = query(reader, x, y, z, i);
            if (result != 4) val[i] = 1; 
        }
        int zeros = 0;
        int ones = 0;
        for (int x : val) {
            if (x == 0) ++zeros;
            if (x == 1) ++ones;
        }
        if (ones == zeros) {
            return -1;
        }
        if (zeros > ones) {
            for (int i = 0; i < n; ++i) {
                if (val[i] == 0) return i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (val[i] == 1) return i;
        }
        return -1;
    }
};
    
int main() {

    return 0;
}
