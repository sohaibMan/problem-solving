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

int maxDepth(TreeNode *root) {
    if (root == nullptr)return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}


int SumIfSameLevel(TreeNode *root, int current_level, int level) {
    if (root == nullptr)return 0;
    else if (current_level == level)return root->val;
    return SumIfSameLevel(root->right, current_level + 1, level) + SumIfSameLevel(root->left, current_level + 1, level);
}

public:
int deepestLeavesSum(TreeNode *root) {
    int max_depth = maxDepth(root);//o(n)
    return SumIfSameLevel(root, 1, max_depth);//o(n)
}
};
