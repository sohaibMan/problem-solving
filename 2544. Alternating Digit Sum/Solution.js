// 2544. Alternating Digit Sum
function alternateDigitSum(n) {
  const numberOfDigits = Math.floor(Math.log10(n) + 1);
  let sum = 0;
  let sign = 1;
  for (let i = 0; i < numberOfDigits; i++) {
    sum += Math.floor(n / Math.pow(10, numberOfDigits - 1 - i)) * sign;
    n = n % Math.pow(10, numberOfDigits - 1 - i);
    sign === -1 ? (sign = 1) : (sign = -1);
  }
  return sum;
}
console.log(
  "🚀 ~ file: Solution.ts:6 ~ alternateDigitSum(521):",
  alternateDigitSum(521)
);
console.log(
  "🚀 ~ file: Solution.ts:8 ~ alternateDigitSum(111):",
  alternateDigitSum(111)
);
console.log(
  "🚀 ~ file: Solution.ts:10 ~ alternateDigitSum(886996);:",
  alternateDigitSum(886996)
);

// You are given a positive integer n. Each digit of n has a sign according to the following rules:

// The most significant digit is assigned a positive sign.
// Each other digit has an opposite sign to its adjacent digits.
// Return the sum of all digits with their corresponding sign.

// Example 1:

// Input: n = 521
// Output: 4
// Explanation: (+5) + (-2) + (+1) = 4.
// Example 2:

// Input: n = 111
// Output: 1
// Explanation: (+1) + (-1) + (+1) = 1.
// Example 3:

// Input: n = 886996
// Output: 0
// Explanation: (+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0.

// Constraints:

// 1 <= n <= 109
