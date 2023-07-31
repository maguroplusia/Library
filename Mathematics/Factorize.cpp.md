---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-judge/Factorize.test.cpp
    title: Test/yosupo-judge/Factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Mathematics/Factorize.cpp\"\nlong long mul(long long  a,long\
    \ long b,long long m) {\n    __int128 a_ = a;\n    __int128 b_ = b;\n    __int128\
    \ m_ = m;\n    __int128 ret = a_ * b_ % m_;\n    long long res = ret;\n    return\
    \ res;\n}\n\nbool is_prime(const long long& n) {\n    if(n == 1) return false;\n\
    \    for(long long p : {2,3,5,7,11,13,17,19,23,29,31,37}) {\n        if(n == p)\
    \ return true;\n        if(n % p == 0) return false;\n    }\n\n    long long d\
    \ = n - 1;\n    int k = 0;\n    while(!(d & 1)) {\n        k++;\n        d >>=\
    \ 1;\n    }\n\n    auto modpow = [](long long A,long long B,const long long& M)\
    \ -> long long {\n        long long ret = 1;\n        while(B) {\n           \
    \ if(B & 1) ret = mul(ret,A,M);\n            B /= 2;\n            A = mul(A,A,M);\n\
    \        }\n        return ret;\n    };\n\n    std::random_device rnd;\n    std::default_random_engine\
    \ engine(rnd());\n    std::uniform_int_distribution<long long> rand(2,n - 1);\n\
    \n    for(int tmp = 0;tmp < 50;tmp++) {\n        long long a = rand(engine);\n\
    \        long long y = modpow(a,d,n);\n        if(y == 1 || y == n - 1) continue;\n\
    \n        int i = 0;\n        for(i = 1;i < k;i++) {\n            y = mul(y,y,n);\n\
    \            if(y == n - 1) break;\n        }\n        if(i == k) return false;\n\
    \    }\n\n    return true;\n}\n\nlong long rho(const long long &n) {\n    if(is_prime(n))\
    \ return n;\n\n    std::random_device rnd;\n    std::default_random_engine engine(rnd());\n\
    \    std::uniform_int_distribution<long long> rand(2,n - 1);\n\n    for(int c\
    \ = 1;;++c) {\n        long long x = rand(engine);\n        long long y = x;\n\
    \        long long d = 1;\n        auto f = [&](long long a) -> long long {\n\
    \            return (mul(a,a,n) + c) % n;\n        };\n        while(d == 1) {\n\
    \            x = f(x);\n            y = f(f(y));\n            d = gcd(abs(x -\
    \ y),n);\n            if(1 < d && d < n) {\n                return rho(d);\n \
    \           }\n        }\n    }\n}\n\nstd::vector<long long> factorize(long long\
    \ n) {\n    std::vector<long long> ret;\n\n    while(!(n & 1)) {\n        n >>=\
    \ 1;\n        ret.push_back(2);\n    }\n\n    while(n > 1) {\n        long long\
    \ d = rho(n);\n        while(n % d == 0) {\n            n /= d;\n            ret.push_back(d);\n\
    \        }\n    }\n\n    std::sort(ret.begin(),ret.end());\n    return ret;\n\
    }\n"
  code: "long long mul(long long  a,long long b,long long m) {\n    __int128 a_ =\
    \ a;\n    __int128 b_ = b;\n    __int128 m_ = m;\n    __int128 ret = a_ * b_ %\
    \ m_;\n    long long res = ret;\n    return res;\n}\n\nbool is_prime(const long\
    \ long& n) {\n    if(n == 1) return false;\n    for(long long p : {2,3,5,7,11,13,17,19,23,29,31,37})\
    \ {\n        if(n == p) return true;\n        if(n % p == 0) return false;\n \
    \   }\n\n    long long d = n - 1;\n    int k = 0;\n    while(!(d & 1)) {\n   \
    \     k++;\n        d >>= 1;\n    }\n\n    auto modpow = [](long long A,long long\
    \ B,const long long& M) -> long long {\n        long long ret = 1;\n        while(B)\
    \ {\n            if(B & 1) ret = mul(ret,A,M);\n            B /= 2;\n        \
    \    A = mul(A,A,M);\n        }\n        return ret;\n    };\n\n    std::random_device\
    \ rnd;\n    std::default_random_engine engine(rnd());\n    std::uniform_int_distribution<long\
    \ long> rand(2,n - 1);\n\n    for(int tmp = 0;tmp < 50;tmp++) {\n        long\
    \ long a = rand(engine);\n        long long y = modpow(a,d,n);\n        if(y ==\
    \ 1 || y == n - 1) continue;\n\n        int i = 0;\n        for(i = 1;i < k;i++)\
    \ {\n            y = mul(y,y,n);\n            if(y == n - 1) break;\n        }\n\
    \        if(i == k) return false;\n    }\n\n    return true;\n}\n\nlong long rho(const\
    \ long long &n) {\n    if(is_prime(n)) return n;\n\n    std::random_device rnd;\n\
    \    std::default_random_engine engine(rnd());\n    std::uniform_int_distribution<long\
    \ long> rand(2,n - 1);\n\n    for(int c = 1;;++c) {\n        long long x = rand(engine);\n\
    \        long long y = x;\n        long long d = 1;\n        auto f = [&](long\
    \ long a) -> long long {\n            return (mul(a,a,n) + c) % n;\n        };\n\
    \        while(d == 1) {\n            x = f(x);\n            y = f(f(y));\n  \
    \          d = gcd(abs(x - y),n);\n            if(1 < d && d < n) {\n        \
    \        return rho(d);\n            }\n        }\n    }\n}\n\nstd::vector<long\
    \ long> factorize(long long n) {\n    std::vector<long long> ret;\n\n    while(!(n\
    \ & 1)) {\n        n >>= 1;\n        ret.push_back(2);\n    }\n\n    while(n >\
    \ 1) {\n        long long d = rho(n);\n        while(n % d == 0) {\n         \
    \   n /= d;\n            ret.push_back(d);\n        }\n    }\n\n    std::sort(ret.begin(),ret.end());\n\
    \    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/Factorize.cpp
  requiredBy: []
  timestamp: '2023-07-31 11:45:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-judge/Factorize.test.cpp
documentation_of: Mathematics/Factorize.cpp
layout: document
redirect_from:
- /library/Mathematics/Factorize.cpp
- /library/Mathematics/Factorize.cpp.html
title: Mathematics/Factorize.cpp
---
