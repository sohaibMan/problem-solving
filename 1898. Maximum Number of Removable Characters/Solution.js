var NodeElement = /** @class */ (function () {
    function NodeElement(v) {
        this._leftNode = null;
        this._rightNode = null;
        this._value = v;
    }
    Object.defineProperty(NodeElement.prototype, "rightNode", {
        get: function () {
            return this._rightNode;
        },
        set: function (value) {
            this._rightNode = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(NodeElement.prototype, "leftNode", {
        get: function () {
            return this._leftNode;
        },
        set: function (value) {
            this._leftNode = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(NodeElement.prototype, "value", {
        get: function () {
            return this._value;
        },
        enumerable: false,
        configurable: true
    });
    return NodeElement;
}());
function wordToBinaryTree(word) {
    if (word.length === 0)
        return null;
    // console.log(word)
    var parent = new NodeElement(word[0]);
    var currentNodeElement = parent;
    for (var i = 1; i < word.length; i++) {
        // if(word[i]===currentNodeElement.value)continue;
        var newNodeElement = new NodeElement(word[i]);
        if (word[i] > currentNodeElement.value) {
            // console.log(newNodeElement.value,"right ")
            currentNodeElement.rightNode = newNodeElement;
        }
        else {
            // console.log(newNodeElement.value,"left")
            currentNodeElement.leftNode = newNodeElement;
        }
        currentNodeElement = newNodeElement;
    }
    return parent;
}
// function areIdentical(root1:NodeElement,  root2:NodeElement)
// {
//
//     /* base cases */
//     if (root2 === null)
//         return true;
//
//     if (root1 === null)
//         return false;
//     // console.log(root2.leftNode,root2.rightNode);
//
//     /* Check if the data of both roots
//        is same and data of left and right
//        subtrees are also same */
//     return (root1.value === root2.value
//         && areIdentical(root1.leftNode, root2.leftNode)
//         && areIdentical(root1.rightNode, root2.rightNode));
// }
// function isSubtree(T:NodeElement,  S:NodeElement):boolean
// {
//     /* base cases */
//     //  a null is any every tree
//     if (S === null)
//         return true;
//     // a null tree doesn't contain anything
//     if (T === null)
//         return false;
//
//     /* Check the tree with root as current node */
//     if (areIdentical(T, S))
//         return true;
//
//     // console.log(root2)
//     /* If the tree with root as
//        current node doesn't match then
//        try left and right subtrees one by one */
//     return isSubtree(T.leftNode, S)
//         || isSubtree(T.rightNode, S);
// }
function doesWordIncludeLetter(wordRootNodeElement, letter) {
    if (wordRootNodeElement === null)
        return false;
    console.log(wordRootNodeElement.value, letter, wordRootNodeElement.value === letter);
    if (wordRootNodeElement.value === letter)
        return true;
    else if (letter > wordRootNodeElement.value)
        return doesWordIncludeLetter(wordRootNodeElement.rightNode, letter);
    else
        return doesWordIncludeLetter(wordRootNodeElement.leftNode, letter);
    // return  true;
}
function isQueryInsideWord(word, query) {
    // console.log(word,query)
    // const wordRootNodeElement = wordToBinaryTree(word);
    for (var _i = 0, query_1 = query; _i < query_1.length; _i++) {
        var queryItem = query_1[_i];
        if (word.includes(queryItem) === false)
            return false;
        // console.log(queryItem, word)
        // if (doesWordIncludeLetter(wordRootNodeElement, queryItem) === false) {
        //     return false;
        // }
    }
    return true;
    // const queryRootNodeElement=wordToBinaryTree(query);
    // return
    // console.log(JSON.stringify(wordRootNodeElement))
    // console.log(JSON.stringify(queryRootNodeElement))
    // return  isSubtree(wordRootNodeElement,queryRootNodeElement);
    //     Check if a Binary Tree is subtree of another binary tree
}
function maximumRemovals(s, p, removable) {
    var maximumRemovals = 0;
    for (var i = 0; i < removable.length; i++) {
        // console.log(s,removable[i])
        // console.log(removable[i],s.replace(s[removable[i]],''))
        // console.log(s,p,removable[i])
        var tmp = s.split("");
        tmp.splice(removable[i], 1);
        s = tmp.join("");
        var isPInS = isQueryInsideWord(s, p);
        // console.log(isPInS,s,p)
        if (isPInS === true)
            maximumRemovals++;
        else
            return maximumRemovals;
    }
    // return  1;
    // return maximumRemovals;
}
// First, we need to think about solving an easier problem, If we remove a set of indices from the string does P exist in S as a subsequence
// We can binary search the K and check by solving the above problem.
// console.log(isQueryInsideWord("adam","dama"))
// qobftcueho
var s = "qofgcueho", p = "obue", removable = [5, 3, 0, 6, 4, 9, 10, 7, 2, 8];
// accb
// console.log(maximumRemovals(s,p,removable));
console.log(isQueryInsideWord(s, p));
// s = "abddddd"
// p = "abcd"
// removable = [3,2,1,4,5,6]
// console.log(maximumRemovals(s,p,removable));
//
// s = "abcab"
// p = "abc"
// removable =[0,1,2,3,4]
// console.log(maximumRemovals(s,p,removable));
