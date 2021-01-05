---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/AOJ/Dijkstra.test.cpp
    title: Test/AOJ/Dijkstra.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/Dijkstra.cpp\"\nstruct edge{\n\tint to;\n\tll cost;\n\
    };\n\nint N; //\u9802\u70B9\u6570\nvector<edge> graph[200010];\nll d[200010];\
    \ //\u9802\u70B9s\u304B\u3089\u306E\u6700\u77ED\u8DDD\u96E2\nint pre[200010];\n\
    \nvoid Dijkstra(int s) {\n\t//greater<P>\u3092\u6307\u5B9A\u3059\u308B\u3053\u3068\
    \u3067first\u304C\u5C0F\u3055\u3044\u9806\u306B\u53D6\u308A\u51FA\u305B\u308B\n\
    \tpriority_queue<P,vector<P>,greater<P>> que;\n\tfill(d,d + N,INF);\n\tfill(pre,pre\
    \ + N,-1);\n\td[s] = 0;\n\tque.push(P(0,s));\n\n\twhile(!que.empty()) {\n\t\t\
    P p = que.top();\n\t\tque.pop();\n\t\tint v = p.second;\n\t\tif(d[v] < p.first)\
    \ {\n\t\t\tcontinue;\n\t\t}\n        for(auto x:graph[v]) {\n            if(chmin(d[x.to],d[v]\
    \ + x.cost)) {\n                pre[x.to] = v;\n                que.push(P(d[x.to],x.to));\n\
    \            }\n        }\n\t}\n}\n\n//\u6700\u77ED\u8DEF\u3092\u53D6\u5F97\n\
    vector<int> get_path(int t) {\n\tvector<int> path;\n\twhile(t != -1) {\n\t\tpath.push_back(t);\n\
    \t\tt = pre[t];\n\t}\n\treverse(path.begin(),path.end());\n\treturn path;\n}\n"
  code: "struct edge{\n\tint to;\n\tll cost;\n};\n\nint N; //\u9802\u70B9\u6570\n\
    vector<edge> graph[200010];\nll d[200010]; //\u9802\u70B9s\u304B\u3089\u306E\u6700\
    \u77ED\u8DDD\u96E2\nint pre[200010];\n\nvoid Dijkstra(int s) {\n\t//greater<P>\u3092\
    \u6307\u5B9A\u3059\u308B\u3053\u3068\u3067first\u304C\u5C0F\u3055\u3044\u9806\u306B\
    \u53D6\u308A\u51FA\u305B\u308B\n\tpriority_queue<P,vector<P>,greater<P>> que;\n\
    \tfill(d,d + N,INF);\n\tfill(pre,pre + N,-1);\n\td[s] = 0;\n\tque.push(P(0,s));\n\
    \n\twhile(!que.empty()) {\n\t\tP p = que.top();\n\t\tque.pop();\n\t\tint v = p.second;\n\
    \t\tif(d[v] < p.first) {\n\t\t\tcontinue;\n\t\t}\n        for(auto x:graph[v])\
    \ {\n            if(chmin(d[x.to],d[v] + x.cost)) {\n                pre[x.to]\
    \ = v;\n                que.push(P(d[x.to],x.to));\n            }\n        }\n\
    \t}\n}\n\n//\u6700\u77ED\u8DEF\u3092\u53D6\u5F97\nvector<int> get_path(int t)\
    \ {\n\tvector<int> path;\n\twhile(t != -1) {\n\t\tpath.push_back(t);\n\t\tt =\
    \ pre[t];\n\t}\n\treverse(path.begin(),path.end());\n\treturn path;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Dijkstra.cpp
  requiredBy: []
  timestamp: '2021-01-05 12:22:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/AOJ/Dijkstra.test.cpp
documentation_of: Graph/Dijkstra.cpp
layout: document
redirect_from:
- /library/Graph/Dijkstra.cpp
- /library/Graph/Dijkstra.cpp.html
title: Graph/Dijkstra.cpp
---
