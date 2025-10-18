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
      st[p] = max(st[l(p)], st[r(p)]);
    }
  }

  int query(int p, int L, int R, int i, int j){
    if(i > j) return -INF;
    if((L >= i) && (R <= j))
      return st[p];
    int m = L + (R - L)/2;
    int p1 = query(l(p), L, m, i, min(m, j));
    int p2 = query(r(p), m+1, R, max(m+1, i), j);
    return max(p1, p2);
  }

public:

  SegTree(const vi originalA){
    n = originalA.size();
    st.assign(4*n, 0);
    A = originalA;
    build(1, 0, n-1);
  }

  int query(int i, int j){ return query(1, 0, n-1, i, j); }

};

int main(){

  speedBoost;
  int n, q;
  while(cin >> n, n){

    cin >> q;

    vi A(n);
    for(int i=0; i<n; i++)
      cin >> A[i];

    vi freq(n), start(n);
    for(int i=0; i<n; ){

      int j = i;
      while(j < n && A[i] == A[j])
        j++;

      for(int k=i; k<j; k++){
        freq[k] = j - i;
        start[k] = i;
      }
      i = j;
    }

    SegTree st(freq);
    while(q--){

      int i, j; cin >> i >> j;
      i--, j--;

      if(start[i] == start[j]){
        cout << j - i + 1 << endl;
        continue;
      }

      int left_block_end = start[i] + freq[i] - 1;
      int left_block_freq = left_block_end - i + 1;
      int right_block_freq = j - start[j] + 1;

      int middle_begin = left_block_end + 1;
      int middle_end = start[j] - 1;

      int query = st.query(middle_begin, middle_end);
      cout << max({left_block_freq, query, right_block_freq}) << endl;
    }
  }

  return 0;
}
