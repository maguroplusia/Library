---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Mathematics/Factorize.cpp\"\nlong long mul(long long  A,long\
    \ long B,long long M) {\n    __int128 a = A;\n    __int128 b = B;\n    __int128\
    \ m = M;\n    __int128 ret = a * b % m;\n    long long res = ret;\n    return\
    \ res;\n}\n\nbool is_prime(const long long& N) {\n    if(N == 1) return false;\n\
    \    for(long long p : {2,3,5,7,11,13,17,19,23,29,31,37}) {\n        if(N == p)\
    \ return true;\n        if(N % p == 0) return false;\n    }\n\n    long long d\
    \ = N - 1;\n    int k = 0;\n    while(!(d & 1)) {\n        k++;\n        d >>=\
    \ 1;\n    }\n\n    auto modpow = [](long long A,long long B,const long long& M)\
    \ -> long long {\n        long long ret = 1;\n        while(B) {\n           \
    \ if(B & 1) ret = mul(ret,A,M);\n            B /= 2;\n            A = mul(A,A,M);\n\
    \        }\n        return ret;\n    };\n\n    random_device rnd;\n    default_random_engine\
    \ engine(rnd());\n    uniform_int_distribution<long long> rand(2,N - 1);\n\n \
    \   for(int tmp = 0;tmp < 50;tmp++) {\n        long long a = rand(engine);\n \
    \       long long y = modpow(a,d,N);\n        if(y == 1 || y == N - 1) continue;\n\
    \n        int i = 0;\n        for(i = 1;i < k;i++) {\n            y = mul(y,y,N);\n\
    \            if(y == N - 1) break;\n        }\n        if(i == k) return false;\n\
    \    }\n\n    return true;\n}\n\nlong long rho(const long long &N) {\n    if(is_prime(N))\
    \ return N;\n\n    random_device rnd;\n    default_random_engine engine(rnd());\n\
    \    uniform_int_distribution<long long> rand(2,N - 1);\n\n    for(int c = 1;;++c)\
    \ {\n        long long x = rand(engine);\n        long long y = x;\n        long\
    \ long d = 1;\n        auto f = [&](long long a) -> long long {\n            return\
    \ (mul(a,a,N) + c) % N;\n        };\n        while(d == 1) {\n            x =\
    \ f(x);\n            y = f(f(y));\n            d = gcd(abs(x - y),N);\n      \
    \      if(1 < d && d < N) {\n                return rho(d);\n            }\n \
    \       }\n    }\n}\n\nvector<long long> factorize(long long N) {\n    vector<long\
    \ long> ret;\n\n    while(!(N & 1)) {\n        N >>= 1;\n        ret.push_back(2);\n\
    \    }\n\n    while(N > 1) {\n        long long d = rho(N);\n        while(N %\
    \ d == 0) {\n            N /= d;\n            ret.push_back(d);\n        }\n \
    \   }\n\n    sort(ret.begin(),ret.end());\n    return ret;\n}\n"
  code: "long long mul(long long  A,long long B,long long M) {\n    __int128 a = A;\n\
    \    __int128 b = B;\n    __int128 m = M;\n    __int128 ret = a * b % m;\n   \
    \ long long res = ret;\n    return res;\n}\n\nbool is_prime(const long long& N)\
    \ {\n    if(N == 1) return false;\n    for(long long p : {2,3,5,7,11,13,17,19,23,29,31,37})\
    \ {\n        if(N == p) return true;\n        if(N % p == 0) return false;\n \
    \   }\n\n    long long d = N - 1;\n    int k = 0;\n    while(!(d & 1)) {\n   \
    \     k++;\n        d >>= 1;\n    }\n\n    auto modpow = [](long long A,long long\
    \ B,const long long& M) -> long long {\n        long long ret = 1;\n        while(B)\
    \ {\n            if(B & 1) ret = mul(ret,A,M);\n            B /= 2;\n        \
    \    A = mul(A,A,M);\n        }\n        return ret;\n    };\n\n    random_device\
    \ rnd;\n    default_random_engine engine(rnd());\n    uniform_int_distribution<long\
    \ long> rand(2,N - 1);\n\n    for(int tmp = 0;tmp < 50;tmp++) {\n        long\
    \ long a = rand(engine);\n        long long y = modpow(a,d,N);\n        if(y ==\
    \ 1 || y == N - 1) continue;\n\n        int i = 0;\n        for(i = 1;i < k;i++)\
    \ {\n            y = mul(y,y,N);\n            if(y == N - 1) break;\n        }\n\
    \        if(i == k) return false;\n    }\n\n    return true;\n}\n\nlong long rho(const\
    \ long long &N) {\n    if(is_prime(N)) return N;\n\n    random_device rnd;\n \
    \   default_random_engine engine(rnd());\n    uniform_int_distribution<long long>\
    \ rand(2,N - 1);\n\n    for(int c = 1;;++c) {\n        long long x = rand(engine);\n\
    \        long long y = x;\n        long long d = 1;\n        auto f = [&](long\
    \ long a) -> long long {\n            return (mul(a,a,N) + c) % N;\n        };\n\
    \        while(d == 1) {\n            x = f(x);\n            y = f(f(y));\n  \
    \          d = gcd(abs(x - y),N);\n            if(1 < d && d < N) {\n        \
    \        return rho(d);\n            }\n        }\n    }\n}\n\nvector<long long>\
    \ factorize(long long N) {\n    vector<long long> ret;\n\n    while(!(N & 1))\
    \ {\n        N >>= 1;\n        ret.push_back(2);\n    }\n\n    while(N > 1) {\n\
    \        long long d = rho(N);\n        while(N % d == 0) {\n            N /=\
    \ d;\n            ret.push_back(d);\n        }\n    }\n\n    sort(ret.begin(),ret.end());\n\
    \    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/Factorize.cpp
  requiredBy: []
  timestamp: '2021-06-25 22:26:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mathematics/Factorize.cpp
layout: document
redirect_from:
- /library/Mathematics/Factorize.cpp
- /library/Mathematics/Factorize.cpp.html
title: Mathematics/Factorize.cpp
---
