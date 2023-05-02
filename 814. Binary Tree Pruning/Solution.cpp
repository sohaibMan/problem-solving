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
private:
    bool doesContainOne(TreeNode* root ){
        if(root==nullptr)return false;
        if(root->val==1)return true;
        return doesContainOne(root->left) || doesContainOne(root->right);
    }
    void pruineTreeHelper(TreeNode* root){
        if(root==nullptr)return;
        bool doesLeftNodeContainOne=this->doesContainOne(root->left);
        bool doesRightNodeContainOne=this->doesContainOne(root->right);
        if(doesLeftNodeContainOne==false)root->left=nullptr;
        if(doesRightNodeContainOne==false)root->right=nullptr;
        pruineTreeHelper(root->left);
        pruineTreeHelper(root->right);
    }

public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root==nullptr)return root;
        bool doesLeftNodeContainOne=this->doesContainOne(root->left);
        bool doesRightNodeContainOne=this->doesContainOne(root->right);
        if(doesLeftNodeContainOne==false && doesRightNodeContainOne==false && root->val==0)return nullptr;
        this->pruineTreeHelper(root);
        return root;

    }
};