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
        int tot;
    };
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        stack<node> st;
        st.push({root, -1});
        while(st.size()){
            node now = st.top(); st.pop();
            int nowTot = now.tree->val + (now.tot >= 0 ? (now.tot << 1) : 0);

            if(now.tree->left || now.tree->right){
                if(now.tree->left) st.push({now.tree->left, nowTot});
                if(now.tree->right) st.push({now.tree->right, nowTot});
            }
            else ans += nowTot;
        }
        return ans;
    }
};