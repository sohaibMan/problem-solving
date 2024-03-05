/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function (s) {
    return s.replace(/\s+/g, ' ').trim().split(" ").reverse().join(" ")
};

console.log(reverseWords("the sky is blue"))
console.log(reverseWords("  hello world  "))