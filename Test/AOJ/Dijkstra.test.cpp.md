---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/Dijkstra.cpp
    title: Graph/Dijkstra.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"Test/AOJ/Dijkstra.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
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
    \ - 1,M);\n    }\n    return N * RS(N, P-1, M) % M;\n}\n#line 1 \"Graph/Dijkstra.cpp\"\
    \nstruct edge{\n    int to;\n    ll cost;\n};\n\nint N; //\u9802\u70B9\u6570\n\
    vector<edge> graph[200010];\nll dist[200010]; //\u9802\u70B9s\u304B\u3089\u306E\
    \u6700\u77ED\u8DDD\u96E2\nint pre[200010];\n\nvoid Dijkstra(int s) {\n    //greater<P>\u3092\
    \u6307\u5B9A\u3059\u308B\u3053\u3068\u3067first\u304C\u5C0F\u3055\u3044\u9806\u306B\
    \u53D6\u308A\u51FA\u305B\u308B\n    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>\
    \ que;\n    fill(dist,dist + N,INF);\n    fill(pre,pre + N,-1);\n    dist[s] =\
    \ 0;\n    que.push(P(0,s));\n\n    while(!que.empty()) {\n        auto [cost,v]\
    \ = que.top();\n        que.pop();\n        if(dist[v] < p.first) continue;\n\
    \        for(auto x:graph[v]) {\n            if(chmin(dist[x.to],dist[v] + cost))\
    \ {\n                pre[x.to] = v;\n                que.push(P(dist[x.to],x.to));\n\
    \            }\n        }\n    }\n}\n\n//\u6700\u77ED\u8DEF\u3092\u53D6\u5F97\n\
    vector<int> get_path(int t) {\n    vector<int> path;\n    while(t != -1) {\n \
    \       path.push_back(t);\n        t = pre[t];\n    }\n    reverse(path.begin(),path.end());\n\
    \    return path;\n}\n#line 8 \"Test/AOJ/Dijkstra.test.cpp\"\n\nint main() {\n\
    \    cin >> N;\n    int M,r;\n    cin >> M >> r;\n    for(int i = 0;i < M;i++)\
    \ {\n        int s,t;\n        ll d;\n        cin >> s >> t >> d;\n        graph[s].push_back(edge{t,d});\n\
    \    }\n    Dijkstra(r);\n    for(int i = 0;i < N;i++) {\n        if(dist[i] ==\
    \ INF) cout << \"INF\" << endl;\n        else cout << dist[i] << endl;\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../Graph/Dijkstra.cpp\"\n\nint main() {\n    cin >> N;\n    int\
    \ M,r;\n    cin >> M >> r;\n    for(int i = 0;i < M;i++) {\n        int s,t;\n\
    \        ll d;\n        cin >> s >> t >> d;\n        graph[s].push_back(edge{t,d});\n\
    \    }\n    Dijkstra(r);\n    for(int i = 0;i < N;i++) {\n        if(dist[i] ==\
    \ INF) cout << \"INF\" << endl;\n        else cout << dist[i] << endl;\n    }\n\
    }\n"
  dependsOn:
  - Other/Template.cpp
  - Graph/Dijkstra.cpp
  isVerificationFile: true
  path: Test/AOJ/Dijkstra.test.cpp
  requiredBy: []
  timestamp: '2021-06-05 10:38:27+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/AOJ/Dijkstra.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/Dijkstra.test.cpp
- /verify/Test/AOJ/Dijkstra.test.cpp.html
title: Test/AOJ/Dijkstra.test.cpp
---
