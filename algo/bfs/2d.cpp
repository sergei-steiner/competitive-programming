#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/flood-fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        
        int m = image[0].size();
        
        vector<vector<int>> result = image;
        int prev = image[sr][sc];
        if (prev == newColor) return result;
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while (! q.empty()) {
            pair<int, int> val = q.front();
            q.pop();
            int i = val.first;
            int j = val.second;
            result[i][j] = newColor;
            if (j + 1 < m && result[i][j + 1] == prev) q.push({i, j + 1});
            if (i + 1 < n && result[i + 1][j] == prev) q.push({i + 1, j});
            if (i > 0 && result[i - 1][j] == prev) q.push({i - 1, j});
            if (j > 0 && result[i][j - 1] == prev) q.push({i, j - 1});
            
                
        }
        
        return result;
    }
};


    
int main() {

    return 0;
}
