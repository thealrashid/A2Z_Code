#include <bits/stdc++.h>

using namespace std;

double my_pow(double base, int index) {
    if (index == 0) return 1;

    if (index < 0) return 1.0 / my_pow(base, -index);

    double half = my_pow(base, index / 2);

    if (index % 2 == 0) return half * half;
    else return base * half * half;
}

int main() {
    double result = my_pow(2.1, 3);

    cout << result << endl;

    return 0;
}