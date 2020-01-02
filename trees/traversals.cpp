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


https://leetcode.com/problems/binary-tree-inorder-traversal/

void dfs_inorder(TreeNode* root, vector<int>& traversal) {
    if (!root) return;
    dfs_inorder(root->left, traversal);
    traversal.push_back(root->val);
    dfs_inorder(root->right, traversal);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    dfs_inorder(root, ans);
    return ans;
}

// Morris Traversal

vector<int> inorderMorrisTraversal(TreeNode* root) {  
    vector<int> ans;
    TreeNode* current = root;
    while (current != nullptr) { 
        if (current->left == nullptr) { 
            ans.push_back(current->val); 
            current = current->right; 
        } else { 
           
            TreeNode* pred = current->left; 
            while (pred->right != nullptr && pred->right != current) {
                pred = pred->right; 
            }
  
            if (pred->right == nullptr) { 
                pred->right = current; 
                current = current->left; 
            } else { 
                pred->right = nullptr; 
                ans.push_back(current->val); 
                current = current->right; 
           }
        }
    }
    return ans;
} 

// https://leetcode.com/problems/binary-tree-preorder-traversal/

void dfs_preoder(TreeNode* root, vector<int>& traversal) {
    if (!root) return;
    traversal.push_back(root->val);
    dfs_preoder(root->left, traversal);
    dfs_preoder(root->right, traversal);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    dfs_preoder(root, ans);
    return ans;
}

// https://leetcode.com/problems/binary-tree-postorder-traversal/

void dfs_postoder(TreeNode* root, vector<int>& traversal) {
    if (!root) return;
    dfs_postoder(root->left, traversal);
    dfs_postoder(root->right, traversal);
    traversal.push_back(root->val);
}

vector<int> postoderTraversal(TreeNode* root) {
    vector<int> ans;
    dfs_postoder(root, ans);
    return ans;
}
int main() {

    return 0;
}
