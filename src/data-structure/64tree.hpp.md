---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/64tree.hpp\"\nstruct WordsizeTree{\n\
    \   using Word = unsigned long long;\n   static constexpr int W = 64;\n   int\
    \ N;\n   vector<vector<Word>> A;\n   static int highBit(Word x){\n      if(x ==\
    \ 0) return 0;\n      return W-1 - __builtin_clzll(x);\n   }\n   static int lowBit(Word\
    \ x){\n      if(x == 0) return W;\n      return __builtin_ctzll(x);\n   }\n  \
    \ WordsizeTree(int length){\n      N = length;\n      int n = length;\n      do\
    \ {\n         vector<Word> a(n/W+1,0);\n         A.emplace_back(move(a));\n  \
    \       n /= W;\n      } while(n);\n   }\n   WordsizeTree(const string& binStr\
    \ = \"\"){\n      N = binStr.size();\n      int n = N;\n      {\n         vector<Word>\
    \ a(n/W+1);\n         for(int i=0; i<n; i++) if(binStr[i] == '1'){\n         \
    \   a[i/W] |= (Word)1 << (i%W);\n         }\n         A.emplace_back(move(a));\n\
    \         n /= W;\n      }\n      while(n){\n         vector<Word> a(n/W+1,0);\n\
    \         for(int i=0; i<=n; i++){\n            if(A.back()[i]) a[i/W] |= (Word)1\
    \ << (i%W);\n         }\n         A.emplace_back(move(a));\n         n /= W;\n\
    \      }\n   }\n   void insert(int x){\n      for(auto& a : A){\n         a[x/W]\
    \ |= (Word)1 << (x % W);\n         x /= W;\n      }\n   }\n   void erase(int x){\n\
    \      for(auto& a : A){\n         a[x/W] &= ~((Word)1 << (x % W));\n        \
    \ if(a[x/W]) return;\n         x /= W;\n      }\n   }\n   int count(int x) const\
    \ {\n      return (int)((A[0][x/W] >> (x%W)) & 1);\n   }\n   int noLessThan(int\
    \ x) const {\n      if(x < 0) x = 0;\n      if(N <= x) return N;\n      int d\
    \ = 0, i = x;\n      while(true){\n         if(d >= (int)A.size()) return N;\n\
    \         if(i/W >= (int)A[d].size()) return N;\n         Word m = A[d][i/W] &\
    \ ((~(Word)0) << (i%W));\n         if(!m){ d++; i /= W; i++; }\n         else{\n\
    \               int to = lowBit(m);\n               i = i/W*W + to;\n        \
    \       if(d == 0) break;\n               i *= W;\n               d--;\n     \
    \    }\n      }\n      return i;\n   }\n   int noGreaterThan(int x) const {\n\
    \      if(x < 0) return -1;\n      if(N <= x) x = N-1;\n      int d = 0, i = x;\n\
    \      while(true){\n         if(i < 0) return -1;\n         if(d >= (int)A.size())\
    \ return -1;\n         Word m = A[d][i/W] & ~((~(Word)1) << (i%W));\n        \
    \ if(!m){ d++; i /= W; i--; }\n         else{\n            int to = highBit(m);\n\
    \            i = i/W*W + to;\n            if(d == 0) break;\n            i *=\
    \ W;\n            i += W-1;\n            d--;\n         }\n      }\n      return\
    \ i;\n   }\n};\n"
  code: "struct WordsizeTree{\n   using Word = unsigned long long;\n   static constexpr\
    \ int W = 64;\n   int N;\n   vector<vector<Word>> A;\n   static int highBit(Word\
    \ x){\n      if(x == 0) return 0;\n      return W-1 - __builtin_clzll(x);\n  \
    \ }\n   static int lowBit(Word x){\n      if(x == 0) return W;\n      return __builtin_ctzll(x);\n\
    \   }\n   WordsizeTree(int length){\n      N = length;\n      int n = length;\n\
    \      do {\n         vector<Word> a(n/W+1,0);\n         A.emplace_back(move(a));\n\
    \         n /= W;\n      } while(n);\n   }\n   WordsizeTree(const string& binStr\
    \ = \"\"){\n      N = binStr.size();\n      int n = N;\n      {\n         vector<Word>\
    \ a(n/W+1);\n         for(int i=0; i<n; i++) if(binStr[i] == '1'){\n         \
    \   a[i/W] |= (Word)1 << (i%W);\n         }\n         A.emplace_back(move(a));\n\
    \         n /= W;\n      }\n      while(n){\n         vector<Word> a(n/W+1,0);\n\
    \         for(int i=0; i<=n; i++){\n            if(A.back()[i]) a[i/W] |= (Word)1\
    \ << (i%W);\n         }\n         A.emplace_back(move(a));\n         n /= W;\n\
    \      }\n   }\n   void insert(int x){\n      for(auto& a : A){\n         a[x/W]\
    \ |= (Word)1 << (x % W);\n         x /= W;\n      }\n   }\n   void erase(int x){\n\
    \      for(auto& a : A){\n         a[x/W] &= ~((Word)1 << (x % W));\n        \
    \ if(a[x/W]) return;\n         x /= W;\n      }\n   }\n   int count(int x) const\
    \ {\n      return (int)((A[0][x/W] >> (x%W)) & 1);\n   }\n   int noLessThan(int\
    \ x) const {\n      if(x < 0) x = 0;\n      if(N <= x) return N;\n      int d\
    \ = 0, i = x;\n      while(true){\n         if(d >= (int)A.size()) return N;\n\
    \         if(i/W >= (int)A[d].size()) return N;\n         Word m = A[d][i/W] &\
    \ ((~(Word)0) << (i%W));\n         if(!m){ d++; i /= W; i++; }\n         else{\n\
    \               int to = lowBit(m);\n               i = i/W*W + to;\n        \
    \       if(d == 0) break;\n               i *= W;\n               d--;\n     \
    \    }\n      }\n      return i;\n   }\n   int noGreaterThan(int x) const {\n\
    \      if(x < 0) return -1;\n      if(N <= x) x = N-1;\n      int d = 0, i = x;\n\
    \      while(true){\n         if(i < 0) return -1;\n         if(d >= (int)A.size())\
    \ return -1;\n         Word m = A[d][i/W] & ~((~(Word)1) << (i%W));\n        \
    \ if(!m){ d++; i /= W; i--; }\n         else{\n            int to = highBit(m);\n\
    \            i = i/W*W + to;\n            if(d == 0) break;\n            i *=\
    \ W;\n            i += W-1;\n            d--;\n         }\n      }\n      return\
    \ i;\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/64tree.hpp
  requiredBy: []
  timestamp: '2025-02-21 18:02:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/64tree.hpp
layout: document
redirect_from:
- /library/src/data-structure/64tree.hpp
- /library/src/data-structure/64tree.hpp.html
title: src/data-structure/64tree.hpp
---
