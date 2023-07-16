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
    bool hasPathSum(TreeNode* root, int targetSum) {
 if (root == nullptr)return false;
    else if (root->right == nullptr && root->left == nullptr && targetSum - root->val == 0) {
        // root is a leaf and the targetSum is 0 which means there a path
        return true;
    } else return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val); 
    }
};
