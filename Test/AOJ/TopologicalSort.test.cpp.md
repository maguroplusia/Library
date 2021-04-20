---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/TopologicalSort.cpp
    title: Topological Sort
  - icon: ':question:'
    path: Other/Template.cpp
    title: Other/Template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
  bundledCode: "#line 1 \"Test/AOJ/TopologicalSort.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"Other/Template.cpp\"\ntypedef long long ll;\n\
    constexpr int Inf = 1000000030;\nconstexpr ll INF= 2000000000000000000;\nconstexpr\
    \ ll MOD = 1000000007;\nconst double PI = 3.1415926535897;\ntypedef pair<ll,ll>\
    \ P;\ntypedef pair<ll,P> PP;\n\ntemplate<class T> inline bool chmax(T &a, T b)\
    \ {\n    if (a < b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n\
    }\n\ntemplate<class T> inline bool chmin(T &a, T b) {\n    if (a > b) {\n    \
    \    a = b;\n        return 1;\n    }\n    return 0;\n}\n\n\nll mod(ll val, ll\
    \ M) {\n    val = val % M;\n    if(val < 0) {\n        val += M;\n    }\n    return\
    \ val;\n}\n\ntemplate<typename T>\nT RS(T N, T P, T M){\n    if(P == 0) {\n  \
    \      return 1;\n    }\n    if(P < 0) {\n        return 0;\n    }\n    if(P %\
    \ 2 == 0){\n        ll t = RS(N, P/2, M);\n        if(M == -1) return t * t;\n\
    \        return t * t % M;\n    }\n    if(M == -1) {\n        return N * RS(N,P\
    \ - 1,M);\n    }\n    return N * RS(N, P-1, M) % M;\n}\n#line 1 \"Graph/TopologicalSort.cpp\"\
    \nint N;\nvector<int> graph[500010];\nint indegree[500010];\nint outdegree[500010];\n\
    \n//graph\u3092\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3059\u308B\
    \u3002\u8FD4\u308A\u5024\u306Evector\u306B\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u9806\u5E8F\u304C\u683C\u7D0D\u3055\u308C\u308B\nvector<int> topological_sort()\
    \ {\n    for(int i = 0;i < N;i++) {\n        indegree[i] = 0;\n    }\n    for(auto\
    \ x:graph) {\n        for(auto y:x) {\n            indegree[y]++;\n        }\n\
    \    }\n    stack<int> st;\n    for(int i = 0;i < N;i++) {\n        if(indegree[i]\
    \ == 0) {\n            st.push(i);\n        }\n    }\n    vector<int> res;\n \
    \   while(!st.empty()) {\n        int i = st.top();\n        st.pop();\n     \
    \   res.push_back(i);\n        for(auto x:graph[i]) {\n            indegree[x]--;\n\
    \            if(indegree[x] == 0) {\n                st.push(x);\n           \
    \ }\n        }\n    }\n    return res;\n}\n\n//\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u30BD\u30FC\u30C8\u3059\u308B\u901A\u308A\u6570\u3001O(2^N)\u304C\u9593\u306B\
    \u5408\u3046\u7A0B\u5EA6\u3067\nll counting() {\n    for(int i = 0;i < N;i++)\
    \ {\n        outdegree[i] = 0;\n    }\n    for(int i = 0;i < N;i++) {\n      \
    \  for(auto x:graph[i]) {\n            outdegree[i] += (1 << x);\n        }\n\
    \    }\n    vector<ll> dp(1 << N);\n    dp.at(0) = 1;\n    for(int i = 0;i < (1\
    \ << N);i++) {\n        for(int j = 0;j < N;j++) {\n            if(!(i & (1 <<\
    \ j)) && !(i & outdegree[j])) {\n                dp.at(i | (1 << j)) += dp.at(i);\n\
    \            }\n        }\n    }\n    return dp.at((1 << N) - 1);\n}\n#line 8\
    \ \"Test/AOJ/TopologicalSort.test.cpp\"\n\nint main() {\n    cin >> N;\n    int\
    \ M;\n    cin >> M;\n    for(int i = 0;i < M;i++) {\n        int s,t;\n      \
    \  cin >> s >> t;\n        graph[s].push_back(t);\n    }\n    vector<int> ret\
    \ = topological_sort();\n    for(int i = 0;i < N;i++) {\n        cout << ret.at(i)\
    \ << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../Graph/TopologicalSort.cpp\"\n\nint main() {\n    cin >> N;\n\
    \    int M;\n    cin >> M;\n    for(int i = 0;i < M;i++) {\n        int s,t;\n\
    \        cin >> s >> t;\n        graph[s].push_back(t);\n    }\n    vector<int>\
    \ ret = topological_sort();\n    for(int i = 0;i < N;i++) {\n        cout << ret.at(i)\
    \ << endl;\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - Graph/TopologicalSort.cpp
  isVerificationFile: true
  path: Test/AOJ/TopologicalSort.test.cpp
  requiredBy: []
  timestamp: '2021-04-20 17:11:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/AOJ/TopologicalSort.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/TopologicalSort.test.cpp
- /verify/Test/AOJ/TopologicalSort.test.cpp.html
title: Test/AOJ/TopologicalSort.test.cpp
---
