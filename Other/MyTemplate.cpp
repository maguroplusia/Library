#include <bits/stdc++.h>
using namespace std;
constexpr int Inf = 1e9;
constexpr long long INF = 2e18;
template <typename T> inline bool chmin(T &a, const T &b) { return a > b ? a = b, true : false; }
template <typename T> inline bool chmax(T &a, const T &b) { return a < b ? a = b, true : false; }

template <typename T, typename U>
T modpow(T n, U p, T m = -1) {
    if(p < 0) return 1;
    T ret = 1;
    while(p) {
        if(p & 1) {
            if(m == -1) ret *= n;
            else ret = ret * n % m;
        }
        p >>= 1;
        if(m == -1) n *= n;
        else n = n * n % m;
    }
    return ret;
}

constexpr long long MOD = 998244353;

int main() {
    
}