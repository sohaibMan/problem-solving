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
var TreeNode = /** @class */ (function () {
    function TreeNode(val, left, right) {
        this.val = (val === undefined ? 0 : val);
        this.left = (left === undefined ? null : left);
        this.right = (right === undefined ? null : right);
    }
    return TreeNode;
}());
function kthLargestLevelSum(root, k) {
    var levelSum = {};
    dfs(root, 1, levelSum);
    // const sortedLevelSum=levelSuml
    console.log(levelSum);
    return Object.keys(levelSum).map(function (key) { return levelSum[key]; }).sort(function (a, b) { return b - a; })[k - 1] || -1;
}
function dfs(root, level, levelSum) {
    if (root === null)
        return;
    if (levelSum[level]) {
        levelSum[level] += root.val;
    }
    else {
        levelSum[level] = root.val;
    }
    dfs(root.left, level + 1, levelSum);
    dfs(root.right, level + 1, levelSum);
}
//test
var root = new TreeNode(1);
root.left = new TreeNode(2);
// root.right=new TreeNode(0);
root.left.left = new TreeNode(3);
// root.left.right=new TreeNode(-8);
console.log(kthLargestLevelSum(root, 21));
