#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

long long binaryExp(long long x, long long y, long long res) {
    if (y == 0) return res;

    if (y & 1) {
        return binaryExp((x * x) % mod, y >> 1, (res * x) % mod);
    } else {
        return binaryExp((x * x) % mod, y >> 1, res % mod);
    }
}

int good_num(long long n) {
    long long ll4 = binaryExp(4, n / 2, 1);
    long long ll5 = binaryExp(5, n - n / 2, 1);

    return (int)((ll4 * ll5) % mod);
}

int main() {
    cout << good_num(4) << endl;

    return 0;
}