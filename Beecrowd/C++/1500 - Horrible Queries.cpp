#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef vector<ull> vi;

vi A, st, lazy;

int l(int p) { return (p<<1)+1; }
int r(int p) { return (p<<1)+2; }

ull conquer(ull a, ull b){
  if(a == -1) return b;
  if(b == -1) return a;
  return a+b;
}

void build(int p, int L, int R){
  if(L == R)
    st[p] = A[L];
  else{
    int m = (L+R)/2;
    build(l(p), L, m);
    build(r(p), m+1, R);
    st[p] = conquer(st[l(p)], st[r(p)]);
  }
}

void propagate(int p, int L, int R){
  if(lazy[p] != 0){
    st[p] += lazy[p] * (R - L + 1);
    if(L != R){
      lazy[l(p)] += lazy[p];
      lazy[r(p)] += lazy[p];
    }
    lazy[p] = 0;
  }
}

ull query(int p, int L, int R, int i, int j){
  propagate(p, L, R);
  if(i > j) return 0;
  if((L >= i) && (R <= j)) return st[p];
  int m = (L+R)/2;
  return conquer(query(l(p), L  , m, i          , min(m, j)),
                 query(r(p), m+1, R, max(i, m+1), j       ));
}

void update(int p, int L, int R, int i, int j, ull val){
  propagate(p, L, R);
  if(i > j) return;
  if((L >= i) && (R <= j)){
    lazy[p] += val;
    propagate(p, L, R);
  }
  else{
    int m = (L+R)/2;
    update(l(p), L  , m, i          , min(m, j), val);
    update(r(p), m+1, R, max(i, m+1), j        , val);
    st[p] = conquer(st[l(p)], st[r(p)]);
  }
}

int main(){

  int T; scanf("%d", &T);
  while(T--){
    int n, c; scanf("%d %d", &n, &c);
    A.assign(n, 0), st.assign(n*4, 0), lazy.assign(n*4, 0);

    build(0, 0, n-1);

    while(c--){
      int op; scanf("%d", &op);

      if(!op){
        int p, q; ull v; scanf("%d %d %llu", &p, &q, &v); p--, q--;
        update(0, 0, n-1, p, q, v);
      }
      else{
        int p, q; scanf("%d %d", &p, &q); p--, q--;
        ull result = query(0, 0, n-1, p, q);
        printf("%llu\n", result);
      }
    }
  }

    return 0;
}
