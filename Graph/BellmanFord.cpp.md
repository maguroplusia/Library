---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/BellmanFord.cpp\"\n//\u9802\u70B9from\u304B\u3089\u9802\
    \u70B9to\u3078\u306E\u30B3\u30B9\u30C8cost\u306E\u8FBA\nstruct edge{\n\tint from,to;\n\
    \    ll cost;\n};\n\nedge es[200010]; //\u8FBA\nll d[200010]; //\u6700\u77ED\u8DDD\
    \u96E2\nint N,M; //\u9802\u70B9\u6570\u3001\u8FBA\u6570\n\n//s\u756A\u76EE\u306E\
    \u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DDD\u96E2\
    \u3092\u6C42\u3081\u308B\uFF08\u305F\u3060\u3057\u59CB\u70B9\u304B\u3089\u7D42\
    \u70B9\u307E\u3067\u306E\u9593\u306B\u8CA0\u9589\u8DEF\u304C\u3042\u308B\u5834\
    \u5408\u306Ffalse\u3092\u8FD4\u3059\uFF09\nbool BellmanFord(int s,int g) {\n\t\
    for(int i = 0;i < N;i++) {\n\t\td[i] = INF;\n\t}\n\td[s] = 0;\n\tfor(int i = 0;i\
    \ < N * 2;i++) {\n\t\tfor(auto x:es) {\n\t\t\tif(d[e.from] < INF && d[e.from]\
    \ + e.cost < d[e.to])  {\n\t\t\t\tif(i >= N - 1 && e.to == g) {\n\t\t\t\t\treturn\
    \ false;\n\t\t\t\t}\n\t\t\t\telse if(i >= N - 1) {\n\t\t\t\t\td[e.to] = -INF;\n\
    \t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\td[e.to] = d[e.from] + e.cost;\n\t\t\t\t}\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn d[g];\n}\n\n//true\u306A\u3089\u8CA0\u306E\u9589\
    \u8DEF\u304C\u5B58\u5728\u3059\u308B\nbool find_negative_roop() {\n\tmemset(d,0,sizeof(d));\n\
    \tfor(int i = 0;i < N;i++) {\n\t\tfor(int j = 0;j < M;j++) {\n\t\t\tedge e = es[j];\n\
    \t\t\tif(d[e.to] > d[e.from] + e.cost) {\n\t\t\t\td[e.to] = d[e.from] + e.cost;\n\
    \t\t\t\tif(i == N - 1) return true;\n\t\t\t}\n\t\t}\n\t}\n\treturn false;\n}\n"
  code: "//\u9802\u70B9from\u304B\u3089\u9802\u70B9to\u3078\u306E\u30B3\u30B9\u30C8\
    cost\u306E\u8FBA\nstruct edge{\n\tint from,to;\n    ll cost;\n};\n\nedge es[200010];\
    \ //\u8FBA\nll d[200010]; //\u6700\u77ED\u8DDD\u96E2\nint N,M; //\u9802\u70B9\u6570\
    \u3001\u8FBA\u6570\n\n//s\u756A\u76EE\u306E\u9802\u70B9\u304B\u3089\u5404\u9802\
    \u70B9\u3078\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\uFF08\u305F\
    \u3060\u3057\u59CB\u70B9\u304B\u3089\u7D42\u70B9\u307E\u3067\u306E\u9593\u306B\
    \u8CA0\u9589\u8DEF\u304C\u3042\u308B\u5834\u5408\u306Ffalse\u3092\u8FD4\u3059\uFF09\
    \nbool BellmanFord(int s,int g) {\n\tfor(int i = 0;i < N;i++) {\n\t\td[i] = INF;\n\
    \t}\n\td[s] = 0;\n\tfor(int i = 0;i < N * 2;i++) {\n\t\tfor(auto x:es) {\n\t\t\
    \tif(d[e.from] < INF && d[e.from] + e.cost < d[e.to])  {\n\t\t\t\tif(i >= N -\
    \ 1 && e.to == g) {\n\t\t\t\t\treturn false;\n\t\t\t\t}\n\t\t\t\telse if(i >=\
    \ N - 1) {\n\t\t\t\t\td[e.to] = -INF;\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\td[e.to]\
    \ = d[e.from] + e.cost;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\treturn d[g];\n}\n\n\
    //true\u306A\u3089\u8CA0\u306E\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\nbool\
    \ find_negative_roop() {\n\tmemset(d,0,sizeof(d));\n\tfor(int i = 0;i < N;i++)\
    \ {\n\t\tfor(int j = 0;j < M;j++) {\n\t\t\tedge e = es[j];\n\t\t\tif(d[e.to] >\
    \ d[e.from] + e.cost) {\n\t\t\t\td[e.to] = d[e.from] + e.cost;\n\t\t\t\tif(i ==\
    \ N - 1) return true;\n\t\t\t}\n\t\t}\n\t}\n\treturn false;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/BellmanFord.cpp
  requiredBy: []
  timestamp: '2021-01-03 18:28:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/BellmanFord.cpp
layout: document
redirect_from:
- /library/Graph/BellmanFord.cpp
- /library/Graph/BellmanFord.cpp.html
title: Graph/BellmanFord.cpp
---
