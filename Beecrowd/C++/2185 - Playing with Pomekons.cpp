#include <bits/stdc++.h>
#define MAX 10010
using namespace std;

typedef vector<int> vi;

int n;
vi A(MAX), st(MAX*4), lazy(MAX*4, -1);

int l(int p){ return (p<<1); }
int r(int p){ return (p<<1)+1; }

int conquer(int a, int b){
  if(a == -1) return b;
  if(b == -1) return a;
  return a^b;
}

void build(int p, int L, int R){
  if(L == R) st[p] = A[L];
  else{
    int m = (L+R)/2;
    build(l(p), L, m);
    build(r(p), m+1, R);
    st[p] = conquer(st[l(p)], st[r(p)]);
  }
}

void propagate(int p, int L, int R){
  if(lazy[p] != -1){
    st[p] = (R - L + 1) % 2 == 1 ? lazy[p] : 0;
    if(L != R) lazy[l(p)] = lazy[r(p)] = lazy[p];
  lazy[p] = -1;
  }
}

int query(int p, int L, int R, int i, int j){
  propagate(p, L, R);
  if(i > j) return -1;
  if((L >= i) && (R <= j)) return st[p];
  int m = (L+R)/2;
  return conquer(query(l(p), L  , m, i          , min(m, j)),
                 query(r(p), m+1, R, max(i, m+1), j       ));
}

void update(int p, int L, int R, int i, int j, int val){
  propagate(p, L, R);
  if(i > R || j < L) return;
  if((L >= i) && (R <= j)){
    lazy[p] = val;
    propagate(p, L, R);
  }
  else{
    int m = (L+R)/2;
    update(l(p), L  , m, i          , min(m, j), val);
    update(r(p), m+1, R, max(i, m+1), j        , val);
    int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
    int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
    st[p] = conquer(lsubtree, rsubtree);
  }
}

int main(){

  int m; scanf("%d %d", &n, &m); // n is global

  A.resize(n), st.resize(n*4), lazy.resize(n*4, -1);

  for(int i=0; i<n; i++)
    scanf("%d", &A[i]);

  build(1, 0, n-1);

  while(m--){
    int idx1, idx2, v; scanf("%d %d %d", &idx1, &idx2, &v);
    idx1--, idx2--;

    update(1, 0, n-1, idx1, idx2, v);

    if(query(1, 0, n-1, 0, n-1) == 0)
      printf("Impossivel\n");
    else
      printf("Possivel\n");
  }

  return 0;
}
