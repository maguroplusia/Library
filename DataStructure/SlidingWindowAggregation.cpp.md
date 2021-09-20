---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/yosupo-judge/SlidingWindowAggregation.test.cpp
    title: Test/yosupo-judge/SlidingWindowAggregation.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/SlidingWindowAggregation.cpp\"\ntemplate<class\
    \ T>\nclass SWAG {\n    class Node {\n    public:\n        T val,sum;\n      \
    \  Node(const T& val,const T& sum) : val(val),sum(sum) {}\n    };\n\n    std::stack<Node>\
    \ front_stack,back_stack;\n    function<T(T,T)> op;\n\npublic:\n    SWAG(const\
    \ auto op) : op(op) {}\n\n    bool empty() {\n        return front_stack.empty()\
    \ && back_stack.empty();\n    }\n\n    T fold_all() {\n        assert(!empty());\n\
    \        if(front_stack.empty()) {\n            return back_stack.top().sum;\n\
    \        }\n        else if(back_stack.empty()) {\n            return front_stack.top().sum;\n\
    \        }\n        else {\n            return op(front_stack.top().sum,back_stack.top().sum);\n\
    \        }\n    }\n\n    void push(T x) {\n        if(back_stack.empty()) back_stack.emplace(x,x);\n\
    \        else back_stack.emplace(x,op(back_stack.top().sum,x));\n    }\n\n   \
    \ void pop() {\n        assert(!empty());\n        if(front_stack.empty()) {\n\
    \            front_stack.emplace(back_stack.top().val,back_stack.top().val);\n\
    \            back_stack.pop();\n            while(!back_stack.empty()) {\n   \
    \             T tmp{op(back_stack.top().val,front_stack.top().sum)};\n       \
    \         front_stack.emplace(back_stack.top().val,tmp);\n                back_stack.pop();\n\
    \            }\n        }\n        front_stack.pop();\n    }\n};\n"
  code: "template<class T>\nclass SWAG {\n    class Node {\n    public:\n        T\
    \ val,sum;\n        Node(const T& val,const T& sum) : val(val),sum(sum) {}\n \
    \   };\n\n    std::stack<Node> front_stack,back_stack;\n    function<T(T,T)> op;\n\
    \npublic:\n    SWAG(const auto op) : op(op) {}\n\n    bool empty() {\n       \
    \ return front_stack.empty() && back_stack.empty();\n    }\n\n    T fold_all()\
    \ {\n        assert(!empty());\n        if(front_stack.empty()) {\n          \
    \  return back_stack.top().sum;\n        }\n        else if(back_stack.empty())\
    \ {\n            return front_stack.top().sum;\n        }\n        else {\n  \
    \          return op(front_stack.top().sum,back_stack.top().sum);\n        }\n\
    \    }\n\n    void push(T x) {\n        if(back_stack.empty()) back_stack.emplace(x,x);\n\
    \        else back_stack.emplace(x,op(back_stack.top().sum,x));\n    }\n\n   \
    \ void pop() {\n        assert(!empty());\n        if(front_stack.empty()) {\n\
    \            front_stack.emplace(back_stack.top().val,back_stack.top().val);\n\
    \            back_stack.pop();\n            while(!back_stack.empty()) {\n   \
    \             T tmp{op(back_stack.top().val,front_stack.top().sum)};\n       \
    \         front_stack.emplace(back_stack.top().val,tmp);\n                back_stack.pop();\n\
    \            }\n        }\n        front_stack.pop();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SlidingWindowAggregation.cpp
  requiredBy: []
  timestamp: '2021-09-20 19:22:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/yosupo-judge/SlidingWindowAggregation.test.cpp
documentation_of: DataStructure/SlidingWindowAggregation.cpp
layout: document
redirect_from:
- /library/DataStructure/SlidingWindowAggregation.cpp
- /library/DataStructure/SlidingWindowAggregation.cpp.html
title: DataStructure/SlidingWindowAggregation.cpp
---
