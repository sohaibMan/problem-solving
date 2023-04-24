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
    bool isUnivalTree(TreeNode* root) {
        // if the root is null
        if(root==nullptr)return true;
        // if the node has a right and left node
        else if(root->left!=nullptr &&  root->right!=nullptr)return root->left->val==root->val && root->right->val==root->val  && isUnivalTree(root->left) && isUnivalTree(root->right);
        // if the root left is not null but the right is null
        else if(root->left!=nullptr) return root->left->val==root->val && isUnivalTree(root->left);
        // if the root right is not nulul but the left is null
        else if(root->right!=nullptr) return root->right->val==root->val && isUnivalTree(root->right);
        // if the both are null
        else return true ;



    }
};