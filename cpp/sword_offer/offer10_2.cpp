class Solution {
public:
    int numWays(int n) {
        if (n <= 1)
            return 1;
        
        if (n == 2)
            return 2;
        
        int f1 = 1, f2 = 2;
        int f = 0;
        while (n > 2) {
            f = f1 + f2;
            f1 = f2;
            f2 = f;
            n -= 1;
        }

        return f;
    }
};