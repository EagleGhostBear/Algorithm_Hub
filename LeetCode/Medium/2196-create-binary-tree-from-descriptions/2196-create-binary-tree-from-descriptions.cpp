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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> um;
        unordered_map<int, int> parent; // {child, parent}
        unordered_map<int, bool> pt;
        for(int i=0; i<descriptions.size(); i++){
            if(pt[descriptions[i][0]] && pt[descriptions[i][1]]) int t = 1;
            pt[descriptions[i][1]] = true;
            parent[descriptions[i][1]] = descriptions[i][0];
            TreeNode* now = new TreeNode(descriptions[i][0]);

            // 부모가 이미 정의된게 있는지 확인
            if(um.find(descriptions[i][0]) != um.end()) now = um[descriptions[i][0]];

            // 자식이 이미 정의된게 있는지 확인
            if(descriptions[i][2]){
                if(um.find(descriptions[i][1]) != um.end()) now->left = um[descriptions[i][1]];
                else now->left = new TreeNode(descriptions[i][1]);
            }
            else{
                if(um.find(descriptions[i][1]) != um.end()) now->right = um[descriptions[i][1]];
                else now->right = new TreeNode(descriptions[i][1]);
            }
            um[descriptions[i][0]] = now;
            while(parent[now->val]){
                TreeNode* p = um[parent[now->val]];
                if(p->left && p->left->val == now->val) p->left = now;
                else if(p->right && p->right->val == now->val) p->right = now;
                um[parent[now->val]] = p;
                now = p;
            }
        }
        TreeNode* root;
        for(auto c : pt) if(!c.second) root = um[c.first];
        return root;
    }
};