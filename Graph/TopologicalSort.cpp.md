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
  bundledCode: "#line 1 \"Graph/TopologicalSort.cpp\"\nint N;\nvector<int> graph[200010];\n\
    int indegree[200010];\nint outdegree[200010];\n\nvector<int> topological_sort()\
    \ {\n    for(int i = 0;i < N;i++) {\n        indegree[i] = 0;\n    }\n    for(auto\
    \ x:graph) {\n        for(auto y:x) {\n            indegree[y]++;\n        }\n\
    \    }\n    stack<int> st;\n    for(int i = 0;i < N;i++) {\n        if(indegree[i]\
    \ == 0) {\n            st.push(i);\n        }\n    }\n    vector<int> res;\n \
    \   while(!st.empty()) {\n        int i = st.top();\n        st.pop();\n     \
    \   res.push_back(i);\n        for(auto x:graph[i]) {\n            indegree[x]--;\n\
    \            if(indegree[x] == 0) {\n                st.push(x);\n           \
    \ }\n        }\n    }\n    return res;\n}\n\n//\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u30BD\u30FC\u30C8\u3059\u308B\u65B9\u6CD5\u3001\u305F\u3060\u3057N<=\nll counting()\
    \ {\n    for(int i = 0;i < N;i++) {\n        outdegree[i] = 0;\n    }\n    for(int\
    \ i = 0;i < N;i++) {\n        for(auto x:graph[i]) {\n            outdegree[i]\
    \ += (1 << x);\n        }\n    }\n    vector<ll> dp(1 << N);\n    dp.at(0) = 1;\n\
    \    for(int i = 0;i < (1 << N);i++) {\n        for(int j = 0;j < N;j++) {\n \
    \           if(!(i & (1 << j)) && !(i & outdegree[j])) {\n                dp.at(i\
    \ | (1 << j)) += dp.at(i);\n            }\n        }\n    }\n    return dp.at((1\
    \ << V) - 1);\n}\n"
  code: "int N;\nvector<int> graph[200010];\nint indegree[200010];\nint outdegree[200010];\n\
    \nvector<int> topological_sort() {\n    for(int i = 0;i < N;i++) {\n        indegree[i]\
    \ = 0;\n    }\n    for(auto x:graph) {\n        for(auto y:x) {\n            indegree[y]++;\n\
    \        }\n    }\n    stack<int> st;\n    for(int i = 0;i < N;i++) {\n      \
    \  if(indegree[i] == 0) {\n            st.push(i);\n        }\n    }\n    vector<int>\
    \ res;\n    while(!st.empty()) {\n        int i = st.top();\n        st.pop();\n\
    \        res.push_back(i);\n        for(auto x:graph[i]) {\n            indegree[x]--;\n\
    \            if(indegree[x] == 0) {\n                st.push(x);\n           \
    \ }\n        }\n    }\n    return res;\n}\n\n//\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u30BD\u30FC\u30C8\u3059\u308B\u65B9\u6CD5\u3001\u305F\u3060\u3057N<=\nll counting()\
    \ {\n    for(int i = 0;i < N;i++) {\n        outdegree[i] = 0;\n    }\n    for(int\
    \ i = 0;i < N;i++) {\n        for(auto x:graph[i]) {\n            outdegree[i]\
    \ += (1 << x);\n        }\n    }\n    vector<ll> dp(1 << N);\n    dp.at(0) = 1;\n\
    \    for(int i = 0;i < (1 << N);i++) {\n        for(int j = 0;j < N;j++) {\n \
    \           if(!(i & (1 << j)) && !(i & outdegree[j])) {\n                dp.at(i\
    \ | (1 << j)) += dp.at(i);\n            }\n        }\n    }\n    return dp.at((1\
    \ << V) - 1);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/TopologicalSort.cpp
  requiredBy: []
  timestamp: '2021-01-03 18:28:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/TopologicalSort.cpp
layout: document
redirect_from:
- /library/Graph/TopologicalSort.cpp
- /library/Graph/TopologicalSort.cpp.html
title: Graph/TopologicalSort.cpp
---
