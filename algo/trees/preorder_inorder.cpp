#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

struct TreeNode {
   int val = 0;
   TreeNode* left = nullptr;
   TreeNode* right = nullptr;
   TreeNode(int x) 
       : val(x)
   {
   }
};

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

TreeNode* buildTree(int i1, int j1, int i2, int j2, vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& position) {
    if (i1 > j1) return nullptr;
    int val = preorder[i1];
    TreeNode* root = new TreeNode(val);
    int pos = position[val];
    int len = pos - i2;
    root->left = buildTree(i1 + 1, i1 + len, i2, pos - 1, preorder, inorder, position);
    root->right = buildTree(i1 + len + 1, j1, pos + 1, j2, preorder, inorder, position);
    return root;
}
    
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> position;
    int n = preorder.size();
    if (n == 0) {     
        return nullptr;
    }
    for (int i = 0; i < n; ++i) position[inorder[i]] = i;
    return buildTree(0, n - 1, 0, n - 1, preorder, inorder, position);
 }
 
int main() {
    return 0;
} 
 
