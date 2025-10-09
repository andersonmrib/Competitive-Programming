#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

typedef vector<int> vi;

class segTree{

private:
  int n;
  vi st;

  int l(int p) { return  p<<1;    }
  int r(int p) { return (p<<1)+1; }

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

  segTree(int sz) : n(sz), st(4*n, 0) {}

  void update(int idx, int val) { update(1, 0, n-1, idx, val); }

  int query(int i, int j) { return query(1, 0, n-1, i, j); }
};

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int m, r; cin >> m >> r;
    vi pos(m);
    segTree st(m+r);
    for(int i=0; i<m; i++){
      pos[i] = i + r;
      st.update(pos[i], 1);
    }

    int top_most_so_far = r-1;
    for(int i=0; i<r; i++){
      int a; cin >> a;
      a--;
      int movie_idx = pos[a];

      if(i > 0) cout << " ";
      cout << st.query(0, movie_idx-1);

      st.update(movie_idx, 0);
      pos[a] = top_most_so_far;
      st.update(top_most_so_far, 1);
      top_most_so_far--;
    }
    cout << endl;
  }

  return 0;
}
