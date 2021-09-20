---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-judge/SlidingWindowAggregation.test.cpp
    title: Test/yosupo-judge/SlidingWindowAggregation.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/SlidingWindowAggregation.cpp\"\ntemplate<class\
    \ T>\nclass SWAG {\n    class Node {\n    public:\n        T val,sum;\n      \
    \  Node(const T& val,const T& sum) : val(val),sum(sum) {}\n    };\n\n    std::stack<Node>\
    \ front_stack,back_stack;\n    function<T(T,T)> op;\n\npublic:\n    SWAG(const\
    \ function<T(T,T)> op) : op(op) {}\n\n    bool empty() {\n        return front_stack.empty()\
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
    \npublic:\n    SWAG(const function<T(T,T)> op) : op(op) {}\n\n    bool empty()\
    \ {\n        return front_stack.empty() && back_stack.empty();\n    }\n\n    T\
    \ fold_all() {\n        assert(!empty());\n        if(front_stack.empty()) {\n\
    \            return back_stack.top().sum;\n        }\n        else if(back_stack.empty())\
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
  timestamp: '2021-09-20 19:48:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-judge/SlidingWindowAggregation.test.cpp
documentation_of: DataStructure/SlidingWindowAggregation.cpp
layout: document
title: Sliding Window Aggregation (SWAG)
---

## 説明
[半群](https://ja.wikipedia.org/wiki/%E5%8D%8A%E7%BE%A4) $(S,\bullet)$ とその配列 $(a_0,a_1,\cdots,a_{N - 1})$ を扱う。

実装は、キューをスタック 2 個で表現する方法を用いている。

- `SWAG<S> swag(std::function<S(S,S)>)` : 空の配列を作成する。
- `bool swag.empty()` : 配列が空であるかを確かめる。時間計算量 $O(1)$
- `S swag.fold_all()` : $a_0 \bullet a_1 \bullet \cdots \bullet a_{N - 1}$ を求める。時間計算量 $O(1)$
- `S swag.push(S x)` : 配列に $x$ を追加する。時間計算量 $O(1)$
- `S swag.pop()` : 配列の先頭の要素を削除する。時間計算量 $O(1)\ \mathrm{amortized}$