class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;

        int f1 = 0, f2 = 1;
        int f = 0;
        while (n > 1) {
            f = f1 + f2;
            f1 = f2;
            f2 = f;
            n -= 1;
        }

        return f;
    }
};