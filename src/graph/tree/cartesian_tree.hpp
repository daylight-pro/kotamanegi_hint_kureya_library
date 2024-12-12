template<class T> struct cartesian_tree {
   int root;
   vector<int> par, left, right;

   cartesian_tree(const vector<T>& v) : root(0), par(size(v), -1), left(size(v), -1), right(size(v), -1) {
      stack<int> st;
      int N = size(v);
      for(int i = 0; i < N; i++) {
         int prev = -1;
         while(!st.empty() && v[st.top()] > v[i]) {
            prev = st.top();
            st.pop();
         }
         if(prev != -1) par[prev] = i;
         if(!st.empty()) par[i] = st.top();
         st.push(i);
      }

      root = -1;
      for(int i = 0; i < N; i++) {
         if(par[i] == -1) root = i;
         else if(par[i] < i) right[par[i]] = i;
         else left[par[i]] = i;
      }
   }
};