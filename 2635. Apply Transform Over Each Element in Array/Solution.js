/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    outPut=[]
    arr.forEach((el,i)=>outPut.push(fn(el,i)))
    return outPut
};