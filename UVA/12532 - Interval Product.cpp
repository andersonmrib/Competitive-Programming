#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;

struct segTree{

  int size;
  vi product;

  void init(int n){
    size = 1;
    while(size < n) size *=2;
    product.assign(size*2, 1LL);
  }

  void build(vi &a, int x, int lx, int rx){
    if(rx - lx == 1){
      if(lx < a.size()){
        product[x] = a[lx];
      }
      return;
    }
    int m = (lx + rx)/2;
    build(a, 2*x+1, lx, m);
    build(a, 2*x+2, m, rx);
    product[x] = product[2*x+1] * product[2*x+2];
  }

  void build(vi &a){
    build(a, 0, 0, size);
  }

  void update(int i, int v, int x, int lx, int rx){
    if(rx - lx == 1){
      product[x] = v;
      return;
    }
    int m = (lx + rx)/2;
    if(i < m)
      update(i, v, 2*x+1, lx, m);
    else
      update(i, v, 2*x+2, m, rx);
    product[x] = product[2*x+1] * product[2*x+2];
  }

  void update(int i, int v){
    update(i, v, 0, 0, size);
  }

  int query(int l, int r, int x, int lx, int rx){
    if(lx >= r || l >= rx) return 1;
    if(lx >= l && rx <= r) return product[x];
    int m = (lx + rx)/2;
    int p1 = query(l, r, 2*x+1, lx, m);
    int p2 = query(l, r, 2*x+2, m, rx);
    return p1 * p2;
  }

  int query(int l, int r){
    return query(l, r, 0, 0, size);
  }
};

int main(){

  speedBoost;
  int N, K;
  while(cin >> N >> K){

    vi a(N);
    for(int i=0; i<N; i++){
      cin >> a[i];
      if(a[i]) a[i] /= abs(a[i]);
    }

    segTree st;
    st.init(N), st.build(a);

    for(int i=0; i<K; i++){

      char op; cin >> op;
      if(op == 'C'){
        int I, V;
        cin >> I >> V;
        if(V) V /= abs(V);
        I--;
        st.update(I, V);
      }
      else{
        int I, J;
        cin >> I >> J;
        I--, J--;
        int ans = st.query(I, J+1);
        if(ans < 0) cout << "-";
        else if(ans > 0) cout << "+";
        else cout << "0";
      }
    }
    cout << "\n";
  }

  return 0;
}
