/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  const indexes = [];
  for (let i = 0; i < nums.length; i++) {
    let isFound = 0;
    for (let j = 0; j < nums.length; j++) {
      if (i === j) continue;
      if (nums[i] + nums[j] === target) {
        indexes.push(i, j);
        isFound = 1;
        break;
      }
    }
    if (isFound === 1) break;
  }
  return indexes;
};
