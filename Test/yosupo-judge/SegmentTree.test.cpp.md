---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../Datastructure/SegmentTree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include<bits/stdc++.h>\nusing namesapce std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../Datastructure/SegmentTree.cpp\"\n\nint main() {\n    int N,Q;\n\
    \    cin >> N >> Q;\n    SegmentTree<ll> seg(N,(ll)0,\n    [](ll a,ll b){return\
    \ a + b;},\n    [](ll a,ll b){return a + b;});\n    for(int i = 0;i < N;i++) {\n\
    \        ll A;\n        cin >> A;\n        seg.set(i,A);\n    }\n    seg.build();\n\
    \    for(int i = 0;i < Q;i++) {\n        int t;\n        cin >> t;\n        if(t\
    \ == 0) {\n            int p;\n            ll x;\n            cin >> p >> x;\n\
    \            seg.update(p,x);\n        }\n        else {\n            int l,r;\n\
    \            cin >> l >> r;\n            cout << seg.query(l,r) << endl;\n   \
    \     }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Test/yosupo-judge/SegmentTree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/yosupo-judge/SegmentTree.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-judge/SegmentTree.test.cpp
- /verify/Test/yosupo-judge/SegmentTree.test.cpp.html
title: Test/yosupo-judge/SegmentTree.test.cpp
---
