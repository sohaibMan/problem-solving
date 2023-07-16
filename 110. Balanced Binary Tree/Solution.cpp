// 110. Balanced Binary Tree

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
    bool isBalanced(TreeNode* root) {

         if(root==nullptr)return true;
         if(abs(this->tree_height(root->left) - this->tree_height(root->right))>1)return false;
         return isBalanced(root->left) && isBalanced(root->right);
    }

    int tree_height(TreeNode * root){
       if (root == nullptr)
        return 0;

        // Find the height of left, right subtrees
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);

        // Find max(subtree_height) + 1 to get the height of the tree
        return max(left_height, right_height) + 1;

    }
};