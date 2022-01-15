#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

// https://leetcode.com/problems/binary-tree-cameras/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    static constexpr int inf = 1000000000;
    // answer
    unordered_map<TreeNode*, int> dp;
    // answer if root is not covered
    unordered_map<TreeNode*, int> dp0;
    // answer if root is covered
    unordered_map<TreeNode*, int> dp1;
    // answer to cover children
    unordered_map<TreeNode*, int> dp2;
    
    
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        
        dfs(root->left);
        dfs(root->right);
        
        dp0[root] = dp[root->left] + dp1[root->right];
        dp0[root] = min(dp0[root], dp1[root->left] + dp[root->right]);
        
        dp1[root] = dp2[root->left] + dp2[root->right] + 1;
        
        dp[root] = min(dp0[root], dp1[root]);
        
        dp2[root] = min(dp[root], dp[root->left] + dp[root->right]);

    }
    
    int minCameraCover(TreeNode* root) {
        dp1[nullptr] = inf;
        dfs(root);
        return dp[root];
    }
};

int main() {

    return 0;
}
