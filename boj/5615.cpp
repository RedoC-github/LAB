#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

long long modpow(long long a, long long e, long long m) {
    __int128_t r = 1, b = a % m;
    while (e > 0) {
        if (e & 1)
            r = r * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

bool check_composite(long long n, long long a, long long d, int s) {
    auto x = modpow(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (__int128_t)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool isPrime_MillerRabin(long long x) {
    if (x < 2)
        return false;
    int r = 0;
    long long d = x - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (x == a)
            return true;
        if (check_composite(x, a, d, r))
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int count = 0;
    while (n--) {
        ll x; cin >> x;
        if (isPrime_MillerRabin(2 * x + 1)) count++;
    }

    cout << count;
    return 0;
}
