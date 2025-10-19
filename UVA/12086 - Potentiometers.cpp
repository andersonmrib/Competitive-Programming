#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;

typedef vector<int> vi;
const int INF = 1e9;

class SegTree{

private:
  vi A, st;
  int n;

  int l(int p) { return (p<<1);   }
  int r(int p) { return (p<<1)+1; }

  void build(int p, int L, int R){
    if(L == R)
      st[p] = A[L];
    else{
      int m = L + (R - L)/2;
      build(l(p), L, m);
      build(r(p), m+1, R);
      st[p] = st[l(p)] + st[r(p)];
    }
  }

  void update(int p, int L, int R, int idx, int val){
    if(L == R){
      st[p] = val;
      return;
    }
    int m = L + (R - L)/2;
    if(idx <= m)
      update(l(p), L, m, idx, val);
    else
      update(r(p), m+1, R, idx, val);
    st[p] = st[l(p)] + st[r(p)];
  }

  int query(int p, int L, int R, int i, int j){
    if(i > j) return 0;
    if((L >= i) && (R <= j))
      return st[p];
    int m = L + (R - L)/2;
    int p1 = query(l(p), L, m, i, min(m, j));
    int p2 = query(r(p), m+1, R, max(m+1, i), j);
    return p1 + p2;
  }

public:

  SegTree(const vi originalA){
    n = originalA.size();
    st.assign(4*n, 0);
    A = originalA;
    build(1, 0, n-1);
  }

  int query(int i, int j){ return query(1, 0, n-1, i, j); }

  void update(int idx, int val) { update(1, 0, n-1, idx, val); }

};

/* Is the output wrong? */
int main(){

  speedBoost;
  int N, NC = 0;
  while(cin >> N, N){

    vi A(N);
    for(int i=0; i<N; i++)
      cin >> A[i];

    SegTree st(A);
    if(NC) cout << endl;
    cout << "Case " << ++NC << ":\n";

    string command; cin.ignore();
    while(getline(cin, command)){
      if(command == "END") break;

      stringstream ss(command);
      char op;
      int a, b;
      ss >> op;

      if(op == 'S'){
        int x, y; ss >> x >> y;
        x--;
        st.update(x, y);
      }
      else{
        int x, y; ss >> x >> y;
        x--, y--;
        cout << st.query(x, y) << endl;
      }
    }
  }

  return 0;
}
