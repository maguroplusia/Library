---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../Mathematics/ChineseRemainderTheorem.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/447\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#include\"../../Other/Template.cpp\"\n#include\"../../Mathematics/ChineseRemainderTheorem.cpp\"\
    \n\nint main() {\n    ll X1,Y1,X2,Y2,X3,Y3;\n    cin >> X1 >> Y1 >> X2 >> Y2 >>\
    \ X3 >> Y3;\n    pair<ll,ll> ret = CRT({X1,X2,X3},{Y1,Y2,Y3});\n    if(ret.second\
    \ == -1) cout << -1 << endl;\n    else cout << ret.first << endl;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Test/yukicoder/ChineseRemainderTheorem.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/yukicoder/ChineseRemainderTheorem.test.cpp
layout: document
redirect_from:
- /verify/Test/yukicoder/ChineseRemainderTheorem.test.cpp
- /verify/Test/yukicoder/ChineseRemainderTheorem.test.cpp.html
title: Test/yukicoder/ChineseRemainderTheorem.test.cpp
---
