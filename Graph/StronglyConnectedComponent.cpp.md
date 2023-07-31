---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/StronglyConnectedComponent.test.cpp
    title: Test/AOJ/StronglyConnectedComponent.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/StronglyConnectedComponent.cpp\"\nclass SCC {\n  \
    \  int n;\n    std::vector<std::vector<int>> graph;\n    std::vector<std::vector<int>>\
    \ rgraph;//\u8FBA\u3092\u9006\u306B\u306F\u3063\u305F\u30B0\u30E9\u30D5\n    std::vector<int>\
    \ vs; //\u5E30\u308A\u304C\u3051\u9806\u306E\u4E26\u3073\n    std::vector<bool>\
    \ used; //\u65E2\u306B\u9802\u70B9\u306B\u8A2A\u308C\u305F\u304B\n    std::vector<int>\
    \ cmp; //\u5C5E\u3059\u308B\u5F37\u9023\u7D50\u6210\u5206\u306E\u30C8\u30DD\u30ED\
    \u30B8\u30AB\u30EB\u9806\u5E8F\n\n\n    void dfs(int v) {\n        used[v] = true;\n\
    \        for(auto x:graph[v]) {\n            if(not used[x]) dfs(x);\n       \
    \ }\n        vs.push_back(v);\n    }\n\n    void rdfs(int v,int k) {\n       \
    \ used[v] = true;\n        cmp[v] = k;\n        for(auto x:rgraph[v]) {\n    \
    \        if(!used[x]) rdfs(x,k);\n        }\n    }\n\npublic:\n\n    SCC(int n):\
    \ n(n) {\n        graph.resize(n);\n        rgraph.resize(n);\n        used.resize(n);\n\
    \        cmp.resize(n);\n    }\n\n    void add_edge(int from,int to) {\n     \
    \   graph[from].push_back(to);\n        rgraph[to].push_back(from);\n    }\n\n\
    \    //\u8FD4\u308A\u5024\u306F\u5206\u89E3\u3057\u305F\u5F8C\u306E\u9802\u70B9\
    \u306E\u6570\n    int scc() {\n        vs.clear();\n        for(int v = 0;v <\
    \ n;v++) {\n            if(not used[v]) dfs(v);\n        }\n\n        for(int\
    \ i = 0;i < n;i++) {\n            used[i] = false;\n        }\n\n        int k\
    \ = 0;\n        for(int i = vs.size() - 1;i >= 0;i--) {\n            if(not used[vs[i]])\
    \ rdfs(vs[i],k++);\n        }\n        return k;\n    }\n\n    int operator[](int\
    \ k) {return cmp[k];}\n\n    bool same(int a,int b) {\n        return cmp[a] ==\
    \ cmp[b];\n    }\n};\n"
  code: "class SCC {\n    int n;\n    std::vector<std::vector<int>> graph;\n    std::vector<std::vector<int>>\
    \ rgraph;//\u8FBA\u3092\u9006\u306B\u306F\u3063\u305F\u30B0\u30E9\u30D5\n    std::vector<int>\
    \ vs; //\u5E30\u308A\u304C\u3051\u9806\u306E\u4E26\u3073\n    std::vector<bool>\
    \ used; //\u65E2\u306B\u9802\u70B9\u306B\u8A2A\u308C\u305F\u304B\n    std::vector<int>\
    \ cmp; //\u5C5E\u3059\u308B\u5F37\u9023\u7D50\u6210\u5206\u306E\u30C8\u30DD\u30ED\
    \u30B8\u30AB\u30EB\u9806\u5E8F\n\n\n    void dfs(int v) {\n        used[v] = true;\n\
    \        for(auto x:graph[v]) {\n            if(not used[x]) dfs(x);\n       \
    \ }\n        vs.push_back(v);\n    }\n\n    void rdfs(int v,int k) {\n       \
    \ used[v] = true;\n        cmp[v] = k;\n        for(auto x:rgraph[v]) {\n    \
    \        if(!used[x]) rdfs(x,k);\n        }\n    }\n\npublic:\n\n    SCC(int n):\
    \ n(n) {\n        graph.resize(n);\n        rgraph.resize(n);\n        used.resize(n);\n\
    \        cmp.resize(n);\n    }\n\n    void add_edge(int from,int to) {\n     \
    \   graph[from].push_back(to);\n        rgraph[to].push_back(from);\n    }\n\n\
    \    //\u8FD4\u308A\u5024\u306F\u5206\u89E3\u3057\u305F\u5F8C\u306E\u9802\u70B9\
    \u306E\u6570\n    int scc() {\n        vs.clear();\n        for(int v = 0;v <\
    \ n;v++) {\n            if(not used[v]) dfs(v);\n        }\n\n        for(int\
    \ i = 0;i < n;i++) {\n            used[i] = false;\n        }\n\n        int k\
    \ = 0;\n        for(int i = vs.size() - 1;i >= 0;i--) {\n            if(not used[vs[i]])\
    \ rdfs(vs[i],k++);\n        }\n        return k;\n    }\n\n    int operator[](int\
    \ k) {return cmp[k];}\n\n    bool same(int a,int b) {\n        return cmp[a] ==\
    \ cmp[b];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/StronglyConnectedComponent.cpp
  requiredBy: []
  timestamp: '2023-07-31 10:53:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/StronglyConnectedComponent.test.cpp
documentation_of: Graph/StronglyConnectedComponent.cpp
layout: document
redirect_from:
- /library/Graph/StronglyConnectedComponent.cpp
- /library/Graph/StronglyConnectedComponent.cpp.html
title: Graph/StronglyConnectedComponent.cpp
---