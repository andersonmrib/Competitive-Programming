#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vector<ii>> vvii;

const int INF = 1e9;
const int NEG_INF = -INF;

int n;
vector<vi> grid;
vvii st;

ii combine(ii a, ii b){
  return {min(a.first, b.first), max(a.second, b.second)};
}

int l(int p) { return (p<<1);   }
int r(int p) { return (p<<1)+1; }

void build_y(int px, int lx, int rx, int py, int ly, int ry){
  if(ly == ry){
    if(lx == rx)
      st[px][py] = {grid[lx][ly], grid[lx][ly]};
    else
      st[px][py] = combine(st[l(px)][py], st[r(px)][py]);
  }
  else{
    int my = (ly + ry)/2;
    build_y(px, lx, rx, l(py), ly, my);
    build_y(px, lx, rx, r(py), my+1, ry);
    st[px][py] = combine(st[px][l(py)], st[px][r(py)]);
  }
}

void build_x(int px, int lx, int rx){
  if(lx != rx){
    int mx = (lx + rx)/2;
    build_x(l(px), lx, mx);
    build_x(r(px), mx+1, rx);
  }
  build_y(px, lx, rx, 1, 0, n-1);
}

ii query_y(int px, int py, int ly, int ry, int iy, int jy){
  if(iy > jy || ry < iy || ly > jy) return {INF, NEG_INF};
  if((ly >= iy) && (ry <= jy))
    return st[px][py];
  int my = (ly + ry)/2;
  ii p1 = query_y(px, l(py), ly, my, iy, jy);
  ii p2 = query_y(px, r(py), my+1, ry, iy, jy);
  return combine(p1, p2);
}

ii query_x(int px, int lx, int rx, int ix, int jx, int iy, int jy){
  if(ix > jx || rx < ix || lx > jx) return {INF, NEG_INF};
  if((lx >= ix) && (rx <= jx))
    return query_y(px, 1, 0, n-1, iy, jy);
  int mx = (lx + rx)/2;
  ii p1 = query_x(l(px), lx, mx, ix, jx, iy, jy);
  ii p2 = query_x(r(px), mx+1, rx, ix, jx, iy, jy);
  return combine(p1, p2);
}

void update_y(int px, int lx, int rx, int py, int ly, int ry, int x, int y, int new_val){
  if(ly == ry){
    if(lx == rx)
      st[px][py] = {new_val, new_val};
    else
      st[px][py] = combine(st[l(px)][py], st[r(px)][py]);
  }
  else{
    int my = (ly + ry)/2;
    if(y <= my)
      update_y(px, lx, rx, l(py), ly, my, x, y, new_val);
    else
      update_y(px, lx, rx, r(py), my+1, ry, x, y, new_val);
    st[px][py] = combine(st[px][l(py)], st[px][r(py)]);
  }
}

void update_x(int px, int lx, int rx, int x, int y, int new_val){
  if(lx != rx){
    int mx = (lx + rx)/2;
    if(x <= mx)
      update_x(l(px), lx, mx, x, y, new_val);
    else
      update_x(r(px), mx+1, rx, x, y, new_val);
  }
  update_y(px, lx, rx, 1, 0, n-1, x, y, new_val);
}

int main(){

  scanf("%d", &n);
  grid.assign(n, vi(n));
  st.assign(4*n, vector<ii>(4*n, {INF, NEG_INF}));
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      scanf("%d", &grid[i][j]);

  build_x(1, 0, n-1);

  int q; scanf("%d", &q);
  char op;
  for(int i=0; i<q; i++){
    scanf(" %c", &op);

    if(op == 'q'){
      int r1, c1, r2, c2;
      scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

      ii result = query_x(1, 0, n-1, r1-1, r2-1, c1-1, c2-1);
      printf("%d %d\n", result.second, result.first);
    }
    else if(op == 'c'){
      int r, c, v;
      scanf("%d %d %d", &r, &c, &v);
      update_x(1, 0, n-1, r-1, c-1, v);
    }
  }

  return 0;
}
