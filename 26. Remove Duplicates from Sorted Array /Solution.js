// 26. Remove Duplicates from Sorted Array
function removeDuplicates(nums) {
    var k = 0;
    for (var i = 0; i < nums.length; i++) {
        if (nums[i] !== nums[k]) {
            nums[++k] = nums[i];
        }
    }
    return k + 1;
}
