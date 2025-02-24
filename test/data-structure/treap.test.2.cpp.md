---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/treap.hpp
    title: src/data-structure/treap.hpp
  - icon: ':heavy_check_mark:'
    path: test/template.hpp
    title: test/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"test/data-structure/treap.test.2.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\n#line 1 \"test/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst\
    \ ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a,\
    \ auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/treap.hpp\"\n// base:\
    \ c8a607\n// mm\u3092\u4F7F\u3046\u5834\u5408, \u8FFD\u8A18\u304C\u5FC5\u8981\n\
    // friend bool operator==(const mm& a, const mm& b) { return a.x == b.x; }\ntemplate<class\
    \ S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S, int), F (*composition)(F,\
    \ F), F (*id)()>\nstruct Treap {\n   private:\n   mt19937_64 mt;\n   uniform_int_distribution<uint64_t>\
    \ rand;\n   vector<S> value, acc;\n   vector<F> lazy;\n   vector<ll> priority;\n\
    \   vector<int> cnt, lch, rch;\n   vector<bool> lazy_rev;\n   int new_node(S v,\
    \ ll p) {\n      value.push_back(v);\n      acc.push_back(e());\n      lazy.push_back(id());\n\
    \      priority.push_back(p);\n      cnt.push_back(0);\n      lazy_rev.push_back(false);\n\
    \      lch.push_back(-1);\n      rch.push_back(-1);\n      return value.size()\
    \ - 1;\n   }\n\n   int root = -1;\n   int get_cnt(int t) { return t == -1 ? 0\
    \ : cnt[t]; }\n   S get_acc(int t) { return t == -1 ? e() : acc[t]; }\n   int\
    \ update(int t) {\n      if(t == -1) return t;\n      cnt[t] = 1 + get_cnt(lch[t])\
    \ + get_cnt(rch[t]);\n      acc[t] = op(get_acc(lch[t]), op(value[t], get_acc(rch[t])));\n\
    \      return t;\n   }\n   int push(int t) {\n      if(t == -1) return t;\n  \
    \    if(lazy_rev[t]) {\n         lazy_rev[t] = false;\n         swap(lch[t], rch[t]);\n\
    \         if(lch[t] != -1) lazy_rev[lch[t]] = !lazy_rev[lch[t]];\n         if(rch[t]\
    \ != -1) lazy_rev[rch[t]] = !lazy_rev[rch[t]];\n      }\n      if(lazy[t] != id())\
    \ {\n         if(lch[t] != -1) {\n            lazy[lch[t]] = composition(lazy[t],\
    \ lazy[lch[t]]);\n            acc[lch[t]] = mapping(lazy[t], acc[lch[t]], get_cnt(lch[t]));\n\
    \         }\n         if(rch[t] != -1) {\n            lazy[rch[t]] = composition(lazy[t],\
    \ lazy[rch[t]]);\n            acc[rch[t]] = mapping(lazy[t], acc[rch[t]], get_cnt(rch[t]));\n\
    \         }\n         value[t] = mapping(lazy[t], value[t], 1);\n         lazy[t]\
    \ = id();\n      }\n      return update(t);\n   }\n\n   int merge(int l, int r)\
    \ {\n      push(l);\n      push(r);\n      if(l == -1) return r;\n      if(r ==\
    \ -1) return l;\n      if(priority[l] > priority[r]) {\n         rch[l] = merge(rch[l],\
    \ r);\n         return update(l);\n      } else {\n         lch[r] = merge(l,\
    \ lch[r]);\n         return update(r);\n      }\n   }\n   pair<int, int> split(int\
    \ t, int k) {\n      if(t == -1) return make_pair(-1, -1);\n      push(t);\n \
    \     int implicit_key = get_cnt(lch[t]) + 1;\n      if(k < implicit_key) {\n\
    \         auto s = split(lch[t], k);\n         lch[t] = s.second;\n         return\
    \ make_pair(s.first, update(t));\n      } else {\n         auto s = split(rch[t],\
    \ k - implicit_key);\n         rch[t] = s.first;\n         return make_pair(update(t),\
    \ s.second);\n      }\n   }\n\n   int insert(int t, int k, int n) {\n      auto\
    \ s = split(t, k);\n      return merge(merge(s.first, n), s.second);\n   }\n\n\
    \   int apply(int t, int l, int r, F f) {\n      auto [t1, tt] = split(t, l);\n\
    \      auto [t2, t3] = split(tt, r - l);\n      lazy[t2] = composition(f, lazy[t2]);\n\
    \      acc[t2] = mapping(f, acc[t2], get_cnt(t2));\n      return merge(merge(t1,\
    \ t2), t3);\n   }  // 905a19 (Unordered)\n\n   int _erase(int t, int k) {\n  \
    \    auto [tt, t3] = split(t, k + 1);\n      auto [t1, t2] = split(tt, k);\n \
    \     return merge(t1, t3);\n   }  // 92ef20 (Common)\n\n   int erase_range(int\
    \ t, int l, int r) {\n      auto [tt, t3] = split(t, r);\n      auto [t1, t2]\
    \ = split(tt, l);\n      return merge(t1, t3);\n   }  // 77074b (Common)\n\n \
    \  pair<S, int> query(int t, int l, int r) {\n      auto [t1, tt] = split(t, l);\n\
    \      auto [t2, t3] = split(tt, r - l);\n      S ret = acc[t2];\n      return\
    \ make_pair(ret, merge(merge(t1, t2), t3));\n   }  //  fe8e6c (Common)\n\n   int\
    \ set(int t, int k, S v) {\n      auto [tt, t3] = split(t, k + 1);\n      auto\
    \ [t1, t2] = split(tt, k);\n      push(t2);\n      value[t2] = v;\n      update(t2);\n\
    \      return merge(merge(t1, t2), t3);\n   }  // 31b211 (Unordered)\n\n   int\
    \ _find(int t, S x, int offset, bool left = true) {\n      if(op(get_acc(t), x)\
    \ == x) {\n         return -1;\n      } else {\n         if(left) {\n        \
    \    if(lch[t] != -1 && op(acc[lch[t]], x) != x) {\n               return find(lch[t],\
    \ x, offset, left);\n            } else {\n               return (op(value[t],\
    \ x) != x) ? offset + get_cnt(lch[t])\n                                      \
    \       : find(rch[t], x, offset + get_cnt(lch[t]) + 1, left);\n            }\n\
    \         } else {\n            if(rch[t] != -1 && op(acc[rch[t]], x) != x) {\n\
    \               return find(rch[t], x, offset + get_cnt(lch[t]) + 1, left);\n\
    \            } else {\n               return (op(value[t], x) != x) ? offset +\
    \ get_cnt(lch[t]) : find(lch[t], x, offset, left);\n            }\n         }\n\
    \      }\n   }  // b0c65b (Common)\n\n   int reverse(int t, int l, int r) {\n\
    \      auto [t1, tt] = split(t, l);\n      auto [t2, t3] = split(tt, r - l);\n\
    \      lazy_rev[t2] = !lazy_rev[t2];\n      return merge(merge(t1, t2), t3);\n\
    \   }  // 3f67e3 (Unordered)\n\n   int rotate(int t, int l, int m, int r) {\n\
    \      t = reverse(t, l, r);\n      t = reverse(t, l, l + r - m);\n      return\
    \ reverse(t, l + r - m, r);\n   }  // a5a67c (Unordered)\n\n   int lower_search(int\
    \ t, S x) {\n      int ret = 0;\n      while(t != -1) {\n         if(x <= value[t])\
    \ {\n            t = lch[t];\n         } else {\n            ret += get_cnt(lch[t])\
    \ + 1;\n            t = rch[t];\n         }\n      }\n      return ret;\n   }\
    \  // 0ef7d9 (Ordered)\n\n   int upper_search(int t, S x) {\n      int ret = 0;\n\
    \      while(t != -1) {\n         if(x < value[t]) {\n            t = lch[t];\n\
    \         } else {\n            ret += get_cnt(lch[t]) + 1;\n            t = rch[t];\n\
    \         }\n      }\n      return ret;\n   }  // f91898 (Ordered)\n\n   public:\n\
    \   Treap() : Treap(0) {}\n   Treap(int N) : Treap(vector<S>(N, e())) {}\n   Treap(vector<S>\
    \ V) {\n      mt = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());\n\
    \      rand = uniform_int_distribution<uint64_t>(1, 1e18);\n      for(auto v :\
    \ V) { push_back(v); }\n   }\n\n   size_t size() { return size_t(get_cnt(root));\
    \ }  // f63788 (Common)\n\n   void insert(int ind, S x) { root = insert(root,\
    \ ind, new_node(x, rand(mt))); }  // dc467c (UnOrdered)\n\n   void push_back(S\
    \ x) { root = insert(root, int(size()), new_node(x, rand(mt))); }  // 7fa616 (Unordered)\n\
    \n   void ordered_insert(S x) {\n      int ind = lower_search(root, x);\n    \
    \  insert(ind, x);\n   }  // 539d77 (Ordered)\n\n   // Count elements in [lower,\
    \ upper)\n   int value_range_cnt(S lower, S upper) {\n      int L = lower_search(root,\
    \ lower);\n      int R = lower_search(root, upper);\n      return R - L;\n   }\
    \  // 2d4406 (Ordered)\n\n   // Sum of elements in [lower, upper)\n   S value_range_prod(S\
    \ lower, S upper) {\n      int L = lower_search(root, lower);\n      int R = lower_search(root,\
    \ upper);\n      if(L == R) return e();\n      return query(L, R);\n   }  // 27b9d4\
    \ (Ordered)\n\n   // erase element x cnt times (cnt = -1 -> erase all x)\n   int\
    \ erase_value(S x, int cnt = -1) {\n      int L = lower_search(root, x);\n   \
    \   int R = upper_search(root, x);\n      if(cnt != -1) chmin(R, L + cnt);\n \
    \     root = erase_range(root, L, R);\n      return R - L;\n   }  // 5c60fd (Ordered)\n\
    \n   int lower_search(S x) { return lower_search(root, x); }  // 9731cc (Ordered)\n\
    \n   int upper_search(S x) { return upper_search(root, x); }  // ac5aa0 (Ordered)\n\
    \n   void apply(int l, int r, F f) { root = apply(root, l, r, f); }  // 905a19\
    \ (Unordered)\n\n   void erase(int ind) { root = _erase(root, ind); }\n   // ff257f\
    \ (Common)\n\n   void erase(int l, int r) {\n      auto [tt, t3] = split(root,\
    \ r);\n      auto [t1, t2] = split(tt, l);\n      root = merge(t1, t3);\n   }\
    \  // f9ff4a (Common)\n\n   // l .. r-1 -> r-1 .. l\n   void reverse(int l, int\
    \ r) { root = reverse(root, l, r); }  // 40df7d (Unordered)\n\n   // l .. m-1,\
    \ m .. r-1 -> m .. r-1, l .. m-1\n   void rotate(int l, int m, int r) { root =\
    \ rotate(root, l, m, r); }  // e21b85 (Unordered)\n\n   void set(int k, S v) {\
    \ root = set(root, k, v); }  // 4ae943 (Unordered)\n\n   // min k \\in [l,r) such\
    \ that op(tr[k], x) != x\n   int find(int l, int r, S x, bool left = true) {\n\
    \      auto [t1, tt] = split(root, l);\n      auto [t2, t3] = split(tt, r - l);\n\
    \      int ret = _find(t2, x, l, left);\n      if(ret == -1) ret = r;\n      root\
    \ = merge(merge(t1, t2), t3);\n      return ret;\n   }  // 4f1699 (Common)\n\n\
    \   S prod(int l, int r) {\n      if(l == r) return S(0);\n      auto [t, rt]\
    \ = query(root, l, r);\n      root = rt;\n      return t;\n   }  // c46ac4 (Common)\n\
    \n   S operator[](int ind) {\n      auto [tt, t3] = split(root, ind + 1);\n  \
    \    auto [t1, t2] = split(tt, ind);\n      S ret = acc[t2];\n      root = merge(merge(t1,\
    \ t2), t3);\n      return ret;\n   }  // d2546e (Common)\n};\n#line 5 \"test/data-structure/treap.test.2.cpp\"\
    \n\nusing S = int;\nS op(S a, S b) { return min(a, b); }\nS e() { return INT_MAX;\
    \ }\n\nusing F = int;\nS mapping(F f, S x, int sz) { return f == INT_MAX ? x :\
    \ f; }\nF composition(F f, F g) { return f == INT_MAX ? g : f; }\nF id() { return\
    \ INT_MAX; }\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, Q;\n\
    \   cin >> N >> Q;\n   Treap<S, op, e, F, mapping, composition, id> treap;\n \
    \  string T;\n   cin >> T;\n   for(int i = 0; i < N; i++) {\n      if(T[i] ==\
    \ '1') treap.ordered_insert(i);\n   }\n\n   while(Q--) {\n      int c, k;\n  \
    \    cin >> c >> k;\n      if(c == 0) {\n         int count = treap.upper_search(k)\
    \ - treap.lower_search(k);\n         if(count == 0) treap.ordered_insert(k);\n\
    \      } else if(c == 1) {\n         int count = treap.upper_search(k) - treap.lower_search(k);\n\
    \         if(count == 1) treap.erase_value(k);\n      } else if(c == 2) {\n  \
    \       int count = treap.upper_search(k) - treap.lower_search(k);\n         cout\
    \ << count << '\\n';\n      } else if(c == 3) {\n         int cnt = treap.lower_search(k);\n\
    \         if(cnt == treap.size()) {\n            cout << -1 << \"\\n\";\n    \
    \     } else {\n            cout << treap[cnt] << \"\\n\";\n         }\n     \
    \ } else if(c == 4) {\n         int cnt = treap.upper_search(k);\n         if(cnt\
    \ == 0) {\n            cout << -1 << \"\\n\";\n         } else {\n           \
    \ cout << treap[cnt - 1] << \"\\n\";\n         }\n      }\n   }\n   return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    \n#include \"test/template.hpp\"\n#include \"src/data-structure/treap.hpp\"\n\n\
    using S = int;\nS op(S a, S b) { return min(a, b); }\nS e() { return INT_MAX;\
    \ }\n\nusing F = int;\nS mapping(F f, S x, int sz) { return f == INT_MAX ? x :\
    \ f; }\nF composition(F f, F g) { return f == INT_MAX ? g : f; }\nF id() { return\
    \ INT_MAX; }\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, Q;\n\
    \   cin >> N >> Q;\n   Treap<S, op, e, F, mapping, composition, id> treap;\n \
    \  string T;\n   cin >> T;\n   for(int i = 0; i < N; i++) {\n      if(T[i] ==\
    \ '1') treap.ordered_insert(i);\n   }\n\n   while(Q--) {\n      int c, k;\n  \
    \    cin >> c >> k;\n      if(c == 0) {\n         int count = treap.upper_search(k)\
    \ - treap.lower_search(k);\n         if(count == 0) treap.ordered_insert(k);\n\
    \      } else if(c == 1) {\n         int count = treap.upper_search(k) - treap.lower_search(k);\n\
    \         if(count == 1) treap.erase_value(k);\n      } else if(c == 2) {\n  \
    \       int count = treap.upper_search(k) - treap.lower_search(k);\n         cout\
    \ << count << '\\n';\n      } else if(c == 3) {\n         int cnt = treap.lower_search(k);\n\
    \         if(cnt == treap.size()) {\n            cout << -1 << \"\\n\";\n    \
    \     } else {\n            cout << treap[cnt] << \"\\n\";\n         }\n     \
    \ } else if(c == 4) {\n         int cnt = treap.upper_search(k);\n         if(cnt\
    \ == 0) {\n            cout << -1 << \"\\n\";\n         } else {\n           \
    \ cout << treap[cnt - 1] << \"\\n\";\n         }\n      }\n   }\n   return 0;\n\
    }"
  dependsOn:
  - test/template.hpp
  - src/data-structure/treap.hpp
  isVerificationFile: true
  path: test/data-structure/treap.test.2.cpp
  requiredBy: []
  timestamp: '2025-02-25 04:14:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/treap.test.2.cpp
layout: document
redirect_from:
- /verify/test/data-structure/treap.test.2.cpp
- /verify/test/data-structure/treap.test.2.cpp.html
title: test/data-structure/treap.test.2.cpp
---
