// function createCounter(n: number): () => number {
function createCounter(n) {
  let i;
  return function () {
    if (i === undefined) {
      i = n;
      return n;
    } else return ++i;
  };
}

const counter = createCounter(10);

console.log(counter());
console.log(counter());
console.log(counter());
console.log(counter());
