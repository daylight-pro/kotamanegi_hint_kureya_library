---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/ch_segtree.test.cpp
    title: test/data-structure/ch_segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30BB\u30B0\u6728\u3092\u914D\u5217\u306E\u5185\u5BB9\u3067\u521D\
      \u671F\u5316\u3059\u308B"
    links: []
  bundledCode: "#line 1 \"src/data-structure/ch_segtree.hpp\"\nclass ch_segtree {\n\
    \   private:\n   const ll inf = 1e18;\n   int n, n0;\n   vector<ll> max_v, smax_v,\
    \ max_c, min_v, smin_v, min_c, sum, len, ladd, lval;\n\n   void update_node_max(int\
    \ k, ll x) {\n      sum[k] += (x - max_v[k]) * max_c[k];\n\n      if(max_v[k]\
    \ == min_v[k]) {\n         max_v[k] = min_v[k] = x;\n      } else if(max_v[k]\
    \ == smin_v[k]) {\n         max_v[k] = smin_v[k] = x;\n      } else {\n      \
    \   max_v[k] = x;\n      }\n\n      if(lval[k] != inf && x < lval[k]) { lval[k]\
    \ = x; }\n   }\n   void update_node_min(int k, ll x) {\n      sum[k] += (x - min_v[k])\
    \ * min_c[k];\n\n      if(max_v[k] == min_v[k]) {\n         max_v[k] = min_v[k]\
    \ = x;\n      } else if(smax_v[k] == min_v[k]) {\n         min_v[k] = smax_v[k]\
    \ = x;\n      } else {\n         min_v[k] = x;\n      }\n\n      if(lval[k] !=\
    \ inf && lval[k] < x) { lval[k] = x; }\n   }\n\n   void push(int k) {\n      if(n0\
    \ - 1 <= k) return;\n\n      if(lval[k] != inf) {\n         updateall(2 * k +\
    \ 1, lval[k]);\n         updateall(2 * k + 2, lval[k]);\n         lval[k] = inf;\n\
    \         return;\n      }\n\n      if(ladd[k] != 0) {\n         addall(2 * k\
    \ + 1, ladd[k]);\n         addall(2 * k + 2, ladd[k]);\n         ladd[k] = 0;\n\
    \      }\n\n      if(max_v[k] < max_v[2 * k + 1]) { update_node_max(2 * k + 1,\
    \ max_v[k]); }\n      if(min_v[2 * k + 1] < min_v[k]) { update_node_min(2 * k\
    \ + 1, min_v[k]); }\n\n      if(max_v[k] < max_v[2 * k + 2]) { update_node_max(2\
    \ * k + 2, max_v[k]); }\n      if(min_v[2 * k + 2] < min_v[k]) { update_node_min(2\
    \ * k + 2, min_v[k]); }\n   }\n\n   void update(int k) {\n      sum[k] = sum[2\
    \ * k + 1] + sum[2 * k + 2];\n\n      if(max_v[2 * k + 1] < max_v[2 * k + 2])\
    \ {\n         max_v[k] = max_v[2 * k + 2];\n         max_c[k] = max_c[2 * k +\
    \ 2];\n         smax_v[k] = max(max_v[2 * k + 1], smax_v[2 * k + 2]);\n      }\
    \ else if(max_v[2 * k + 1] > max_v[2 * k + 2]) {\n         max_v[k] = max_v[2\
    \ * k + 1];\n         max_c[k] = max_c[2 * k + 1];\n         smax_v[k] = max(smax_v[2\
    \ * k + 1], max_v[2 * k + 2]);\n      } else {\n         max_v[k] = max_v[2 *\
    \ k + 1];\n         max_c[k] = max_c[2 * k + 1] + max_c[2 * k + 2];\n        \
    \ smax_v[k] = max(smax_v[2 * k + 1], smax_v[2 * k + 2]);\n      }\n\n      if(min_v[2\
    \ * k + 1] < min_v[2 * k + 2]) {\n         min_v[k] = min_v[2 * k + 1];\n    \
    \     min_c[k] = min_c[2 * k + 1];\n         smin_v[k] = min(smin_v[2 * k + 1],\
    \ min_v[2 * k + 2]);\n      } else if(min_v[2 * k + 1] > min_v[2 * k + 2]) {\n\
    \         min_v[k] = min_v[2 * k + 2];\n         min_c[k] = min_c[2 * k + 2];\n\
    \         smin_v[k] = min(min_v[2 * k + 1], smin_v[2 * k + 2]);\n      } else\
    \ {\n         min_v[k] = min_v[2 * k + 1];\n         min_c[k] = min_c[2 * k +\
    \ 1] + min_c[2 * k + 2];\n         smin_v[k] = min(smin_v[2 * k + 1], smin_v[2\
    \ * k + 2]);\n      }\n   }\n\n   void _update_min(ll x, int a, int b, int k,\
    \ int l, int r) {\n      if(b <= l || r <= a || max_v[k] <= x) { return; }\n \
    \     if(a <= l && r <= b && smax_v[k] < x) {\n         update_node_max(k, x);\n\
    \         return;\n      }\n\n      push(k);\n      _update_min(x, a, b, 2 * k\
    \ + 1, l, (l + r) / 2);\n      _update_min(x, a, b, 2 * k + 2, (l + r) / 2, r);\n\
    \      update(k);\n   }\n\n   void _update_max(ll x, int a, int b, int k, int\
    \ l, int r) {\n      if(b <= l || r <= a || x <= min_v[k]) { return; }\n     \
    \ if(a <= l && r <= b && x < smin_v[k]) {\n         update_node_min(k, x);\n \
    \        return;\n      }\n\n      push(k);\n      _update_max(x, a, b, 2 * k\
    \ + 1, l, (l + r) / 2);\n      _update_max(x, a, b, 2 * k + 2, (l + r) / 2, r);\n\
    \      update(k);\n   }\n\n   void addall(int k, ll x) {\n      max_v[k] += x;\n\
    \      if(smax_v[k] != -inf) smax_v[k] += x;\n      min_v[k] += x;\n      if(smin_v[k]\
    \ != inf) smin_v[k] += x;\n\n      sum[k] += len[k] * x;\n      if(lval[k] !=\
    \ inf) {\n         lval[k] += x;\n      } else {\n         ladd[k] += x;\n   \
    \   }\n   }\n\n   void updateall(int k, ll x) {\n      max_v[k] = x;\n      smax_v[k]\
    \ = -inf;\n      min_v[k] = x;\n      smin_v[k] = inf;\n      max_c[k] = min_c[k]\
    \ = len[k];\n\n      sum[k] = x * len[k];\n      lval[k] = x;\n      ladd[k] =\
    \ 0;\n   }\n\n   void _add_val(ll x, int a, int b, int k, int l, int r) {\n  \
    \    if(b <= l || r <= a) { return; }\n      if(a <= l && r <= b) {\n        \
    \ addall(k, x);\n         return;\n      }\n\n      push(k);\n      _add_val(x,\
    \ a, b, 2 * k + 1, l, (l + r) / 2);\n      _add_val(x, a, b, 2 * k + 2, (l + r)\
    \ / 2, r);\n      update(k);\n   }\n\n   void _update_val(ll x, int a, int b,\
    \ int k, int l, int r) {\n      if(b <= l || r <= a) { return; }\n      if(a <=\
    \ l && r <= b) {\n         updateall(k, x);\n         return;\n      }\n\n   \
    \   push(k);\n      _update_val(x, a, b, 2 * k + 1, l, (l + r) / 2);\n      _update_val(x,\
    \ a, b, 2 * k + 2, (l + r) / 2, r);\n      update(k);\n   }\n\n   ll _query_max(int\
    \ a, int b, int k, int l, int r) {\n      if(b <= l || r <= a) { return -inf;\
    \ }\n      if(a <= l && r <= b) { return max_v[k]; }\n      push(k);\n      ll\
    \ lv = _query_max(a, b, 2 * k + 1, l, (l + r) / 2);\n      ll rv = _query_max(a,\
    \ b, 2 * k + 2, (l + r) / 2, r);\n      return max(lv, rv);\n   }\n\n   ll _query_min(int\
    \ a, int b, int k, int l, int r) {\n      if(b <= l || r <= a) { return inf; }\n\
    \      if(a <= l && r <= b) { return min_v[k]; }\n      push(k);\n      ll lv\
    \ = _query_min(a, b, 2 * k + 1, l, (l + r) / 2);\n      ll rv = _query_min(a,\
    \ b, 2 * k + 2, (l + r) / 2, r);\n      return min(lv, rv);\n   }\n\n   ll _query_sum(int\
    \ a, int b, int k, int l, int r) {\n      if(b <= l || r <= a) { return 0; }\n\
    \      if(a <= l && r <= b) { return sum[k]; }\n      push(k);\n      ll lv =\
    \ _query_sum(a, b, 2 * k + 1, l, (l + r) / 2);\n      ll rv = _query_sum(a, b,\
    \ 2 * k + 2, (l + r) / 2, r);\n      return lv + rv;\n   }\n\n   public:\n   ///\
    \ @brief \u30BB\u30B0\u6728\u3092\u914D\u5217\u306E\u5185\u5BB9\u3067\u521D\u671F\
    \u5316\u3059\u308B\n   /// @param a \u30BB\u30B0\u6728\u306E\u521D\u671F\u5024\
    \n   ch_segtree(const vector<ll>& a) {\n      n = a.size();\n      n0 = 1;\n \
    \     while(n0 < n) n0 <<= 1;\n\n      max_v.resize(n0 * 2);\n      smax_v.resize(n0\
    \ * 2);\n      max_c.resize(n0 * 2);\n      min_v.resize(n0 * 2);\n      smin_v.resize(n0\
    \ * 2);\n      min_c.resize(n0 * 2);\n      sum.resize(n0 * 2);\n      len.resize(n0\
    \ * 2);\n      ladd.resize(n0 * 2);\n      lval.resize(n0 * 2);\n\n      for(int\
    \ i = 0; i < 2 * n0; ++i) ladd[i] = 0, lval[i] = inf;\n      len[0] = n0;\n  \
    \    for(int i = 0; i < n0 - 1; ++i) len[2 * i + 1] = len[2 * i + 2] = (len[i]\
    \ >> 1);\n\n      for(int i = 0; i < n; ++i) {\n         max_v[n0 - 1 + i] = min_v[n0\
    \ - 1 + i] = sum[n0 - 1 + i] = a[i];\n         smax_v[n0 - 1 + i] = -inf;\n  \
    \       smin_v[n0 - 1 + i] = inf;\n         max_c[n0 - 1 + i] = min_c[n0 - 1 +\
    \ i] = 1;\n      }\n\n      for(int i = n; i < n0; ++i) {\n         max_v[n0 -\
    \ 1 + i] = smax_v[n0 - 1 + i] = -inf;\n         min_v[n0 - 1 + i] = smin_v[n0\
    \ - 1 + i] = inf;\n         max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 0;\n     \
    \ }\n      for(int i = n0 - 2; i >= 0; i--) { update(i); }\n   }\n\n   /// @brief\
    \ p\u756A\u76EE\u306E\u8981\u7D20\u306B\u30A2\u30AF\u30BB\u30B9\n   /// @param\
    \ p \u30A2\u30AF\u30BB\u30B9\u3059\u308B\u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9(0-indexed)\n   /// @return p\u756A\u76EE\u306E\u8981\u7D20\n   ll\
    \ get(int p) { return prod_sum(p, p + 1); }\n\n   /// @brief p\u756A\u76EE\u306E\
    \u8981\u7D20\u3092x\u306B\u5909\u66F4\n   /// @param p \u5909\u66F4\u3059\u308B\
    \u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9(0-indexed)\n   /// @param\
    \ x \u5909\u66F4\u5F8C\u306E\u5024\n   void set(int p, ll x) { apply_update(p,\
    \ p + 1, x); }\n\n   /// @brief \u533A\u9593[a,b)\u3067v[i]\u2190min(v[i],x)\n\
    \   /// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n   /// @param b \u533A\
    \u9593\u306E\u53F3\u7AEF(exclusive)\n   /// @param x min\u3092\u3068\u308B\u5024\
    \n   void apply_chmin(int a, int b, ll x) { _update_min(x, a, b, 0, 0, n0); }\n\
    \n   /// @brief \u533A\u9593[a,b)\u3067v[i]\u2190max(v[i],x)\n   /// @param a\
    \ \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n   /// @param b \u533A\u9593\u306E\
    \u53F3\u7AEF(exclusive)\n   /// @param x max\u3092\u3068\u308B\u5024\n   void\
    \ apply_chmax(int a, int b, ll x) { _update_max(x, a, b, 0, 0, n0); }\n\n   ///\
    \ @brief \u533A\u9593[a,b)\u3067v[i]\u2190v[i]+x\n   /// @param a \u533A\u9593\
    \u306E\u5DE6\u7AEF(inclusive)\n   /// @param b \u533A\u9593\u306E\u53F3\u7AEF\
    (exclusive)\n   /// @param x \u52A0\u7B97\u3059\u308B\u5024\n   void apply_add(int\
    \ a, int b, ll x) { _add_val(x, a, b, 0, 0, n0); }\n\n   /// @brief \u533A\u9593\
    [a,b)\u3067v[i]\u2190x\n   /// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\
    \   /// @param b \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n   /// @param x \u66F4\
    \u65B0\u3059\u308B\u5024\n   void apply_update(int a, int b, ll x) { _update_val(x,\
    \ a, b, 0, 0, n0); }\n\n   /// @brief \u533A\u9593[a,b)\u306E\u6700\u5927\u5024\
    \u3092\u53D6\u5F97\n   /// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\
    \   /// @param b \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n   /// @return \u533A\
    \u9593[a,b)\u306E\u6700\u5927\u5024\n   ll prod_max(int a, int b) { return _query_max(a,\
    \ b, 0, 0, n0); }\n\n   /// @brief \u533A\u9593[a,b)\u306E\u6700\u5C0F\u5024\u3092\
    \u53D6\u5F97\n   /// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n   ///\
    \ @param b \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n   /// @return \u533A\u9593\
    [a,b)\u306E\u6700\u5C0F\u5024\n   ll prod_min(int a, int b) { return _query_min(a,\
    \ b, 0, 0, n0); }\n\n   /// @brief \u533A\u9593[a,b)\u306E\u548C\u3092\u53D6\u5F97\
    \n   /// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n   /// @param b \u533A\
    \u9593\u306E\u53F3\u7AEF(exclusive)\n   /// @return \u533A\u9593[a,b)\u306E\u548C\
    \n   ll prod_sum(int a, int b) { return _query_sum(a, b, 0, 0, n0); }\n};\n"
  code: "class ch_segtree {\n   private:\n   const ll inf = 1e18;\n   int n, n0;\n\
    \   vector<ll> max_v, smax_v, max_c, min_v, smin_v, min_c, sum, len, ladd, lval;\n\
    \n   void update_node_max(int k, ll x) {\n      sum[k] += (x - max_v[k]) * max_c[k];\n\
    \n      if(max_v[k] == min_v[k]) {\n         max_v[k] = min_v[k] = x;\n      }\
    \ else if(max_v[k] == smin_v[k]) {\n         max_v[k] = smin_v[k] = x;\n     \
    \ } else {\n         max_v[k] = x;\n      }\n\n      if(lval[k] != inf && x <\
    \ lval[k]) { lval[k] = x; }\n   }\n   void update_node_min(int k, ll x) {\n  \
    \    sum[k] += (x - min_v[k]) * min_c[k];\n\n      if(max_v[k] == min_v[k]) {\n\
    \         max_v[k] = min_v[k] = x;\n      } else if(smax_v[k] == min_v[k]) {\n\
    \         min_v[k] = smax_v[k] = x;\n      } else {\n         min_v[k] = x;\n\
    \      }\n\n      if(lval[k] != inf && lval[k] < x) { lval[k] = x; }\n   }\n\n\
    \   void push(int k) {\n      if(n0 - 1 <= k) return;\n\n      if(lval[k] != inf)\
    \ {\n         updateall(2 * k + 1, lval[k]);\n         updateall(2 * k + 2, lval[k]);\n\
    \         lval[k] = inf;\n         return;\n      }\n\n      if(ladd[k] != 0)\
    \ {\n         addall(2 * k + 1, ladd[k]);\n         addall(2 * k + 2, ladd[k]);\n\
    \         ladd[k] = 0;\n      }\n\n      if(max_v[k] < max_v[2 * k + 1]) { update_node_max(2\
    \ * k + 1, max_v[k]); }\n      if(min_v[2 * k + 1] < min_v[k]) { update_node_min(2\
    \ * k + 1, min_v[k]); }\n\n      if(max_v[k] < max_v[2 * k + 2]) { update_node_max(2\
    \ * k + 2, max_v[k]); }\n      if(min_v[2 * k + 2] < min_v[k]) { update_node_min(2\
    \ * k + 2, min_v[k]); }\n   }\n\n   void update(int k) {\n      sum[k] = sum[2\
    \ * k + 1] + sum[2 * k + 2];\n\n      if(max_v[2 * k + 1] < max_v[2 * k + 2])\
    \ {\n         max_v[k] = max_v[2 * k + 2];\n         max_c[k] = max_c[2 * k +\
    \ 2];\n         smax_v[k] = max(max_v[2 * k + 1], smax_v[2 * k + 2]);\n      }\
    \ else if(max_v[2 * k + 1] > max_v[2 * k + 2]) {\n         max_v[k] = max_v[2\
    \ * k + 1];\n         max_c[k] = max_c[2 * k + 1];\n         smax_v[k] = max(smax_v[2\
    \ * k + 1], max_v[2 * k + 2]);\n      } else {\n         max_v[k] = max_v[2 *\
    \ k + 1];\n         max_c[k] = max_c[2 * k + 1] + max_c[2 * k + 2];\n        \
    \ smax_v[k] = max(smax_v[2 * k + 1], smax_v[2 * k + 2]);\n      }\n\n      if(min_v[2\
    \ * k + 1] < min_v[2 * k + 2]) {\n         min_v[k] = min_v[2 * k + 1];\n    \
    \     min_c[k] = min_c[2 * k + 1];\n         smin_v[k] = min(smin_v[2 * k + 1],\
    \ min_v[2 * k + 2]);\n      } else if(min_v[2 * k + 1] > min_v[2 * k + 2]) {\n\
    \         min_v[k] = min_v[2 * k + 2];\n         min_c[k] = min_c[2 * k + 2];\n\
    \         smin_v[k] = min(min_v[2 * k + 1], smin_v[2 * k + 2]);\n      } else\
    \ {\n         min_v[k] = min_v[2 * k + 1];\n         min_c[k] = min_c[2 * k +\
    \ 1] + min_c[2 * k + 2];\n         smin_v[k] = min(smin_v[2 * k + 1], smin_v[2\
    \ * k + 2]);\n      }\n   }\n\n   void _update_min(ll x, int a, int b, int k,\
    \ int l, int r) {\n      if(b <= l || r <= a || max_v[k] <= x) { return; }\n \
    \     if(a <= l && r <= b && smax_v[k] < x) {\n         update_node_max(k, x);\n\
    \         return;\n      }\n\n      push(k);\n      _update_min(x, a, b, 2 * k\
    \ + 1, l, (l + r) / 2);\n      _update_min(x, a, b, 2 * k + 2, (l + r) / 2, r);\n\
    \      update(k);\n   }\n\n   void _update_max(ll x, int a, int b, int k, int\
    \ l, int r) {\n      if(b <= l || r <= a || x <= min_v[k]) { return; }\n     \
    \ if(a <= l && r <= b && x < smin_v[k]) {\n         update_node_min(k, x);\n \
    \        return;\n      }\n\n      push(k);\n      _update_max(x, a, b, 2 * k\
    \ + 1, l, (l + r) / 2);\n      _update_max(x, a, b, 2 * k + 2, (l + r) / 2, r);\n\
    \      update(k);\n   }\n\n   void addall(int k, ll x) {\n      max_v[k] += x;\n\
    \      if(smax_v[k] != -inf) smax_v[k] += x;\n      min_v[k] += x;\n      if(smin_v[k]\
    \ != inf) smin_v[k] += x;\n\n      sum[k] += len[k] * x;\n      if(lval[k] !=\
    \ inf) {\n         lval[k] += x;\n      } else {\n         ladd[k] += x;\n   \
    \   }\n   }\n\n   void updateall(int k, ll x) {\n      max_v[k] = x;\n      smax_v[k]\
    \ = -inf;\n      min_v[k] = x;\n      smin_v[k] = inf;\n      max_c[k] = min_c[k]\
    \ = len[k];\n\n      sum[k] = x * len[k];\n      lval[k] = x;\n      ladd[k] =\
    \ 0;\n   }\n\n   void _add_val(ll x, int a, int b, int k, int l, int r) {\n  \
    \    if(b <= l || r <= a) { return; }\n      if(a <= l && r <= b) {\n        \
    \ addall(k, x);\n         return;\n      }\n\n      push(k);\n      _add_val(x,\
    \ a, b, 2 * k + 1, l, (l + r) / 2);\n      _add_val(x, a, b, 2 * k + 2, (l + r)\
    \ / 2, r);\n      update(k);\n   }\n\n   void _update_val(ll x, int a, int b,\
    \ int k, int l, int r) {\n      if(b <= l || r <= a) { return; }\n      if(a <=\
    \ l && r <= b) {\n         updateall(k, x);\n         return;\n      }\n\n   \
    \   push(k);\n      _update_val(x, a, b, 2 * k + 1, l, (l + r) / 2);\n      _update_val(x,\
    \ a, b, 2 * k + 2, (l + r) / 2, r);\n      update(k);\n   }\n\n   ll _query_max(int\
    \ a, int b, int k, int l, int r) {\n      if(b <= l || r <= a) { return -inf;\
    \ }\n      if(a <= l && r <= b) { return max_v[k]; }\n      push(k);\n      ll\
    \ lv = _query_max(a, b, 2 * k + 1, l, (l + r) / 2);\n      ll rv = _query_max(a,\
    \ b, 2 * k + 2, (l + r) / 2, r);\n      return max(lv, rv);\n   }\n\n   ll _query_min(int\
    \ a, int b, int k, int l, int r) {\n      if(b <= l || r <= a) { return inf; }\n\
    \      if(a <= l && r <= b) { return min_v[k]; }\n      push(k);\n      ll lv\
    \ = _query_min(a, b, 2 * k + 1, l, (l + r) / 2);\n      ll rv = _query_min(a,\
    \ b, 2 * k + 2, (l + r) / 2, r);\n      return min(lv, rv);\n   }\n\n   ll _query_sum(int\
    \ a, int b, int k, int l, int r) {\n      if(b <= l || r <= a) { return 0; }\n\
    \      if(a <= l && r <= b) { return sum[k]; }\n      push(k);\n      ll lv =\
    \ _query_sum(a, b, 2 * k + 1, l, (l + r) / 2);\n      ll rv = _query_sum(a, b,\
    \ 2 * k + 2, (l + r) / 2, r);\n      return lv + rv;\n   }\n\n   public:\n   ///\
    \ @brief \u30BB\u30B0\u6728\u3092\u914D\u5217\u306E\u5185\u5BB9\u3067\u521D\u671F\
    \u5316\u3059\u308B\n   /// @param a \u30BB\u30B0\u6728\u306E\u521D\u671F\u5024\
    \n   ch_segtree(const vector<ll>& a) {\n      n = a.size();\n      n0 = 1;\n \
    \     while(n0 < n) n0 <<= 1;\n\n      max_v.resize(n0 * 2);\n      smax_v.resize(n0\
    \ * 2);\n      max_c.resize(n0 * 2);\n      min_v.resize(n0 * 2);\n      smin_v.resize(n0\
    \ * 2);\n      min_c.resize(n0 * 2);\n      sum.resize(n0 * 2);\n      len.resize(n0\
    \ * 2);\n      ladd.resize(n0 * 2);\n      lval.resize(n0 * 2);\n\n      for(int\
    \ i = 0; i < 2 * n0; ++i) ladd[i] = 0, lval[i] = inf;\n      len[0] = n0;\n  \
    \    for(int i = 0; i < n0 - 1; ++i) len[2 * i + 1] = len[2 * i + 2] = (len[i]\
    \ >> 1);\n\n      for(int i = 0; i < n; ++i) {\n         max_v[n0 - 1 + i] = min_v[n0\
    \ - 1 + i] = sum[n0 - 1 + i] = a[i];\n         smax_v[n0 - 1 + i] = -inf;\n  \
    \       smin_v[n0 - 1 + i] = inf;\n         max_c[n0 - 1 + i] = min_c[n0 - 1 +\
    \ i] = 1;\n      }\n\n      for(int i = n; i < n0; ++i) {\n         max_v[n0 -\
    \ 1 + i] = smax_v[n0 - 1 + i] = -inf;\n         min_v[n0 - 1 + i] = smin_v[n0\
    \ - 1 + i] = inf;\n         max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 0;\n     \
    \ }\n      for(int i = n0 - 2; i >= 0; i--) { update(i); }\n   }\n\n   /// @brief\
    \ p\u756A\u76EE\u306E\u8981\u7D20\u306B\u30A2\u30AF\u30BB\u30B9\n   /// @param\
    \ p \u30A2\u30AF\u30BB\u30B9\u3059\u308B\u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9(0-indexed)\n   /// @return p\u756A\u76EE\u306E\u8981\u7D20\n   ll\
    \ get(int p) { return prod_sum(p, p + 1); }\n\n   /// @brief p\u756A\u76EE\u306E\
    \u8981\u7D20\u3092x\u306B\u5909\u66F4\n   /// @param p \u5909\u66F4\u3059\u308B\
    \u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9(0-indexed)\n   /// @param\
    \ x \u5909\u66F4\u5F8C\u306E\u5024\n   void set(int p, ll x) { apply_update(p,\
    \ p + 1, x); }\n\n   /// @brief \u533A\u9593[a,b)\u3067v[i]\u2190min(v[i],x)\n\
    \   /// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n   /// @param b \u533A\
    \u9593\u306E\u53F3\u7AEF(exclusive)\n   /// @param x min\u3092\u3068\u308B\u5024\
    \n   void apply_chmin(int a, int b, ll x) { _update_min(x, a, b, 0, 0, n0); }\n\
    \n   /// @brief \u533A\u9593[a,b)\u3067v[i]\u2190max(v[i],x)\n   /// @param a\
    \ \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n   /// @param b \u533A\u9593\u306E\
    \u53F3\u7AEF(exclusive)\n   /// @param x max\u3092\u3068\u308B\u5024\n   void\
    \ apply_chmax(int a, int b, ll x) { _update_max(x, a, b, 0, 0, n0); }\n\n   ///\
    \ @brief \u533A\u9593[a,b)\u3067v[i]\u2190v[i]+x\n   /// @param a \u533A\u9593\
    \u306E\u5DE6\u7AEF(inclusive)\n   /// @param b \u533A\u9593\u306E\u53F3\u7AEF\
    (exclusive)\n   /// @param x \u52A0\u7B97\u3059\u308B\u5024\n   void apply_add(int\
    \ a, int b, ll x) { _add_val(x, a, b, 0, 0, n0); }\n\n   /// @brief \u533A\u9593\
    [a,b)\u3067v[i]\u2190x\n   /// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\
    \   /// @param b \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n   /// @param x \u66F4\
    \u65B0\u3059\u308B\u5024\n   void apply_update(int a, int b, ll x) { _update_val(x,\
    \ a, b, 0, 0, n0); }\n\n   /// @brief \u533A\u9593[a,b)\u306E\u6700\u5927\u5024\
    \u3092\u53D6\u5F97\n   /// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n\
    \   /// @param b \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n   /// @return \u533A\
    \u9593[a,b)\u306E\u6700\u5927\u5024\n   ll prod_max(int a, int b) { return _query_max(a,\
    \ b, 0, 0, n0); }\n\n   /// @brief \u533A\u9593[a,b)\u306E\u6700\u5C0F\u5024\u3092\
    \u53D6\u5F97\n   /// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n   ///\
    \ @param b \u533A\u9593\u306E\u53F3\u7AEF(exclusive)\n   /// @return \u533A\u9593\
    [a,b)\u306E\u6700\u5C0F\u5024\n   ll prod_min(int a, int b) { return _query_min(a,\
    \ b, 0, 0, n0); }\n\n   /// @brief \u533A\u9593[a,b)\u306E\u548C\u3092\u53D6\u5F97\
    \n   /// @param a \u533A\u9593\u306E\u5DE6\u7AEF(inclusive)\n   /// @param b \u533A\
    \u9593\u306E\u53F3\u7AEF(exclusive)\n   /// @return \u533A\u9593[a,b)\u306E\u548C\
    \n   ll prod_sum(int a, int b) { return _query_sum(a, b, 0, 0, n0); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/ch_segtree.hpp
  requiredBy: []
  timestamp: '2024-12-18 22:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/ch_segtree.test.cpp
documentation_of: src/data-structure/ch_segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/ch_segtree.hpp
- /library/src/data-structure/ch_segtree.hpp.html
title: "\u30BB\u30B0\u6728\u3092\u914D\u5217\u306E\u5185\u5BB9\u3067\u521D\u671F\u5316\
  \u3059\u308B"
---
