/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root){
    if (root == NULL)return 0;
    int max_left=maxDepth(root->left);
    int max_right=maxDepth(root->right);
    return 1 + max_left>max_right?max_left:max_right;

}
