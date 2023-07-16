// 101. Symmetric Tree
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */
function isSymmetric(root) {
    if (root === null)
        return true;
    return isSymmetricHelper(root.left, root.right);
}
;
function isSymmetricHelper(left, right) {
    if (left === null && right === null)
        return true;
    if (left === null || right === null)
        return false;
    if (left.val !== right.val)
        return false;
    return isSymmetricHelper(left.right, right.left) && isSymmetricHelper(left.left, right.right);
}
