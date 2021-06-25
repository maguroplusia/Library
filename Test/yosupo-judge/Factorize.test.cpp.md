---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../Math/Factorize.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#include\"../../Other/Template.cpp\"\n#include\"../../Math/Factorize.cpp\"\
    \n\nint main() {\n    int Q;\n    cin >> Q;\n    for(int tmp = 0;tmp < Q;tmp++)\
    \ {\n        long long N;\n        cin >> N;\n        vector<long long> ret =\
    \ factorize(N);\n        cout << (int)ret.size() << \" \";\n        for(const\
    \ auto& x:ret) cout << x << \" \";\n        cout << endl;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Test/yosupo-judge/Factorize.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/yosupo-judge/Factorize.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-judge/Factorize.test.cpp
- /verify/Test/yosupo-judge/Factorize.test.cpp.html
title: Test/yosupo-judge/Factorize.test.cpp
---
