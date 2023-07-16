/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSymmetricHelper(struct TreeNode* left,struct TreeNode* right)
{
  if(left==NULL && right==NULL )return true;
  if(left==NULL || right==NULL )return false;
  if(left->val!=right->val)return false;
  return isSymmetricHelper(left->right,right->left) && isSymmetricHelper(left->left,right->right);


}


bool isSymmetric(struct TreeNode* root){
if(root==NULL)return true;
return isSymmetricHelper(root->left,root->right);
}