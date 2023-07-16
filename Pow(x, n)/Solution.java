class Solution {
    public double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (x == 1)
            return 1;
        if (n == 1)
            return x;
        while (n % 2 == 0) {
            x *= x;
            n = n / 2;
        }
        return n < 0 ? 1 / x * myPow(1 / x, -n - 1) : x * myPow(x, n - 1);
    }
}