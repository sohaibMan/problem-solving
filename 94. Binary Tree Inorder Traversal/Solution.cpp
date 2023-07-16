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
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };
#include "vector"
using namespace std;
class Solution {
private:
    vector <int> tree;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorderTraversalHelper(root);
        return this->tree;
    }
    void inorderTraversalHelper(TreeNode* root){

        if (root == nullptr)
            return;

        /* first recur on left child */
        inorderTraversalHelper(root->left);

        /* then push the data of node */
        this->tree.push_back(root->val);

        /* now recur on right child */
        inorderTraversalHelper(root->right);
    }
};