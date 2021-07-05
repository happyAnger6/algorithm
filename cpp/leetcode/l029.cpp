#include <iostream>

using namespace std;

class Solution {
public:
    int deal(int *pdiv1, int *pdiv2, int *sign)
    {
        int r = 0;
        int div1 = *pdiv1;
        int div2 = *pdiv2;

        if (div1 < 0 && div2 > 0)
            *sign = -1;
        
        if (div1 > 0 && div2 < 0)
            *sign = -1;

        if (div1 == INT_MIN) {
            div1 += abs(div2);
            r = 1;
        }

        *pdiv1 = abs(div1);
        *pdiv2 = abs(div2);
        return r;
    }

    int divide(int dividend, int divisor) {
        int sign = 1;

        if (dividend == 0)
            return 0;

        if (dividend == divisor)
            return 1;

        if (divisor == INT_MIN)
            return 0;

        if (dividend == INT_MIN && abs(divisor) == 1)
            return INT_MAX;

        int result = deal(&dividend, &divisor, &sign);
        while (dividend >= divisor) {
            int div = divisor;
            int r = 1;
            while ((dividend > div + div) && (INT_MAX - div) >= div) {
                div = div + div;
                r = r + r;
            }
            dividend -= div;
            result += r;
        }

        return result * sign;
    }
};

int main()
{
    auto co = Solution();
    cout << co.divide(3, 3) << endl;
    cout << co.divide(199, 3) << endl;
    cout << co.divide(1, 3) << endl;
    cout << co.divide(0, 3) << endl;
    cout << co.divide(-7, 3) << endl;
    cout << co.divide(7, -3) << endl;
    cout << co.divide(1028, -3) << endl;
    cout << co.divide(INT_MIN, INT_MIN) << endl;
    cout << co.divide(INT_MIN, -1) << endl;
    cout << co.divide(INT_MIN, -2) << endl;
    cout << co.divide(-100, INT_MIN) << endl;
    cout << co.divide(INT_MIN, INT_MAX) << endl;
}