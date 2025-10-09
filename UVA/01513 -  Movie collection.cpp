#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

typedef vector<int> vi;

class segTree{

private:
  int n;
  vi st;

  int l(int p) { return p<<1;    }
  int r(int p) { return(p<<1)+1; }

  void update(int p, int L, int R, int idx, int val){
    if(L == R){
      st[p] = val;
      return;
    }
    int m = (L+R)/2;
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
    int m = (L+R)/2;
    return query(l(p), L, m, i, min(m, j)) +
           query(r(p), m+1, R, max(m+1, i), j);
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

    int n, m; cin >> n >> m;

    segTree st(n+m);

    vi pos(n, 0);
    for(int i=0; i<n; i++){
      pos[i] = i + m;
      st.update(pos[i], 1);
    }

    int top_most_so_far = m-1;
    for(int i=0; i<m; i++){

      int movie_id; cin >> movie_id;
      movie_id--;
      int movie_location = pos[movie_id];

      if(i > 0) cout << " ";
      cout << st.query(0, movie_location-1);

      st.update(movie_location, 0);
      pos[movie_id] = top_most_so_far;
      st.update(top_most_so_far, 1);
      top_most_so_far--;
    }

    cout << endl;
  }

  return 0;
}
