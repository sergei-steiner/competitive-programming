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

void dfs_inorder(TreeNode* root, vector<int> ans) {
    if (!root) return;
    dfs_inorder(root->left);
    ans.push_back(root->val);
    dfs_inorder(root->right);
}

vector<int> inorder(TreeNode* root) {
    vector<int> ans;
    dfs_inorder(root, ans);
    return ans;
}

void dfs_preoder(TreeNode* root, vector<int> ans) {
    if (!root) return;
    ans.push_back(root->val);
    dfs_preoder(root->left);
    dfs_preoder(root->right);
}

vector<int> preorder(TreeNode* root) {
    vector<int> ans;
    dfs_preoder(root, ans);
    return ans;
}

void dfs_postoder(TreeNode* root, vector<int> ans) {
    if (!root) return;
    dfs_postoder(root->left);
    dfs_postoder(root->right);
    ans.push_back(root->val);
}

vector<int> postoder(TreeNode* root) {
    vector<int> ans;
    dfs_postoder(root, ans);
    return ans;
}
int main() {

    return 0;
}
