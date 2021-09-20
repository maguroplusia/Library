---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SlidingWindowAggregation.cpp
    title: Sliding Window Aggregation (SWAG)
  - icon: ':question:'
    path: Other/Template.cpp
    title: Other/Template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"Test/yosupo-judge/SlidingWindowAggregation.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Other/Template.cpp\"\
    \nconstexpr int Inf = 2000000030;\nconstexpr long long INF= 2000000000000000000;\n\
    \ntemplate<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return\
    \ true; } return false; }\ntemplate<typename T> inline bool chmin(T &a, T b) {\
    \ if (a > b) { a = b; return true; } return false; }\n#line 1 \"DataStructure/SlidingWindowAggregation.cpp\"\
    \ntemplate<class T>\nclass SWAG {\n    class Node {\n    public:\n        T val,sum;\n\
    \        Node(const T& val,const T& sum) : val(val),sum(sum) {}\n    };\n\n  \
    \  std::stack<Node> front_stack,back_stack;\n    function<T(T,T)> op;\n\npublic:\n\
    \    SWAG(const function<T(T,T)> op) : op(op) {}\n\n    bool empty() {\n     \
    \   return front_stack.empty() && back_stack.empty();\n    }\n\n    T fold_all()\
    \ {\n        assert(!empty());\n        if(front_stack.empty()) {\n          \
    \  return back_stack.top().sum;\n        }\n        else if(back_stack.empty())\
    \ {\n            return front_stack.top().sum;\n        }\n        else {\n  \
    \          return op(front_stack.top().sum,back_stack.top().sum);\n        }\n\
    \    }\n\n    void push(T x) {\n        if(back_stack.empty()) back_stack.emplace(x,x);\n\
    \        else back_stack.emplace(x,op(back_stack.top().sum,x));\n    }\n\n   \
    \ void pop() {\n        assert(!empty());\n        if(front_stack.empty()) {\n\
    \            front_stack.emplace(back_stack.top().val,back_stack.top().val);\n\
    \            back_stack.pop();\n            while(!back_stack.empty()) {\n   \
    \             T tmp{op(back_stack.top().val,front_stack.top().sum)};\n       \
    \         front_stack.emplace(back_stack.top().val,tmp);\n                back_stack.pop();\n\
    \            }\n        }\n        front_stack.pop();\n    }\n};\n#line 8 \"Test/yosupo-judge/SlidingWindowAggregation.test.cpp\"\
    \n\nconstexpr long long MOD = 998244353;\n\nusing S = pair<long long,long long>;\n\
    \nS op(S A,S B) {\n    return {A.first * B.first % MOD,(B.first * A.second + B.second)\
    \ % MOD};\n}\n\nint main() {\n    int Q;\n    cin >> Q;\n    SWAG<S> swag(op);\n\
    \    for(int i = 0;i < Q;i++) {\n        int q;\n        cin >> q;\n        if(q\
    \ == 0) {\n            long long a,b;\n            cin >> a >> b;\n          \
    \  swag.push({a,b});\n        }\n        else if(q == 1) {\n            swag.pop();\n\
    \        }\n        else {\n            long long x;\n            cin >> x;\n\
    \            if(swag.empty()) cout << x << endl;\n            else {\n       \
    \         S res = swag.fold_all();\n                cout << (res.first * x + res.second)\
    \ % MOD << endl;\n            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../DataStructure/SlidingWindowAggregation.cpp\"\n\nconstexpr long\
    \ long MOD = 998244353;\n\nusing S = pair<long long,long long>;\n\nS op(S A,S\
    \ B) {\n    return {A.first * B.first % MOD,(B.first * A.second + B.second) %\
    \ MOD};\n}\n\nint main() {\n    int Q;\n    cin >> Q;\n    SWAG<S> swag(op);\n\
    \    for(int i = 0;i < Q;i++) {\n        int q;\n        cin >> q;\n        if(q\
    \ == 0) {\n            long long a,b;\n            cin >> a >> b;\n          \
    \  swag.push({a,b});\n        }\n        else if(q == 1) {\n            swag.pop();\n\
    \        }\n        else {\n            long long x;\n            cin >> x;\n\
    \            if(swag.empty()) cout << x << endl;\n            else {\n       \
    \         S res = swag.fold_all();\n                cout << (res.first * x + res.second)\
    \ % MOD << endl;\n            }\n        }\n    }\n}"
  dependsOn:
  - Other/Template.cpp
  - DataStructure/SlidingWindowAggregation.cpp
  isVerificationFile: true
  path: Test/yosupo-judge/SlidingWindowAggregation.test.cpp
  requiredBy: []
  timestamp: '2021-09-20 19:48:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-judge/SlidingWindowAggregation.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-judge/SlidingWindowAggregation.test.cpp
- /verify/Test/yosupo-judge/SlidingWindowAggregation.test.cpp.html
title: Test/yosupo-judge/SlidingWindowAggregation.test.cpp
---
