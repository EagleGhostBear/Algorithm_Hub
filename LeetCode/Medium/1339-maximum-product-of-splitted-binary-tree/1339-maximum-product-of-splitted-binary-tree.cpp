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
typedef long long ll;

class Solution {
public:
    ll ans = 0, sumTot = 0, mod = 1e9 + 7;

    int dfs(TreeNode* now){
        ll val = now->val;
        if(now->right) val += dfs(now->right);
        if(now->left) val += dfs(now->left);
        ans = max(ans, val * (sumTot - val));
        return val;
    }

    int maxProduct(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        while(st.size()){
            TreeNode* now = st.top(); st.pop();
            sumTot += now->val;
            if(now->right) st.push(now->right);
            if(now->left) st.push(now->left);
        }
        dfs(root);
        
        return ans % mod;
    }
};