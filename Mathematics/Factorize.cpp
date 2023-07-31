long long mul(long long  a,long long b,long long m) {
    __int128 a_ = a;
    __int128 b_ = b;
    __int128 m_ = m;
    __int128 ret = a_ * b_ % m_;
    long long res = ret;
    return res;
}

bool is_prime(const long long& n) {
    if(n == 1) return false;
    for(long long p : {2,3,5,7,11,13,17,19,23,29,31,37}) {
        if(n == p) return true;
        if(n % p == 0) return false;
    }

    long long d = n - 1;
    int k = 0;
    while(!(d & 1)) {
        k++;
        d >>= 1;
    }

    auto modpow = [](long long A,long long B,const long long& M) -> long long {
        long long ret = 1;
        while(B) {
            if(B & 1) ret = mul(ret,A,M);
            B /= 2;
            A = mul(A,A,M);
        }
        return ret;
    };

    std::random_device rnd;
    std::default_random_engine engine(rnd());
    std::uniform_int_distribution<long long> rand(2,n - 1);

    for(int tmp = 0;tmp < 50;tmp++) {
        long long a = rand(engine);
        long long y = modpow(a,d,n);
        if(y == 1 || y == n - 1) continue;

        int i = 0;
        for(i = 1;i < k;i++) {
            y = mul(y,y,n);
            if(y == n - 1) break;
        }
        if(i == k) return false;
    }

    return true;
}

long long rho(const long long &n) {
    if(is_prime(n)) return n;

    std::random_device rnd;
    std::default_random_engine engine(rnd());
    std::uniform_int_distribution<long long> rand(2,n - 1);

    for(int c = 1;;++c) {
        long long x = rand(engine);
        long long y = x;
        long long d = 1;
        auto f = [&](long long a) -> long long {
            return (mul(a,a,n) + c) % n;
        };
        while(d == 1) {
            x = f(x);
            y = f(f(y));
            d = gcd(abs(x - y),n);
            if(1 < d && d < n) {
                return rho(d);
            }
        }
    }
}

std::vector<long long> factorize(long long n) {
    std::vector<long long> ret;

    while(!(n & 1)) {
        n >>= 1;
        ret.push_back(2);
    }

    while(n > 1) {
        long long d = rho(n);
        while(n % d == 0) {
            n /= d;
            ret.push_back(d);
        }
    }

    std::sort(ret.begin(),ret.end());
    return ret;
}
