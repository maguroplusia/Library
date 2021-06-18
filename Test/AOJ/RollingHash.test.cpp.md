---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Other/Template.cpp
    title: Other/Template.cpp
  - icon: ':heavy_check_mark:'
    path: String/RollingHash.cpp
    title: String/RollingHash.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
  bundledCode: "#line 1 \"Test/AOJ/RollingHash.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Other/Template.cpp\"\
    \nconstexpr int Inf = 2000000030;\nconstexpr long long INF= 2000000000000000000;\n\
    \ntemplate<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return\
    \ true; } return false; }\ntemplate<typename T> inline bool chmin(T &a, T b) {\
    \ if (a > b) { a = b; return true; } return false; }\n#line 1 \"String/RollingHash.cpp\"\
    \nclass RollingHash {\n    static const uint64_t mod = (1ull << 61ull) - 1;\n\
    \    vector<uint64_t> power;\n    const uint64_t base;\n\n    //1\u4EE5\u4E0A\
    mod - 1\u4EE5\u4E0B\u306E\u30E9\u30F3\u30C0\u30E0\u306Abase\u3092\u751F\u6210\n\
    \    static inline uint64_t generate_base() {\n        mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<uint64_t> rand((uint64_t)1,(uint64_t)mod - 1);\n\
    \        return rand(engine);\n    }\n\n    //\u8DB3\u3057\u7B97\n    static inline\
    \ uint64_t add(uint64_t a, uint64_t b) {\n        if((a += b) >= mod) a -= mod;\n\
    \        return a;\n    }\n\n    //\u639B\u3051\u7B97\uFF08__uint128_t\u3092\u4F7F\
    \u7528\uFF09\n    static inline uint64_t mul(uint64_t a, uint64_t b) {\n     \
    \   __uint128_t c = (__uint128_t) a * b;\n        return add(c >> 61,c & mod);\n\
    \    }\n\n    inline void expand(size_t sz) {\n        if(power.size() < sz +\
    \ 1) {\n            int pre_sz = (int)power.size();\n            power.resize(sz\
    \ + 1);\n            for(int i = pre_sz - 1;i < sz;i++) {\n                power.at(i\
    \ + 1) = mul(power.at(i),base);\n            }\n        }\n    }\n\npublic:\n\n\
    \    explicit RollingHash(uint64_t base = generate_base()) : base(base),power{1}\
    \ {}\n\n    //\u6587\u5B57\u5217S\u306E\u30CF\u30C3\u30B7\u30E5\u3092\u8FD4\u3059\
    \n    vector<uint64_t> build(string S) {\n        vector<uint64_t> hash(S.size()\
    \ + 1);\n        for (int i = 0; i < S.size(); i++) {\n            hash.at(i +\
    \ 1) = add(mul(hash.at(i),base),S.at(i));\n        }\n        return hash;\n \
    \   }\n\n    //hash\u306E[l,r)\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u8FD4\
    \u3059\n    uint64_t query(vector<uint64_t> &hash,int l,int r) {\n        expand(r\
    \ - l);\n        return add(hash.at(r),mod - mul(hash.at(l),power.at(r - l)));\n\
    \    }\n\n    //\u30CF\u30C3\u30B7\u30E5\u5024h1\u3068\u9577\u3055h2len\u306E\u30CF\
    \u30C3\u30B7\u30E5\u5024h2\u3092\u7D50\u5408\n    uint64_t combine(uint64_t h1,\
    \ uint64_t h2, size_t h2len) {\n        expand(h2len);\n        return add(mul(h1,\
    \ power.at(h2len)), h2);\n    }\n\n    //hash1\u306E\u533A\u9593[l1,r1)\u3068\
    hash2\u306E\u533A\u9593[l2,r2)\u306Elcp\uFF08\u6700\u9577\u5171\u901A\u63A5\u982D\
    \u8F9E\uFF09\u306E\u9577\u3055\u3092\u8FD4\u3059\n    int lcp(vector<uint64_t>\
    \ &hash1,int l1,int r1,vector<uint64_t> &hash2,int l2,int r2) {\n        int len\
    \ = min(r1 - l1,r2 - l2);\n        int ok = 0;\n        int ng = len + 1;\n  \
    \      int mid;\n        while(ng - ok > 1) {\n            mid = (ok + ng) / 2;\n\
    \            if(query(hash1,l1,l1 + mid) == query(hash2,l2,l2 + mid)) ok = mid;\n\
    \            else ng = mid;\n        }\n        return ok;\n    }\n};\n#line 8\
    \ \"Test/AOJ/RollingHash.test.cpp\"\n\nint main() {\n    string T,P;\n    cin\
    \ >> T >> P;\n    if(T.size() < P.size()) return 0;\n    RollingHash rh;\n   \
    \ vector<uint64_t> t = rh.build(T);\n    vector<uint64_t> p = rh.build(P);\n \
    \   uint64_t cnt = rh.query(p,0,P.size());\n    for(int i = 0;i < T.size() - P.size()\
    \ + 1;i++) {\n        if(rh.query(t,i,i + P.size()) == cnt) cout << i << endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../String/RollingHash.cpp\"\n\nint main() {\n    string T,P;\n\
    \    cin >> T >> P;\n    if(T.size() < P.size()) return 0;\n    RollingHash rh;\n\
    \    vector<uint64_t> t = rh.build(T);\n    vector<uint64_t> p = rh.build(P);\n\
    \    uint64_t cnt = rh.query(p,0,P.size());\n    for(int i = 0;i < T.size() -\
    \ P.size() + 1;i++) {\n        if(rh.query(t,i,i + P.size()) == cnt) cout << i\
    \ << endl;\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - String/RollingHash.cpp
  isVerificationFile: true
  path: Test/AOJ/RollingHash.test.cpp
  requiredBy: []
  timestamp: '2021-06-18 21:14:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/RollingHash.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/RollingHash.test.cpp
- /verify/Test/AOJ/RollingHash.test.cpp.html
title: Test/AOJ/RollingHash.test.cpp
---
