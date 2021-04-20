---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/AOJ/TopologicalSort.test.cpp
    title: Test/AOJ/TopologicalSort.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/TopologicalSort.cpp\"\nint N;\nvector<int> graph[500010];\n\
    int indegree[500010];\nint outdegree[500010];\n\n//graph\u3092\u30C8\u30DD\u30ED\
    \u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3059\u308B\u3002\u8FD4\u308A\u5024\u306E\
    vector\u306B\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u304C\u683C\u7D0D\
    \u3055\u308C\u308B\nvector<int> topological_sort() {\n    for(int i = 0;i < N;i++)\
    \ {\n        indegree[i] = 0;\n    }\n    for(auto x:graph) {\n        for(auto\
    \ y:x) {\n            indegree[y]++;\n        }\n    }\n    stack<int> st;\n \
    \   for(int i = 0;i < N;i++) {\n        if(indegree[i] == 0) {\n            st.push(i);\n\
    \        }\n    }\n    vector<int> res;\n    while(!st.empty()) {\n        int\
    \ i = st.top();\n        st.pop();\n        res.push_back(i);\n        for(auto\
    \ x:graph[i]) {\n            indegree[x]--;\n            if(indegree[x] == 0)\
    \ {\n                st.push(x);\n            }\n        }\n    }\n    return\
    \ res;\n}\n\n//\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3059\u308B\
    \u901A\u308A\u6570\u3001O(2^N)\u304C\u9593\u306B\u5408\u3046\u7A0B\u5EA6\u3067\
    \nll counting() {\n    for(int i = 0;i < N;i++) {\n        outdegree[i] = 0;\n\
    \    }\n    for(int i = 0;i < N;i++) {\n        for(auto x:graph[i]) {\n     \
    \       outdegree[i] += (1 << x);\n        }\n    }\n    vector<ll> dp(1 << N);\n\
    \    dp.at(0) = 1;\n    for(int i = 0;i < (1 << N);i++) {\n        for(int j =\
    \ 0;j < N;j++) {\n            if(!(i & (1 << j)) && !(i & outdegree[j])) {\n \
    \               dp.at(i | (1 << j)) += dp.at(i);\n            }\n        }\n \
    \   }\n    return dp.at((1 << N) - 1);\n}\n"
  code: "int N;\nvector<int> graph[500010];\nint indegree[500010];\nint outdegree[500010];\n\
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
    \            }\n        }\n    }\n    return dp.at((1 << N) - 1);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/TopologicalSort.cpp
  requiredBy: []
  timestamp: '2021-04-20 17:11:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/AOJ/TopologicalSort.test.cpp
documentation_of: Graph/TopologicalSort.cpp
layout: document
title: Topological Sort
---

スペシャルジャッジの関係でバツ印がついていますがおそらく問題はありません。
