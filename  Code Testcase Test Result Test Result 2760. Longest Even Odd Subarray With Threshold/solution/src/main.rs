use std::cmp::max;

fn main() {
    // println!("{}", longest_alternating_subarray(vec![2, 3, 4, 5], 4));
    // println!("{}", longest_alternating_subarray(vec![1, 1, 1, 1], 4));
    // println!("{}", longest_alternating_subarray(vec![1, 2], 2));
    // println!("{}", longest_alternating_subarray(vec![3, 2, 5, 4], 5));
    // println!("{}", longest_alternating_subarray(vec![2], 2));
    // println!("{}", longest_alternating_subarray(vec![2], 0));
    // println!("{}", longest_alternating_subarray(vec![6], 5));
    println!("{}", longest_alternating_subarray(vec![2,3,4,5], 4));
}

// You are given a 0-indexed integer array nums and an integer threshold.
//
// Find the length of the longest subarray of nums starting at index l and ending at index r (0 <= l <= r < nums.length)
// that satisfies the following conditions:
//
// nums[l] % 2 == 0
// For all indices i in the range [l, r - 1], nums[i] % 2 != nums[i + 1] % 2
// For all indices i in the range [l, r], nums[i] <= threshold
// Return an integer denoting the length of the longest such subarray.

pub fn longest_alternating_subarray(nums: Vec<i32>, threshold: i32) -> i32 {
    // Brute force all the possible sub arrays and find the longest that satisfies the conditions.
    let mut length = 0;
    let mut max_length = length;

    for i in 0..nums.len() {
        if i > 0 && max(nums[i], nums[i - 1]) <= threshold && nums[i] % 2 != nums[i - 1] % 2 {
            length = length + 1;
        } else {
            length = if nums[i] % 2 == 0 && nums[i] <= threshold { 1 } else { 0 };
        }
        max_length = max(max_length, length);
    }

    // return the l
    max_length
}