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
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> res;
    if (root == nullptr)return res;
    // level by level
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
     
        vector<int> LevelNodes;
        int q_size=q.size();
       for(int i=0;i<q_size;i++){
            TreeNode* current = q.front();
            q.pop();
            LevelNodes.push_back(current->val);
            if (current->left!=nullptr)q.push(current->left);
            if (current->right!=nullptr)q.push(current->right);
        }
        res.push_back(LevelNodes);
     
    }
    return res;
    }
};
