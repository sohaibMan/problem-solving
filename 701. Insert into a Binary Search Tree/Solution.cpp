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
TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr)return new TreeNode(val);
    else if (root->right == nullptr && val > root->val) {
        root->right = new TreeNode(val);
    }
    else if (root->left == nullptr && root->val > val) {
        root->left = new TreeNode(val);
    }
    else if(val > root->val) insertIntoBST(root->right, val);
    else if(root->val > val) insertIntoBST(root->left, val);
    return root;
}

};
