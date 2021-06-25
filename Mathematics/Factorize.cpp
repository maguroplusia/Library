long long mul(long long  A,long long B,long long M) {
    __int128 a = A;
    __int128 b = B;
    __int128 m = M;
    __int128 ret = a * b % m;
    long long res = ret;
    return res;
}

bool is_prime(const long long& N) {
    if(N == 1) return false;
    for(long long p : {2,3,5,7,11,13,17,19,23,29,31,37}) {
        if(N == p) return true;
        if(N % p == 0) return false;
    }

    long long d = N - 1;
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

    random_device rnd;
    default_random_engine engine(rnd());
    uniform_int_distribution<long long> rand(2,N - 1);

    for(int tmp = 0;tmp < 50;tmp++) {
        long long a = rand(engine);
        long long y = modpow(a,d,N);
        if(y == 1 || y == N - 1) continue;

        int i = 0;
        for(i = 1;i < k;i++) {
            y = mul(y,y,N);
            if(y == N - 1) break;
        }
        if(i == k) return false;
    }

    return true;
}

long long rho(const long long &N) {
    if(is_prime(N)) return N;

    random_device rnd;
    default_random_engine engine(rnd());
    uniform_int_distribution<long long> rand(2,N - 1);

    for(int c = 1;;++c) {
        long long x = rand(engine);
        long long y = x;
        long long d = 1;
        auto f = [&](long long a) -> long long {
            return (mul(a,a,N) + c) % N;
        };
        while(d == 1) {
            x = f(x);
            y = f(f(y));
            d = gcd(abs(x - y),N);
            if(1 < d && d < N) {
                return rho(d);
            }
        }
    }
}

vector<long long> factorize(long long N) {
    vector<long long> ret;

    while(!(N & 1)) {
        N >>= 1;
        ret.push_back(2);
    }

    while(N > 1) {
        long long d = rho(N);
        while(N % d == 0) {
            N /= d;
            ret.push_back(d);
        }
    }

    sort(ret.begin(),ret.end());
    return ret;
}
