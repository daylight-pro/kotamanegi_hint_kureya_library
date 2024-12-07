// base: 69a9e9
template<typename T, int MAX_LOG = 32> struct BinaryTrie {
   struct Node {
      array<int, 2> next;
      int common;
      T lazy;
      Node() : next{-1, -1}, common(), lazy() {}
   };
   vector<Node> nodes;
   BinaryTrie() { nodes.push_back(Node()); }
   void apply_xor(T val) { nodes[0].lazy ^= val; }
   void push(int cur, int b) {
      if((nodes[cur].lazy >> b) & 1) swap(nodes[cur].next[0], nodes[cur].next[1]);
      rep(i, 0, 2) {
         if(nodes[cur].next[i] == -1) nodes[nodes[cur].next[i]].lazy ^= nodes[cur].lazy;
      }
      nodes[cur].lazy = 0;
   }
   void add(T val, int cur = 0, int b = MAX_LOG - 1) {
      nodes[cur].common++;
      if(b == -1) return;
      push(cur, b);
      int nxt = (val >> (T)b) & (T)1;
      if(nodes[cur].next[nxt] == -1) {
         nodes[cur].next[nxt] = sz(nodes);
         nodes.push_back(Node());
      }
      add(val, nodes[cur].next[nxt], b - 1);
   }

   void erase(T val, int cur = 0, int b = MAX_LOG - 1) {
      nodes[cur].common--;
      if(b == -1) return;
      push(cur, b);
      erase(val, nodes[cur].next[(val >> b) & 1], b - 1);
   }

   T min_element(T val = 0, int cur = 0, int b = MAX_LOG - 1) {
      if(b == -1) return 0;
      push(cur, b);
      T nxt = (val >> b) & 1;
      int ind = nodes[cur].next[nxt];
      if(ind == -1 || nodes[ind].common == 0) nxt ^= 1;
      return min_element(val, nodes[cur].next[nxt], b - 1) | (nxt << b);
   }  // ddf699

   T max_element(T val = 0, int cur = 0, int b = MAX_LOG - 1) { return min_element(~val); }  // 5e1a86

   int lower_bound_rank(T val, int cur = 0, int b = MAX_LOG - 1) {
      if(cur == -1 || b == -1) return 0;
      push(cur, b);
      T nxt = (val >> b) & 1;
      int ret = lower_bound_rank(val, nodes[cur].next[nxt], b - 1);
      if(nxt == 1 && nodes[cur].next[0] != -1) { ret += nodes[nodes[cur].next[0]].common; }
      return ret;
   }  // 05b14c

   int upper_bound_rank(T val) { return lower_bound_rank(val + 1); }  // 70e301

   T kth_smallest(int k, int cur = 0, int b = MAX_LOG - 1) {
      if(b == -1) return 0;
      int lower_ind = nodes[cur].next[0];
      int lower_cnt = 0;
      if(lower_ind != -1) lower_cnt = nodes[lower_ind].common;
      if(k < lower_cnt) return kth_smallest(k, nodes[cur].next[0], b - 1);
      return kth_smallest(k - lower_cnt, nodes[cur].next[1], b - 1) | (T(1) << b);
   }  // b85845

   T kth_largest(int k) { return kth_smallest(nodes[0].common - k); }  // 1df41b

   int count(T val) {
      int cur = 0;
      for(int b = MAX_LOG - 1; b >= 0; b--) {
         push(cur, b);
         cur = nodes[cur].next[(val >> b) & 1];
         if(cur == -1) return 0;
      }
      return nodes[cur].common;
   }  // 2a3342

   int size() { return nodes[0].common; }  // 5f9f13
};