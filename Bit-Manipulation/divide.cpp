#include <bits/stdc++.h>

using namespace std;

int divide(int dividend, int divisor) {
    if (divisor == 0) throw runtime_error("Divide by zero");

    bool neg = (dividend < 0) ^ (divisor < 0);
    long long a = llabs((long long)dividend);
    long long b = llabs((long long)divisor);

    long long quotient = 0;

    while (b <= a) {
        long long temp = b, multiple = 1;

        while ((temp << 1) <= a) {
            temp <<= 1;
            multiple <<= 1;
        }

        a -= temp;
        quotient += multiple;
    }

    if (neg) quotient = -quotient;

    if (quotient < INT_MIN) return INT_MIN;
    if (quotient > INT_MAX) return INT_MAX;

    return (int)quotient;
}

int main() {
    int dividend = 10;
    int divisor = 2;

    cout << "Quetient: " << divide(dividend, divisor) << endl;
}