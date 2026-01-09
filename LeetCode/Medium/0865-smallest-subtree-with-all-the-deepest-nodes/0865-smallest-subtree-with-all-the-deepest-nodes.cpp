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
        vector<int> history;
        TreeNode* me;
    };

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*> tree(501);
        vector<vector<int>> ans;
        queue<node> q;
        q.push({{}, root});
        while(q.size()){
            node now = q.front(); q.pop();
            now.history.push_back(now.me->val);
            tree[now.me->val] = now.me;

            if(ans.size() && ans[0].size() > now.history.size()) continue;
            else if(ans.size() && ans[0].size() < now.history.size()) ans.clear();
            ans.push_back(now.history);

            if(now.me->left) q.push({now.history, now.me->left});
            if(now.me->right) q.push({now.history, now.me->right});
        }
        if(ans.size() == 1) return tree[ans[0].back()];
        int base = 0;
        for(int sz=ans[0].size() - 1; sz>-1; sz--){
            base = ans[0][sz];
            bool chk = true;
            for(int i=1; i<ans.size(); i++){
                if(ans[i][sz] != base) chk = false;
            }
            if(chk) break;
        }
        return tree[base];
    }
};