// 1304. Find N Unique Integers Sum up to Zero
// Hints
// (1/2)
// Return an array where the values are symmetric. (+x , -x)
// (2/2)
// If n is odd, append value 0 in your returned array.
function sumZero(n: number): number[] {

    if (n == 1) return [0];

    const outPut = new Array(n);
    outPut.fill(0);

    if (n % 2 !== 0) {
        for (let i = 1; i < n; i++) {
            if (i <= n / 2) outPut[i] = -i;
            else outPut[i] = -outPut[i - (n - 1) / 2];
        }
    }
    else {
        for (let i = 0; i < n; i++) {
            if (i < n / 2) outPut[i] = -(i + 1);
            else outPut[i] = -outPut[i - n / 2];
        }
    }

    return outPut;
};