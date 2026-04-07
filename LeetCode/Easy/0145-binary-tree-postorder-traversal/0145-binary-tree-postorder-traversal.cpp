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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root) st.push(root);
        while(st.size()){
            TreeNode* now = st.top();
            
            if(now->left == nullptr && now->right == nullptr){
                ans.push_back(now->val);
                st.pop();
            }
            if(now->right){
                st.push(now->right);
                now->right = nullptr;
            }
            if(now->left){
                st.push(now->left);
                now->left = nullptr;
            }
        }
        return ans;
    }
};