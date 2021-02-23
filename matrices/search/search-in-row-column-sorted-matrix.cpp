#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int n = matrix.size();
         if (n == 0) return false;
         int m = matrix[0].size();
         if (m  == 0) return false;
         int i = 0;
         int j = m - 1;
         while (i < n && j >= 0) {
             if (matrix[i][j] == target) {
                 return true;
             }
             if (matrix[i][j] > target) {
                 --j;
                 continue;
             }
             if (matrix[i][j] < target) {
                 ++i;
                 continue;
             }
         }
         return false;
    }
};
    
int main() {

    return 0;
}
