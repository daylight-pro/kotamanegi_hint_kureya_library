// base: 822702
template<int char_size, int margin> struct AhoCorasick : Trie<char_size + 1, margin> {
   using Trie<char_size + 1, margin>::Trie;

   const int FAIL = char_size;
   vector<int> correct;

   void build(bool heavy = true) {
      correct.resize(this->nodes.size());
      for(int i = 0; i < size(this->nodes); ++i) { correct[i] = size(this->nodes[i].accept); }
      queue<int> que;
      for(int i = 0; i < char_size; ++i) {
         if(~this->nodes[0].nxt[i]) {
            this->nodes[this->nodes[0].nxt[i]].nxt[FAIL] = 0;
            que.emplace(this->nodes[0].nxt[i]);
         } else {
            this->nodes[0].nxt[i] = 0;
         }
      }
      while(!que.empty()) {
         auto& now = this->nodes[que.front()];
         int fail = now.nxt[FAIL];
         correct[que.front()] += correct[fail];
         que.pop();
         for(int i = 0; i < char_size; i++) {
            if(~now.nxt[i]) {
               this->nodes[now.nxt[i]].nxt[FAIL] = this->nodes[fail].nxt[i];
               if(heavy) {
                  auto& u = this->nodes[now.nxt[i]].accept;
                  auto& v = this->nodes[this->nodes[fail].nxt[i]].accept;
                  vector<int> accept;
                  set_union(all(u), all(v), back_inserter(accept));
                  u = accept;
               }
               que.emplace(now.nxt[i]);
            } else {
               now.nxt[i] = this->nodes[fail].nxt[i];
            }
         }
      }
   }

   vector<int> match(const char& c, int now = 0) {
      vector<int> res;
      now = this->nodes[now].nxt[c - margin];
      for(auto& v : this->nodes[now].accept) res.push_back(v);
      return res;
   }  // 68ef6b

   unordered_map<int, int> match(const string& str, int now = 0) {
      unordered_map<int, int> res, visit_cnt;
      for(auto& c : str) {
         now = this->nodes[now].nxt[c - margin];
         visit_cnt[now]++;
      }
      for(auto& [now, cnt] : visit_cnt) {
         for(auto& v : this->nodes[now].accept) res[v] += cnt;
      }
      return res;
   }  // 36fe6c

   pair<ll, int> move(const char& c, int now = 0) {
      now = this->nodes[now].nxt[c - margin];
      return {correct[now], now};
   }  // 43ccad

   pair<ll, int> move(const string& str, int now = 0) {
      ll res = 0;
      for(auto& c : str) {
         auto [cnt, nxt] = move(c, now);
         res += cnt;
         now = nxt;
      }
      return {res, now};
   }  // b1949a
};