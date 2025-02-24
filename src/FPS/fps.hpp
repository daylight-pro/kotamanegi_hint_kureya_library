using vm = vector<mm>;
vm pre(vm f, int sz) { return vm(f.begin(), f.begin() + min((int)f.size(), sz)); }
vm inv(vm f, int deg = -1) {
   if(deg < 0) deg = (int)f.size();
   vm res({mm(1) / f[0]});
   for(int i = 1; i < deg; i <<= 1) {
      vm ff = conv(res, conv(res, pre(f, i << 1)));
      int sz = res.size();
      for(int j = 0; j < sz; j++) res[j] += res[j];
      sz = max(sz, (int)ff.size());
      res.resize(sz);
      sz = ff.size();
      for(int j = 0; j < sz; j++) res[j] -= ff[j];
      res = pre(res, i << 1);
   }
   res.resize(deg);
   return res;
}
vm diff(vm f) {
   int n = f.size();
   vm res(n - 1);
   for(int i = 1; i < n; i++) res[i - 1] = f[i] * i;
   return res;
}
vm intg(vm f) {
   int n = (int)f.size();
   vm res(n + 1, 0);
   for(int i = 0; i < n; i++) res[i + 1] = f[i] / (i + 1);
   return res;
}
vm log(vm f, int deg = -1) {
   if(deg == -1) deg = f.size();
   vm res = intg(conv(diff(f), inv(f, deg)));
   res.resize(deg);
   return res;
}
vm exp(vm f, int deg = -1) {
   vm res(1, 1);
   if(deg == -1) deg = f.size();
   for(int i = 1; i < deg; i <<= 1) {
      vm ff1 = pre(f, i << 1);
      vm ff2 = log(res, i << 1);
      ff1.resize(max(ff1.size(), ff2.size()));
      ff1[0] += mm(1);
      int sz = ff2.size();
      for(int j = 0; j < sz; j++) ff1[j] -= ff2[j];
      res = conv(res, pre(ff1, i << 1));
   }
   res.resize(deg);
   return res;
}
vm taylor_shift(vm f, mm a) {
   int n = f.size();
   vm fac(n, 1), inv(n, 1), finv(n, 1);
   for(int i = 2; i < n; i++) {
      fac[i] = fac[i - 1] * i;
      inv[i] = -inv[mod % i] * (mod / i);
      finv[i] = finv[i - 1] * inv[i];
   }
   for(int i = 0; i < n; i++) f[i] *= fac[i];
   std::reverse(f.begin(), f.end());
   vm g(n, 1);
   for(int i = 1; i < n; i++) g[i] = g[i - 1] * a * inv[i];
   f = pre(conv(f, g), n);
   reverse(f.begin(), f.end());
   for(int i = 0; i < n; i++) f[i] *= finv[i];
   return f;
}