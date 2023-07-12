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
        queue<TreeNode *> tmp;
        vector<int> LevelNodes;
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            LevelNodes.push_back(current->val);
            if (current->left!=nullptr)tmp.push(current->left);
            if (current->right!=nullptr)tmp.push(current->right);
        }
        res.push_back(LevelNodes);
        q = tmp;
    }
    return res;
    }
};
