

class NodeElement {
    private readonly _value: string;
    private _leftNode: NodeElement;
    private _rightNode: NodeElement;
    public constructor(v: string) {
        this._leftNode = null;
        this._rightNode = null;
        this._value = v;
    }

    get rightNode(): NodeElement {
        return this._rightNode;
    }

    set rightNode(value: NodeElement) {
        this._rightNode = value;
    }
    get leftNode(): NodeElement {
        return this._leftNode;
    }

    set leftNode(value: NodeElement) {
        this._leftNode = value;
    }
    get value(): string {
        return this._value;
    }






}
function wordToBinaryTree(word: string): NodeElement {
    if (word.length === 0) return null;
    // console.log(word)
    const parent = new NodeElement(word[0]);
    let currentNodeElement = parent;
    for (let i = 1; i < word.length; i++) {
        // if(word[i]===currentNodeElement.value)continue;
        const newNodeElement = new NodeElement(word[i])
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
function doesWordIncludeLetter(wordRootNodeElement: NodeElement, letter: string): boolean {


    if (wordRootNodeElement === null) return false;
    console.log(wordRootNodeElement.value, letter, wordRootNodeElement.value === letter)
    if (wordRootNodeElement.value === letter) return true;
    else if (letter > wordRootNodeElement.value) return doesWordIncludeLetter(wordRootNodeElement.rightNode, letter);
    else return doesWordIncludeLetter(wordRootNodeElement.leftNode, letter)
    // return  true;


}
function isQueryInsideWord(word: string, query: string): boolean {
    // console.log(word,query)
    // const wordRootNodeElement = wordToBinaryTree(word);
    for (const queryItem of query) {
        if (word.includes(queryItem) === false) return false;

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

function maximumRemovals(s: string, p: string, removable: number[]): number {
    let maximumRemovals = 0;
    for (let i = 0; i < removable.length; i++) {
        // console.log(s,removable[i])
        // console.log(removable[i],s.replace(s[removable[i]],''))
        // console.log(s,p,removable[i])


        const tmp = s.split("");
        tmp.splice(removable[i], 1);
        s = tmp.join("")
        const isPInS = isQueryInsideWord(s, p);
        // console.log(isPInS,s,p)
        if (isPInS === true) maximumRemovals++;
        else return maximumRemovals;

    }

    // return  1;
    // return maximumRemovals;
}
// First, we need to think about solving an easier problem, If we remove a set of indices from the string does P exist in S as a subsequence
// We can binary search the K and check by solving the above problem.

// console.log(isQueryInsideWord("adam","dama"))
// qobftcueho
let s = "qofgcueho", p = "obue", removable = [5, 3, 0, 6, 4, 9, 10, 7, 2, 8]
// accb
// console.log(maximumRemovals(s,p,removable));
console.log(isQueryInsideWord(s, p))

// s = "abddddd"
// p = "abcd"
// removable = [3,2,1,4,5,6]
// console.log(maximumRemovals(s,p,removable));
//
// s = "abcab"
// p = "abc"
// removable =[0,1,2,3,4]
// console.log(maximumRemovals(s,p,removable));
