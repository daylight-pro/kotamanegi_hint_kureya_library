#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2320"

#include "test/template.hpp"
#include "src/algorithm/doubling.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int H, W;
   ll L;
   while(cin >> H >> W >> L) {
      if(H == 0 && W == 0 && L == 0) break;
      vector<string> S(H);
      for(auto&& s : S) cin >> s;
      vector<int> nxt(H * W * 4, -1);
      int dx[4] = {1, 0, -1, 0};
      int dy[4] = {0, 1, 0, -1};
      int y, x, dir;
      rep(i, 0, H) {
         rep(j, 0, W) {
            if(S[i][j] == 'E') {
               y = i;
               x = j;
               dir = 0;
               break;
            } else if(S[i][j] == 'S') {
               y = i;
               x = j;
               dir = 1;
               break;
            } else if(S[i][j] == 'W') {
               y = i;
               x = j;
               dir = 2;
               break;
            } else if(S[i][j] == 'N') {
               y = i;
               x = j;
               dir = 3;
               break;
            }
         }
      }
      int sy = y, sx = x, sd = dir;
      while(nxt[y * 4 * W + 4 * x + dir] == -1) {
         int ny = y + dy[dir];
         int nx = x + dx[dir];
         int pd = dir;
         while(ny < 0 || ny >= H || nx < 0 || nx >= W || S[ny][nx] == '#') {
            dir = (dir + 1) % 4;
            ny = y + dy[dir];
            nx = x + dx[dir];
         }
         nxt[y * 4 * W + 4 * x + pd] = ny * 4 * W + 4 * nx + dir;
         y = ny;
         x = nx;
      }
      Doubling<60> db(nxt);
      int to = db.jump(sy * W * 4 + 4 * sx + sd, L);
      int Y = to / W / 4;
      int X = to / 4 % W;
      int d = to % 4;
      cout << Y + 1 << ' ' << X + 1 << ' ';
      if(d == 0) cout << 'E';
      if(d == 1) cout << 'S';
      if(d == 2) cout << 'W';
      if(d == 3) cout << 'N';

      cout << '\n';
   }
   return 0;
}