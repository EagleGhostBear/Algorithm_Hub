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
    struct node{
        TreeNode* tree;
        int depth;
    };
    int minDepth(TreeNode* root) {
        queue<node> q;
        if(root != nullptr) q.push({root, 1});
        while(q.size()){
            node now = q.front(); q.pop();

            if(now.tree->left == nullptr && now.tree->right == nullptr) return now.depth;
            if(now.tree->left) q.push({now.tree->left, now.depth + 1});
            if(now.tree->right) q.push({now.tree->right, now.depth + 1});
        }
        return 0;
    }
};