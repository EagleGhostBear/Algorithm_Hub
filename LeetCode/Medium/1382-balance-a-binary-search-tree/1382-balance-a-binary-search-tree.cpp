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
    vector<int> v;
    TreeNode* solve(int left, int right){
        if(left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* now = new TreeNode(v[mid]);
        now->left = solve(left, mid - 1);
        now->right = solve(mid + 1, right);
        return now;
    }
    TreeNode* balanceBST(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            TreeNode* now = q.front(); q.pop();
            v.push_back(now->val);
            if(now->left) q.push(now->left);
            if(now->right) q.push(now->right);
        }
        sort(v.begin(), v.end());
        int mid = (v.size() - 1) / 2;
        TreeNode* ans = new TreeNode(v[mid]);
        ans->left = solve(0, mid - 1);
        ans->right = solve(mid + 1, v.size() - 1);
        return ans;
    }
};