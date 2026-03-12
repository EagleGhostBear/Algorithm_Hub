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
    bool ans = false;
    void dfs(TreeNode* tree, int tot, int& targetSum){
        if(tree->left == nullptr && tree->right == nullptr){
            if(targetSum == tot) ans = true;
        }
        if(tot >= targetSum) return;
        if(tree->left) dfs(tree->left, tot + tree->left->val, targetSum);
        if(tree->right) dfs(tree->right, tot + tree->right->val, targetSum);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root) dfs(root, root->val, targetSum);
        return ans;
    }
};