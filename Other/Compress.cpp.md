---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Other/Compress.cpp\"\ntemplate<typename T>\nstruct Compress\
    \ {\n    std::vector<T> values;\n\n    Compress() {}\n    Compress(const vector<T>&\
    \ vec): values(vec) {}\n\n    void add(const T& x) {\n        values.emplace_back(x);\n\
    \    }\n\n    void add(const vector<T>& vec) {\n        std::copy(vec.begin(),\
    \ vec.end(), std::back_inserter(values));\n    }\n\n    void build() {\n     \
    \   std::sort(values.begin(), values.end());\n        values.erase(std::unique(values.begin(),\
    \ values.end()), values.end());\n    }\n\n    int get(T x) {\n        return std::lower_bound(values.begin(),\
    \ values.end(), x) - values.begin();\n    }\n\n    const T& operator[](int x)\
    \ {\n        return values[x];\n    }\n\n    int size() {\n        return values.size();\n\
    \    }\n};\n"
  code: "template<typename T>\nstruct Compress {\n    std::vector<T> values;\n\n \
    \   Compress() {}\n    Compress(const vector<T>& vec): values(vec) {}\n\n    void\
    \ add(const T& x) {\n        values.emplace_back(x);\n    }\n\n    void add(const\
    \ vector<T>& vec) {\n        std::copy(vec.begin(), vec.end(), std::back_inserter(values));\n\
    \    }\n\n    void build() {\n        std::sort(values.begin(), values.end());\n\
    \        values.erase(std::unique(values.begin(), values.end()), values.end());\n\
    \    }\n\n    int get(T x) {\n        return std::lower_bound(values.begin(),\
    \ values.end(), x) - values.begin();\n    }\n\n    const T& operator[](int x)\
    \ {\n        return values[x];\n    }\n\n    int size() {\n        return values.size();\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Other/Compress.cpp
  requiredBy: []
  timestamp: '2021-12-15 22:45:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Other/Compress.cpp
layout: document
redirect_from:
- /library/Other/Compress.cpp
- /library/Other/Compress.cpp.html
title: Other/Compress.cpp
---
