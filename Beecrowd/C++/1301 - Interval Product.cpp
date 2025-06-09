#include <bits/stdc++.h>
using namespace std;

#define MAX 100010
#define l(p) ((p) << 1)
#define r(p) (l(p) + 1)

int n, k, a[MAX], st[4*MAX];

int build(int p, int L, int R){
  if(L == R) return st[p] = a[L];
  int m = (L+R)/2;
  return st[p] = build(l(p), L, m) *
                 build(r(p), m+1, R);
}

int query(int p, int L, int R, int i, int j){
  if(R < i || L > j) return 1;
  if(i <= L && R <= j) return st[p];
  int m = (L+R)/2;
  return query(l(p), L, m, i, j) *
         query(r(p), m+1, R, i, j);
}

int update(int p, int L, int R, int i, int val){
  if(i < L || i > R) return st[p];
  if(i == L && L == R) return st[p] = val;
  int m = (L+R)/2;
  return st[p] = update(l(p), L, m, i, val) *
                 update(r(p), m+1, R, i, val);
}

int main(){

  int i, j;
  while(cin >> n >> k){
    for(i=0; i<n; i++){
      cin >> a[i];
      if(a[i]) a[i] /= abs(a[i]);
    }

    build(1, 0, n-1);
    while(k--){
      char op;
      cin >> op >> i >> j;

      if(op == 'C'){
        i--;
        if(j) j /= abs(j);
        update(1, 0, n-1, i, j);
      }
      else{
        i--, j--;
        int ans = query(1, 0, n-1, i, j);
        printf("%c", ans ? (ans > 0 ? '+' : '-') : '0');
      }
    }
    cout << endl;
  }

  return 0;
}
