function quickSort(arr) {
  if (arr.length <= 1) return arr;
  const pivot = arr[0];
  const left = [];
  const right = [];
  const duplicates = [];
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] < pivot) {
      left.push(arr[i]);
    } else if (arr[i] > pivot) {
      right.push(arr[i]);
    } else {
        // arr[i] === pivot
      duplicates.push(arr[i]);
    }
  }
  const sortedLeft = quickSort(left);
  const sortedRight = quickSort(right);
  return [...sortedLeft, ...duplicates, ...sortedRight];
}

// Test case
const testCases = [
  { input: [], expectedOutput: [] },
  { input: [1], expectedOutput: [1] },
  { input: [5, 3, 6, 2, 10], expectedOutput: [2, 3, 5, 6, 10] },
  { input: [10, 9, 8, 7, 6, 5, 4, 3, 2, 1], expectedOutput: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] },
  { input: [1, 2, 3, 4, 5], expectedOutput: [1, 2, 3, 4, 5] },
  { input: [5, 4, 3, 2, 1], expectedOutput: [1, 2, 3, 4, 5] },
  { input: [1, 3, 2, 5, 4], expectedOutput: [1, 2, 3, 4, 5] },
  { input: [1, 1, 1, 1, 1], expectedOutput: [1, 1, 1, 1, 1] },
  { input: [1, 2, 3, 2, 1], expectedOutput: [1, 1, 2, 2, 3] },
  { input: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], expectedOutput: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] },
  { input: [5, 3, 6, 2, 10, 1, 4, 7, 8, 9], expectedOutput: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] },
];

let passed = 0;
let failed = 0;

for (let i = 0; i < testCases.length; i++) {
  const { input, expectedOutput } = testCases[i];
  const actualOutput = quickSort(input);
  if (arraysEqual(actualOutput, expectedOutput)) {
    console.log(`Test ${i + 1} passed!`);
    passed++;
  } else {
    console.error(`Test ${i + 1} failed.`);
    console.error(`Expected: ${expectedOutput}`);
    console.error(`Actual: ${actualOutput}`);
    failed++;
  }
}

console.log(`\n${passed} tests passed, ${failed} tests failed.`);

function arraysEqual(arr1, arr2) {
  if (arr1.length !== arr2.length) return false;
  for (let i = 0; i < arr1.length; i++) {
    if (arr1[i] !== arr2[i]) return false;
  }
  return true;
}
