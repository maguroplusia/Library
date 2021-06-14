---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/StronglyConnectedComponent.cpp
    title: Graph/StronglyConnectedComponent.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C
  bundledCode: "#line 1 \"Test/AOJ/StronglyConnectedComponent.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Other/Template.cpp\"\
    \ntypedef long long ll;\nconstexpr int Inf = 2000000030;\nconstexpr long long\
    \ INF= 2000000000000000000;\n\ntemplate<typename T> inline bool chmax(T &a, T\
    \ b) { if (a < b) { a = b; return true; } return false; }\ntemplate<typename T>\
    \ inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false;\
    \ }\n#line 1 \"Graph/StronglyConnectedComponent.cpp\"\nclass SCC {\n    int N;\n\
    \    vector<int> graph[100010];\n    vector<int> rgraph[100010];//\u8FBA\u3092\
    \u9006\u306B\u306F\u3063\u305F\u30B0\u30E9\u30D5\n    vector<int> vs; //\u5E30\
    \u308A\u304C\u3051\u9806\u306E\u4E26\u3073\n    bool used[100010]; //\u65E2\u306B\
    \u9802\u70B9\u306B\u8A2A\u308C\u305F\u304B\n    int cmp[100010]; //\u5C5E\u3059\
    \u308B\u5F37\u9023\u7D50\u6210\u5206\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u9806\u5E8F\n\n\n    void dfs(int v) {\n        used[v] = true;\n        for(auto\
    \ x:graph[v]) {\n            if(!used[x]) dfs(x);\n        }\n        vs.push_back(v);\n\
    \    }\n\n    void rdfs(int v,int k) {\n        used[v] = true;\n        cmp[v]\
    \ = k;\n        for(auto x:rgraph[v]) {\n            if(!used[x]) rdfs(x,k);\n\
    \        }\n    }\n\npublic:\n\n    SCC(int n) {\n        N = n;\n    }\n\n  \
    \  void add_edge(int from,int to) {\n        graph[from].push_back(to);\n    \
    \    rgraph[to].push_back(from);\n    }\n\n    //\u8FD4\u308A\u5024\u306F\u5206\
    \u89E3\u3057\u305F\u5F8C\u306E\u9802\u70B9\u306E\u6570\n    int scc() {\n    \
    \    memset(used,0,sizeof(used));\n        vs.clear();\n        for(int v = 0;v\
    \ < N;v++) {\n            if(!used[v]) dfs(v);\n        }\n        memset(used,0,sizeof(used));\n\
    \        int k = 0;\n        for(int i = vs.size() - 1;i >= 0;i--) {\n       \
    \     if(!used[vs[i]]) rdfs(vs[i],k++);\n        }\n        return k;\n    }\n\
    \n    int operator[](int k) {return cmp[k];}\n\n    bool same(int a,int b) {\n\
    \        return cmp[a] == cmp[b];\n    }\n};\n#line 8 \"Test/AOJ/StronglyConnectedComponent.test.cpp\"\
    \n\nint main() {\n    int N,M;\n    cin >> N >> M;\n    SCC scc(N);\n    for(int\
    \ i = 0;i < M;i++) {\n        int s,t;\n        cin >> s >> t;\n        scc.add_edge(s,t);\n\
    \    }\n    scc.scc();\n    int Q;\n    cin >> Q;\n    for(int i = 0;i < Q;i++)\
    \ {\n        int u,v;\n        cin >> u >> v;\n        cout << scc.same(u,v) <<\
    \ endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../Graph/StronglyConnectedComponent.cpp\"\n\nint main() {\n   \
    \ int N,M;\n    cin >> N >> M;\n    SCC scc(N);\n    for(int i = 0;i < M;i++)\
    \ {\n        int s,t;\n        cin >> s >> t;\n        scc.add_edge(s,t);\n  \
    \  }\n    scc.scc();\n    int Q;\n    cin >> Q;\n    for(int i = 0;i < Q;i++)\
    \ {\n        int u,v;\n        cin >> u >> v;\n        cout << scc.same(u,v) <<\
    \ endl;\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - Graph/StronglyConnectedComponent.cpp
  isVerificationFile: true
  path: Test/AOJ/StronglyConnectedComponent.test.cpp
  requiredBy: []
  timestamp: '2021-06-14 17:23:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/StronglyConnectedComponent.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/StronglyConnectedComponent.test.cpp
- /verify/Test/AOJ/StronglyConnectedComponent.test.cpp.html
title: Test/AOJ/StronglyConnectedComponent.test.cpp
---
