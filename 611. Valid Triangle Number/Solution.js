// 611. Valid Triangle Number
// Medium
// 3.3K
// 181
// Companies
// Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

// Example 1:

// Input: nums = [2,2,3,4]
// Output: 3
// Explanation: Valid combinations are:
// 2,3,4 (using the first 2)
// 2,3,4 (using the second 2)
// 2,2,3
// Example 2:

// Input: nums = [4,2,3,4]
// Output: 4

function triangleNumber(nums) {
  let sum = 0;
  for (let i = 0; i < nums.length; i++) {
    let a = nums[i];
    for (let j = i + 1; j < nums.length; j++) {
      let b = nums[j];
      for (let k = j + 1; k < nums.length; k++) {
        let c = nums[k];

        if (a + b > c && a + c > b && b + c > a) {
          sum++;
        }
      }
    }
  }
  return sum;
}
console.log(triangleNumber([4, 2, 3, 4]));

// O(n^3) n1

// Sides of Triangle Rule
// The rule of the sides of a triangle is that the sum of the lengths of any two sides of a triangle
// is always greater than the length of the third side.
