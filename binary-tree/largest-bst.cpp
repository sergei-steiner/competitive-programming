#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/largest-bst-subtree

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
    int ans = 0;
    unordered_map<TreeNode*, bool> bst;
    unordered_map<TreeNode*, int> min_val;
    unordered_map<TreeNode*, int> max_val;
    unordered_map<TreeNode*, int> size;
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        min_val[root] = root->val;
        max_val[root] = root->val;
        size[root] = 1;
        bst[root] = true;
        if (root->left) {
            dfs(root->left);
            min_val[root] = min(min_val[root], min_val[root->left]);
            max_val[root] = max(max_val[root], max_val[root->left]);
            size[root] += size[root->left];
            if (max_val[root->left] >= root->val) bst[root] = false;
            if (!bst[root->left]) bst[root] = false;
        }
        if (root->right) {
            dfs(root->right);
            min_val[root] = min(min_val[root], min_val[root->right]);
            max_val[root] = max(max_val[root], max_val[root->right]);
            size[root] += size[root->right];
            if (root->val >= min_val[root->right]) bst[root] = false;
            if (!bst[root->right]) bst[root] = false;
        }
        if (bst[root]) ans = max(ans, size[root]);
    }
    int largestBSTSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
    
int main() {

    return 0;
}
