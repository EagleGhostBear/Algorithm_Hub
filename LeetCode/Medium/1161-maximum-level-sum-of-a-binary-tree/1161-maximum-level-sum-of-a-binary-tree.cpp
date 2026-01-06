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
    struct tree{
        int level;
        TreeNode* node;
    };

    int maxLevelSum(TreeNode* root) {
        vector<int> sumLevel;
        queue<tree> q;
        q.push({0, root});
        while(q.size()){
            tree now = q.front(); q.pop();

            // 최대 100개 까지만 만들기 때문에 그때그때 만드는게 더 효율적일것
            while(sumLevel.size() < now.level + 1) sumLevel.push_back(0);
            sumLevel[now.level] += now.node->val;
            if(now.node->left) q.push({now.level + 1, now.node->left});
            if(now.node->right) q.push({now.level + 1, now.node->right});
        }
        pair<int, int> ans = {-1e5, -1};
        for(int i=0; i<sumLevel.size(); i++) if(ans.first < sumLevel[i]) ans = {sumLevel[i], i + 1};
        return ans.second;
    }
};
/*
최대 tree depth = n = sqrt(1e4 - 3/4) - 1/2 = 99.49 = 100까지만 보면된다.
*/