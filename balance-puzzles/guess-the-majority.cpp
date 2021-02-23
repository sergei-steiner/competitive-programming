#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

/*

In the hidden 0-1 array you can query every 4 items to find the distribution of values (4-0, 3-1 or 2-2).
Find the index of majority element.  

*/

// https://leetcode.com/problems/guess-the-majority-in-a-hidden-array

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

// my solution \Theta(N)
// just find majority along first 5
// then query every other

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

// Theta(n / 2) approach

// again, find majority
// but then query the rest in pairs
// cause only balance is important

class Solution2 {
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
        int zeros = 2;
        int ones = 0;
        vector<int> left;
        for (int i = 0; i < n; ++i) {
            if (i == x) continue;
            if (i == y) continue;
            left.push_back(i);
        }
        int one_index = -1;
        for (int i = 0; i < left.size() / 2; ++i) {
            int result = query(reader, x, y, left[2 * i], left[2 * i + 1]);
            if (result == 0) {
                ones += 2;
                one_index = left[2 * i];
            }
            if (result == 2) {
                zeros += 1;
                ones += 1;
            }
            if (result == 4) {
                zeros += 2;
            }
        }
        if (left.size() % 2 == 1) {
            int i = left.back();
            if (left.back() == z) {
                ++zeros;
            } else {
                int result = query(reader, x, y, z, left.back());
                if (result == 4) {
                    ++zeros;
                } else {
                    ++ones;
                }
            }
        }
        if (zeros > ones) {
            return x;
        }
        if (ones > zeros) {
            return one_index;
        }
        return -1;
    }
};
    
int main() {

    return 0;
}
