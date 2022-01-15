#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves

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
    unordered_map<TreeNode*, int> dp;
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        if (dp.count(root)) return dp[root];
        return dp[root] = 1 + max(dfs(root->left),  dfs(root->right));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == nullptr) return nullptr;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (left < right) return lcaDeepestLeaves(root->right);
        if (left > right) return lcaDeepestLeaves(root->left);
        return root;
    }
};
    
int main() {

    return 0;
}
