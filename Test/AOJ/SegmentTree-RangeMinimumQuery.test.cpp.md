---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/SegmentTree.cpp
    title: Segment Tree
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Other/Template.cpp\"\
    \nconstexpr int Inf = 2000000030;\nconstexpr long long INF= 2000000000000000000;\n\
    \ntemplate<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return\
    \ true; } return false; }\ntemplate<typename T> inline bool chmin(T &a, T b) {\
    \ if (a > b) { a = b; return true; } return false; }\n#line 1 \"DataStructure/SegmentTree.cpp\"\
    \ntemplate<typename T>\nclass SegmentTree {\n    int internal_size, seg_size;\n\
    \    const T def;\n    std::vector<T> dat;\n    std::function<T(T, T)> operation;\n\
    \    std::function<T(T, T)> update;\n\npublic:\n    explicit SegmentTree(const\
    \ int size, const T& e, std::function<T(T, T)> operation, std::function<T(T, T)>\
    \ update): internal_size(size), def(e), operation(operation), update(update) {\n\
    \        for(seg_size = 1; seg_size < internal_size; seg_size *= 2);\n       \
    \ dat = std::vector<T>(2 * seg_size, def);\n    }\n\n    explicit SegmentTree(std::vector<T>\
    \ v, const T& e,std::function<T(T, T)> operation, std::function<T(T, T)> update):\
    \ internal_size(v.size()), def(e), operation(operation), update(update) {\n  \
    \      for(seg_size = 1; seg_size < internal_size; seg_size *= 2);\n        dat.resize(2\
    \ * seg_size, def);\n\n        for(int i = 0; i < seg_size;i++) dat[i + seg_size]\
    \ = v[i];\n        for(int i = seg_size - 1; i >= 1; i--) {\n            dat[i]\
    \ = operation(dat[i * 2], dat[i * 2 + 1]);\n        }\n    }\n\n    void set_val(int\
    \ i, const T& value) {\n        i += seg_size;\n        dat[i] = update(dat[i],\
    \ value);\n        while(i > 1) {\n            i >>= 1;\n            dat[i] =\
    \ operation(dat[i * 2], dat[i * 2 + 1]);\n        }\n    }\n\n    T fold(int l,int\
    \ r) {\n        l += seg_size;\n        r += seg_size;\n        T ret = def;\n\
    \        while(l < r) {\n            if(l & 1) ret = operation(ret,dat[l++]);\n\
    \            if(r & 1) ret = operation(dat[--r],ret);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return ret;\n    }\n\n    int max_right(int\
    \ l, std::function<bool(T)> f) {\n        if(l == internal_size) return internal_size;\n\
    \        l += seg_size;\n        T sum = def;\n        do {\n            while(!(l\
    \ & 1)) l >>= 1;\n            if(!f(operation(sum, data[l]))) {\n            \
    \    while(l < seg_size) {\n                    l <<= 1;\n                   \
    \ if(f(operation(sum, data[l]))) sum = operation(sum, data[l++]);\n          \
    \      }\n                return l - seg_size;\n            }\n        } while((l\
    \ & -1) != l);\n        return internal_size;\n    }\n\n    T operator[](int i)\
    \ {return dat[i + seg_size];}\n};\n#line 8 \"Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp\"\
    \n\nint main() {\n    int N,Q;\n    cin >> N >> Q;\n    SegmentTree<int> seg(N,numeric_limits<int>::max(),\n\
    \    [](int a,int b){return min(a,b);},\n    [](int a,int b){return b;});\n  \
    \  for(int i = 0;i < Q;i++) {\n        int t;\n        cin >> t;\n        if(t\
    \ == 0) {\n            int p,x;\n            cin >> p >> x;\n            seg.set_val(p,x);\n\
    \        }\n        else {\n            int s,t;\n            cin >> s >> t;\n\
    \            cout << seg.fold(s,t + 1) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../DataStructure/SegmentTree.cpp\"\n\nint main() {\n    int N,Q;\n\
    \    cin >> N >> Q;\n    SegmentTree<int> seg(N,numeric_limits<int>::max(),\n\
    \    [](int a,int b){return min(a,b);},\n    [](int a,int b){return b;});\n  \
    \  for(int i = 0;i < Q;i++) {\n        int t;\n        cin >> t;\n        if(t\
    \ == 0) {\n            int p,x;\n            cin >> p >> x;\n            seg.set_val(p,x);\n\
    \        }\n        else {\n            int s,t;\n            cin >> s >> t;\n\
    \            cout << seg.fold(s,t + 1) << endl;\n        }\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - DataStructure/SegmentTree.cpp
  isVerificationFile: true
  path: Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp
  requiredBy: []
  timestamp: '2021-11-21 13:25:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp
- /verify/Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp.html
title: Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp
---
