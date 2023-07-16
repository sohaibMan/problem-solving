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
int MaxBinaryTree(TreeNode *root) {
    if (root == nullptr)return INT32_MIN;  // max of the left and right trees
    else if(root->left && root->right) return max(max(MaxBinaryTree(root->left), MaxBinaryTree(root->right)),root->val);
     else if(root->left)return max(MaxBinaryTree(root->left),root->val);
     else return max(MaxBinaryTree(root->right),root->val);

}

int MinBinaryTree(TreeNode*root) {
    if (root == nullptr)return INT32_MAX;
    // min of the left and right trees
    else if(root->left && root->right)return min(min( MinBinaryTree(root->left),MinBinaryTree(root->right)),root->val);
    else if(root->left) return min(MinBinaryTree(root->left),root->val);
    else return min(MinBinaryTree(root->right),root->val);

}

public:
   bool isValidBST(TreeNode *root) {
    if (root == nullptr)return true;
    else if (root->left== nullptr && root->right==nullptr)return true;
    else if ((root->right != nullptr && root->val >= root->right->val) ||
             (root->left != nullptr && root->val <= root->left->val))
        return false;
    else
       return (root->right ? root->val < MinBinaryTree(root->right) :true) &&
               (root->left ? root->val > MaxBinaryTree(root->left):true) &&
               isValidBST(root->left) && isValidBST(root->right);
}

};y

