// Bostan-Mori
// find [x^N] P(x)/Q(x), O(K log K log N)
// deg(Q(x)) = K, deg(P(x)) < K, Q[0] = 1
template <typename mint> mint BostanMori(const vector<mint> &P, const vector<mint> &Q, long long N) {
   assert(!P.empty() && !Q.empty());
   if (N == 0) return P[0] / Q[0];
   
   int qdeg = (int)Q.size();
   vector<mint> P2{P}, minusQ{Q};
   P2.resize(qdeg - 1);
   for (int i = 1; i < (int)Q.size(); i += 2) minusQ[i] = -minusQ[i];
   P2 = conv(P2, minusQ);
   vector<mint> Q2 = conv(Q, minusQ);
   vector<mint> S(qdeg - 1), T(qdeg);
   for (int i = 0; i < (int)S.size(); ++i) {
      S[i] = (N % 2 == 0 ? P2[i * 2] : P2[i * 2 + 1]);
   }
   for (int i = 0; i < (int)T.size(); ++i) {
      T[i] = Q2[i * 2];
   }
   return BostanMori(S, T, N >> 1);
}
