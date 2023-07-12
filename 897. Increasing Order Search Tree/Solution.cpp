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
    stack<TreeNode *> stack;

    void dfs(TreeNode *head) {
        if (head == nullptr)return;
        dfs(head->left);
        stack.push(head);
        dfs(head->right);
    }

public:
    TreeNode *increasingBST(TreeNode *root) {
        dfs(root);
        TreeNode *head = nullptr, *node = nullptr;
        while (!stack.empty()) {
            node = stack.top();
            stack.pop();
            node->left = nullptr;
            node->right = head;
            head = node;
        }
        return head;
    }
};
