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
  bundledCode: "#line 1 \"Other/Mo.cpp\"\ntemplate<typename T>\nstruct Mo {\n    int\
    \ internal_size, packet_size;\n    std::vector<T> dat;\n    std::vector<int> query_left;\n\
    \    std::vector<int> query_right;\n    \n    Mo(int internal_size_, std::vector<T>\
    \ dat_): internal_size(internal_size_), dat(dat_) {\n        assert((int)dat.size()\
    \ == internal_size);\n        packet_size = std::max(1, int(internal_size / std::sqrt(internal_size)));\n\
    \    };\n\n    void add_query(int l, int r) {\n        query_left.emplace_back(l);\n\
    \        query_right.emplace_back(r);\n    }\n\n    template <typename AL, typename\
    \ AR, typename DL, typename DR, typename REM>\n    void build(const AL& add_left,\
    \ const AR& add_right, const DL& delete_left, const DR& delete_right, const REM&\
    \ out) {\n        std::vector<int> order(query_left.size());\n        std::iota(order.begin(),\
    \ order.end(), 0);\n        std::sort(order.begin(), order.end(), [&](int a,int\
    \ b) {\n            if(query_left[a] / packet_size != query_left[b] / packet_size)\
    \ return query_left[a] / packet_size < query_left[b] / packet_size;\n        \
    \    return query_right[a] < query_right[b];\n        });\n\n        int current_left\
    \ = 0;\n        int current_right = 0;\n        for(auto& x: order) {\n      \
    \      while(current_left > query_left[x]) add_left(--current_left);\n       \
    \     while(current_right < query_right[x]) add_right(current_right++);\n    \
    \        while(current_left < query_left[x]) delete_left(current_left++);\n  \
    \          while(current_right > query_right[x]) delete_right(--current_right);\n\
    \            out(x);\n        }\n    }\n};\n"
  code: "template<typename T>\nstruct Mo {\n    int internal_size, packet_size;\n\
    \    std::vector<T> dat;\n    std::vector<int> query_left;\n    std::vector<int>\
    \ query_right;\n    \n    Mo(int internal_size_, std::vector<T> dat_): internal_size(internal_size_),\
    \ dat(dat_) {\n        assert((int)dat.size() == internal_size);\n        packet_size\
    \ = std::max(1, int(internal_size / std::sqrt(internal_size)));\n    };\n\n  \
    \  void add_query(int l, int r) {\n        query_left.emplace_back(l);\n     \
    \   query_right.emplace_back(r);\n    }\n\n    template <typename AL, typename\
    \ AR, typename DL, typename DR, typename REM>\n    void build(const AL& add_left,\
    \ const AR& add_right, const DL& delete_left, const DR& delete_right, const REM&\
    \ out) {\n        std::vector<int> order(query_left.size());\n        std::iota(order.begin(),\
    \ order.end(), 0);\n        std::sort(order.begin(), order.end(), [&](int a,int\
    \ b) {\n            if(query_left[a] / packet_size != query_left[b] / packet_size)\
    \ return query_left[a] / packet_size < query_left[b] / packet_size;\n        \
    \    return query_right[a] < query_right[b];\n        });\n\n        int current_left\
    \ = 0;\n        int current_right = 0;\n        for(auto& x: order) {\n      \
    \      while(current_left > query_left[x]) add_left(--current_left);\n       \
    \     while(current_right < query_right[x]) add_right(current_right++);\n    \
    \        while(current_left < query_left[x]) delete_left(current_left++);\n  \
    \          while(current_right > query_right[x]) delete_right(--current_right);\n\
    \            out(x);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Other/Mo.cpp
  requiredBy: []
  timestamp: '2023-07-31 11:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Other/Mo.cpp
layout: document
redirect_from:
- /library/Other/Mo.cpp
- /library/Other/Mo.cpp.html
title: Other/Mo.cpp
---
