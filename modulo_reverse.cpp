#include<bits/stdc++.h>

using namespace std;

const int p = 1e9 + 7;

int bin_pow(int val, int power, int mod) {
    int res = 1;
    while (power) {
        if (power & 1) {
            res = val * res % mod;
        }
        val = val * val % mod;
        power >>= 1;
    }
    return res;
}

int main() {
    int a, m;
    cin >> a >> m;
    cout << bin_pow(a, p - 2, m);
}
