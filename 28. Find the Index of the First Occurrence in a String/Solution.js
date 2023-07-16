function strStr(haystack, needle) {
    for (var i = 0; i < haystack.length; i++) {
        if (haystack[i] === needle[0])
            for (var j = 0; j < needle.length; j++) {
                if (haystack.length - i < needle.length)
                    return -1;
                if (haystack[i + j] !== needle[j]) {
                    // i++;
                    break;
                }
                ;
                if (j === needle.length - 1)
                    return i;
            }
    }
    return -1;
}
;
var haystack = "mississippi", needle = "pi";
console.log(strStr(haystack, needle));
// haystack = "hello", needle = "ll"
// console.log(strStr(haystack, needle))
// haystack = "aaaaa", needle = "bba"
// console.log(strStr(haystack, needle))
// haystack = "", needle = ""
// console.log(strStr(haystack, needle))
