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
    int maxLevelSum(TreeNode* root) {
    int level = 0, current_level = 0;
    int max_value = INT32_MIN;
    if (root == nullptr)return level;
    // level by level
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        queue<TreeNode *> tmp;
        int level_sum = 0;
        while (!q.empty()) {
            TreeNode*current = q.front();
            q.pop();
            level_sum += current->val;
            if (current->left != nullptr)tmp.push(current->left);
            if (current->right != nullptr)tmp.push(current->right);
        }
        level++;
        if (level_sum  >max_value ) {
            max_value = level_sum;
            current_level = level;
        }
        q = tmp;
    
    }
    return current_level;

    }
};
