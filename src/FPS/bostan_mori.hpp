// find [x^N] P(x)/Q(x), O(K log K log N)
// deg(Q(x)) = K, deg(P(x)) < K, Q[0] = 1
mm BostanMori(vector<mm> P, vector<mm> Q, ll N) {
   const int d = Q.size();
   for(; N; N >>= 1) {
      auto Q_neg = Q;
      for(size_t i = 1; i < Q.size(); i += 2) Q_neg[i] *= -1;
      P = conv(P, Q_neg);
      Q = conv(Q, Q_neg);
      for(size_t i = N & 1; i < P.size(); i += 2) P[i >> 1] = P[i];
      for(size_t i = 0; i < Q.size(); i += 2) Q[i >> 1] = Q[i];
      P.resize(d - 1);
      Q.resize(d);
   }
   return P[0];
}