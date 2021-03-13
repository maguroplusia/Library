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
    \ntypedef long long ll;\nconstexpr int Inf = 1000000030;\nconstexpr ll INF= 2000000000000000000;\n\
    constexpr ll MOD = 1000000007;\nconst double PI = 3.1415926535897;\ntypedef pair<ll,ll>\
    \ P;\ntypedef pair<ll,P> PP;\n\ntemplate<class T> inline bool chmax(T &a, T b)\
    \ {\n    if (a < b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n\
    }\n\ntemplate<class T> inline bool chmin(T &a, T b) {\n    if (a > b) {\n    \
    \    a = b;\n        return 1;\n    }\n    return 0;\n}\n\n\nll mod(ll val, ll\
    \ M) {\n    val = val % M;\n    if(val < 0) {\n        val += M;\n    }\n    return\
    \ val;\n}\n\ntemplate<typename T>\nT RS(T N, T P, T M){\n    if(P == 0) {\n  \
    \      return 1;\n    }\n    if(P < 0) {\n        return 0;\n    }\n    if(P %\
    \ 2 == 0){\n        ll t = RS(N, P/2, M);\n        if(M == -1) return t * t;\n\
    \        return t * t % M;\n    }\n    if(M == -1) {\n        return N * RS(N,P\
    \ - 1,M);\n    }\n    return N * RS(N, P-1, M) % M;\n}\n#line 1 \"Graph/StronglyConnectedComponent.cpp\"\
    \nclass SCC {\n    int N;\n    vector<int> graph[200010];\n    vector<int> rgraph[200010];//\u8FBA\
    \u3092\u9006\u306B\u306F\u3063\u305F\u30B0\u30E9\u30D5\n    vector<int> vs; //\u5E30\
    \u308A\u304C\u3051\u9806\u306E\u4E26\u3073\n    bool used[200010]; //\u65E2\u306B\
    \u9802\u70B9\u306B\u8A2A\u308C\u305F\u304B\n    int cmp[200010]; //\u5C5E\u3059\
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
    \n    bool same(int a,int b) {\n        return cmp[a] == cmp[b];\n    }\n};\n\
    #line 8 \"Test/AOJ/StronglyConnectedComponent.test.cpp\"\n\nint main() {\n   \
    \ int N,M;\n    cin >> N >> M;\n    SCC scc(N);\n    for(int i = 0;i < M;i++)\
    \ {\n        int s,t;\n        cin >> s >> t;\n        scc.add_edge(s,t);\n  \
    \  }\n    scc.scc();\n    int Q;\n    cin >> Q;\n    for(int i = 0;i < Q;i++)\
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
  timestamp: '2021-01-18 19:46:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/StronglyConnectedComponent.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/StronglyConnectedComponent.test.cpp
- /verify/Test/AOJ/StronglyConnectedComponent.test.cpp.html
title: Test/AOJ/StronglyConnectedComponent.test.cpp
---
