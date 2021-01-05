---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/AOJ/BellmanFord.test.cpp
    title: Test/AOJ/BellmanFord.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/BellmanFord.cpp\"\n//\u9802\u70B9from\u304B\u3089\u9802\
    \u70B9to\u3078\u306E\u30B3\u30B9\u30C8cost\u306E\u8FBA\nstruct edge{\n\tint from,to;\n\
    \    ll cost;\n};\n\nedge es[3010]; //\u8FBA\nll dist[3010]; //\u6700\u77ED\u8DDD\
    \u96E2\nint N,M; //\u9802\u70B9\u6570\u3001\u8FBA\u6570\n\n//s\u756A\u76EE\u306E\
    \u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DDD\u96E2\
    \u3092\u6C42\u3081\u308B\uFF08\u305F\u3060\u3057s\u756A\u76EE\u306E\u9802\u70B9\
    \u304B\u3089\u8CA0\u9589\u8DEF\u3092\u8FBF\u3063\u3066\u884C\u3051\u308B\u5834\
    \u5408\u306F-INF\uFF09\nvoid BellmanFord(int s) {\n\tfor(int i = 0;i < N;i++)\
    \ {\n\t\tdist[i] = INF;\n\t}\n\tdist[s] = 0;\n\tfor(int i = 0;i < N * 2;i++) {\n\
    \t\tfor(auto x:es) {\n\t\t\tif(dist[e.from] < INF && dist[e.from] + e.cost < dist[e.to])\
    \  {\n\t\t\t\tif(i >= N - 1) {\n\t\t\t\t\tdist[e.to] = -INF;\n\t\t\t\t}\n\t\t\t\
    \telse {\n\t\t\t\t\tdist[e.to] = dist[e.from] + e.cost;\n\t\t\t\t}\n\t\t\t}\n\t\
    \t}\n\t}\n}\n\n//true\u306A\u3089\u8CA0\u306E\u9589\u8DEF\u304C\u5B58\u5728\u3059\
    \u308B\nbool find_negative_roop() {\n\tmemset(d,0,sizeof(d));\n\tfor(int i = 0;i\
    \ < N;i++) {\n\t\tfor(int j = 0;j < M;j++) {\n\t\t\tedge e = es[j];\n\t\t\tif(dist[e.to]\
    \ > dist[e.from] + e.cost) {\n\t\t\t\tdist[e.to] = dist[e.from] + e.cost;\n\t\t\
    \t\tif(i == N - 1) return true;\n\t\t\t}\n\t\t}\n\t}\n\treturn false;\n}\n"
  code: "//\u9802\u70B9from\u304B\u3089\u9802\u70B9to\u3078\u306E\u30B3\u30B9\u30C8\
    cost\u306E\u8FBA\nstruct edge{\n\tint from,to;\n    ll cost;\n};\n\nedge es[3010];\
    \ //\u8FBA\nll dist[3010]; //\u6700\u77ED\u8DDD\u96E2\nint N,M; //\u9802\u70B9\
    \u6570\u3001\u8FBA\u6570\n\n//s\u756A\u76EE\u306E\u9802\u70B9\u304B\u3089\u5404\
    \u9802\u70B9\u3078\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\uFF08\
    \u305F\u3060\u3057s\u756A\u76EE\u306E\u9802\u70B9\u304B\u3089\u8CA0\u9589\u8DEF\
    \u3092\u8FBF\u3063\u3066\u884C\u3051\u308B\u5834\u5408\u306F-INF\uFF09\nvoid BellmanFord(int\
    \ s) {\n\tfor(int i = 0;i < N;i++) {\n\t\tdist[i] = INF;\n\t}\n\tdist[s] = 0;\n\
    \tfor(int i = 0;i < N * 2;i++) {\n\t\tfor(auto x:es) {\n\t\t\tif(dist[e.from]\
    \ < INF && dist[e.from] + e.cost < dist[e.to])  {\n\t\t\t\tif(i >= N - 1) {\n\t\
    \t\t\t\tdist[e.to] = -INF;\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tdist[e.to] =\
    \ dist[e.from] + e.cost;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n}\n\n//true\u306A\u3089\
    \u8CA0\u306E\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\nbool find_negative_roop()\
    \ {\n\tmemset(d,0,sizeof(d));\n\tfor(int i = 0;i < N;i++) {\n\t\tfor(int j = 0;j\
    \ < M;j++) {\n\t\t\tedge e = es[j];\n\t\t\tif(dist[e.to] > dist[e.from] + e.cost)\
    \ {\n\t\t\t\tdist[e.to] = dist[e.from] + e.cost;\n\t\t\t\tif(i == N - 1) return\
    \ true;\n\t\t\t}\n\t\t}\n\t}\n\treturn false;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/BellmanFord.cpp
  requiredBy: []
  timestamp: '2021-01-05 14:21:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/AOJ/BellmanFord.test.cpp
documentation_of: Graph/BellmanFord.cpp
layout: document
redirect_from:
- /library/Graph/BellmanFord.cpp
- /library/Graph/BellmanFord.cpp.html
title: Graph/BellmanFord.cpp
---
