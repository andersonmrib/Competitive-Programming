#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

typedef vector<int> vi;

class segTree{

private:
  int n;
  vi A, st;
  vector<char> lazy;

  int l(int p) { return p<<1; }
  int r(int p) { return (p<<1)+1; }

  int conquer(int a, int b){
    if(a == -1) return b;
    if(b == -1) return a;
    return a + b;
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
    if(lazy[p] == '\0') return;

    if(lazy[p] == 'F')
      st[p] = (R - L + 1);
    else if(lazy[p] == 'E')
      st[p] = 0;
    else
      st[p] = (R - L + 1) - st[p];

    if(L != R){
      // Propagates downwards
      if(lazy[p] == 'F' || lazy[p] == 'E')
        lazy[l(p)] = lazy[r(p)] = lazy[p];
      else{
        if(lazy[l(p)] == 'F') lazy[l(p)] = 'E';
        else if(lazy[l(p)] == 'E') lazy[l(p)] = 'F';
        else if(lazy[l(p)] == 'I') lazy[l(p)] = '\0';
        else lazy[l(p)] = 'I'; // Important!

        if(lazy[r(p)] == 'F') lazy[r(p)] = 'E';
        else if(lazy[r(p)] == 'E') lazy[r(p)] = 'F';
        else if(lazy[r(p)] == 'I') lazy[r(p)] = '\0';
        else lazy[r(p)] = 'I'; // Important!
      }
    }
    lazy[p] = '\0';
  }

  int query(int p, int L, int R, int i, int j){
    propagate(p, L, R);
    if(i > j) return -1;
    if((L >= i) && (R <= j)) return st[p];
    int m = (L+R)/2;
    return conquer(query(l(p), L, m, i, min(m, j)),
                   query(r(p), m+1, R, max(m+1, i), j));
  }

  void update(int p, int L, int R, int i, int j, char op){
    propagate(p, L, R);
    if(i > j) return;
    if((L >= i) && (R <= j)){
      lazy[p] = op;
      propagate(p, L, R);
      return;
    }
    else{
      int m = (L+R)/2;
      update(l(p), L, m, i, min(m, j), op);
      update(r(p), m+1, R, max(m+1, i), j, op);
      st[p] = conquer(st[l(p)], st[r(p)]);
    }
  }

public:

  segTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n, '\0') {}

  segTree(vi &initialA) : segTree((int)initialA.size()){
    A = initialA;
    build(1, 0, n-1);
  }

  int query(int i, int j) { return query(1, 0, n-1, i, j); }

  void update(int i, int j, char op) { update(1, 0, n-1, i, j, op); }
};

int main(){

  speedBoost;
  int T; cin >> T;
  int NC = 1;
  while(T--){

    int m; cin >> m;
    string pirates = "";
    // Buccaneer = 1, Barbary = 0
    for(int i=0; i<m; i++){
      int t; cin >> t;
      string line; cin >> line;
      for(int j=0; j<t; j++)
        pirates += line;
    }

    vi A((int)pirates.size());
    for(int i=0; i<pirates.size(); i++)
      A[i] = pirates[i] - '0';

    // Starts creating the tree here!
    segTree seg1(A);

    cout << "Case " << NC++ << ":\n";
    int question = 1;
    int Q; cin >> Q;
    for(int i=0; i<Q; i++){
      char op;
      int a, b;
      cin >> op >> a >> b;

      if(op == 'S'){
        cout << "Q" << question++ << ": ";
        cout << seg1.query(a, b) << endl;
      }
      else
        seg1.update(a, b, op);
    }
  }

  return 0;
}
