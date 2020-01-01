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

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


TreeNode* buildTree(unordered_map<int, int>& pos, vector<int>& inorder, vector<int>& postorder, int i1, int j1, int i2, int j2) {
    if (i1 > j1) return nullptr;
    TreeNode* node = new TreeNode(postorder[j2]);
    int position = pos[postorder[j2]];
    node->left = buildTree(pos, inorder, postorder, i1, position - 1, i2, i2 + (position - i1) - 1);
    node->right = buildTree(pos, inorder, postorder, position + 1, j1, i2 + (position - i1), j2 - 1);
    return node;
}
    
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    unordered_map<int, int> pos;
    for (int i = 0; i < n; ++i) pos[inorder[i]] =  i; 
    return buildTree(pos, inorder, postorder, 0, n - 1, 0, n - 1);
}
 
int main() {
    return 0;
} 
