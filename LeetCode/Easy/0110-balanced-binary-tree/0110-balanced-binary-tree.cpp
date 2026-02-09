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
    bool ans = true;
    int solve(TreeNode* now){
        int left = (now->left ? solve(now->left) + 1 : 0);
        int right = (now->right ? solve(now->right) + 1 : 0);
        if(abs(left - right) > 1) ans = false;
        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(root) solve(root);
        return ans;
    }
};