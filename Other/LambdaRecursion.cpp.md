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
  bundledCode: "#line 1 \"Other/LambdaRecursion.cpp\"\ntemplate<typename F>\nstruct\
    \ FixPoint : F {\n    template<typename G>\n    FixPoint(G&& g) : F{std::forward<G>(g)}\
    \ {}\n\n    template<typename... Args>\n    decltype(auto) operator()(Args&&...\
    \ args) const {\n        return F::operator()(*this,std::forward<Args>(args)...);\n\
    \    }\n};\n\n#if defined(__cpp_deduction_guides)\ntemplate<typename F>\nFixPoint(F&&)\
    \ -> FixPoint<std::decay_t<F>>;\n#endif\n\ntemplate<typename F>\ninline FixPoint<std::decay_t<F>>\
    \ fix(F&& f) {\n    return std::forward<std::decay_t<F>>(f);\n}\n"
  code: "template<typename F>\nstruct FixPoint : F {\n    template<typename G>\n \
    \   FixPoint(G&& g) : F{std::forward<G>(g)} {}\n\n    template<typename... Args>\n\
    \    decltype(auto) operator()(Args&&... args) const {\n        return F::operator()(*this,std::forward<Args>(args)...);\n\
    \    }\n};\n\n#if defined(__cpp_deduction_guides)\ntemplate<typename F>\nFixPoint(F&&)\
    \ -> FixPoint<std::decay_t<F>>;\n#endif\n\ntemplate<typename F>\ninline FixPoint<std::decay_t<F>>\
    \ fix(F&& f) {\n    return std::forward<std::decay_t<F>>(f);\n}"
  dependsOn: []
  isVerificationFile: false
  path: Other/LambdaRecursion.cpp
  requiredBy: []
  timestamp: '2021-11-16 21:56:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Other/LambdaRecursion.cpp
layout: document
redirect_from:
- /library/Other/LambdaRecursion.cpp
- /library/Other/LambdaRecursion.cpp.html
title: Other/LambdaRecursion.cpp
---
