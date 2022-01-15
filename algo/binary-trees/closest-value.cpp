#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/closest-binary-search-tree-value

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
    double ans = numeric_limits<double>::max();
    int val = 0;
    void dfs(TreeNode* root, double target) {
        if (root == nullptr) return;
        if (target <= root->val) {
            if (ans > root->val - target) {
                val = root->val;
                ans = root->val - target;
            }
            dfs(root->left, target);
        }
        if (target >= root->val) {
            if (ans > target - root->val) {
                val = root->val;
                ans = target - root->val;
            }
            dfs(root->right, target);
        }
    }
    int closestValue(TreeNode* root, double target) {
        dfs(root, target);
        return val;
    }
};
    
int main() {

    return 0;
}
