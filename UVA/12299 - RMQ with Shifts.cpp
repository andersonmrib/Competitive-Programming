#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

typedef vector<int> vi;
const int INF = 1e9;

class segTree{

private:
  int n;
  vi A, st, lazy;

  int l(int p) { return (p<<1);   }
  int r(int p) { return (p<<1)+1; }

  void build(int p, int L, int R){
    if(L == R)
      st[p] = A[L];
    else{
      int m = L + (R - L)/2;
      build(l(p), L, m);
      build(r(p), m+1, R);
      st[p] = min(st[l(p)], st[r(p)]);
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
    st[p] = min(st[r(p)], st[l(p)]);
  }

  int query(int p, int L, int R, int i, int j){
    if(i > j) return INF;
    if((L >= i) && (R <= j))
      return st[p];
    int m = L + (R - L)/2;
    int p1 = query(l(p), L, m, i, min(m, j));
    int p2 = query(r(p), m+1, R, max(m+1, i), j);
    return min(p1, p2);
  }


public:

  segTree(int sz) : n(sz), st(4*n), lazy(4*n, -1) {}

  segTree(const vi &initialA) : segTree((int)initialA.size()){
    A = initialA;
    build(1, 0, n-1);
  }

  void update(int idx, int val) { update(1, 0, n-1, idx, val); }

  int query(int i, int j) { return query(1, 0, n-1, i, j); }

};

void parse_numbers(const char *s, vi &indexes){
  indexes.clear();
  int cur_num = 0;
  bool keep_going = false;
  for(int i=0; s[i] != '\0'; i++){
    if(s[i] >= '0' && s[i] <= '9'){
      // Keep constructing the number
      cur_num = cur_num * 10 + (s[i] - '0');
      keep_going = true;
    }
    else{
      if(keep_going){
        indexes.push_back(cur_num);
        cur_num = 0;
        keep_going = false;
      }
    }
  }
}

int main(){

  speedBoost;
  int n, q;
  scanf("%d %d", &n, &q);

  vi A(n);
  for(int i=0; i<n; i++)
    scanf("%d", &A[i]);

  segTree st(A);

  char str[40];
  vi indexes_numbers;
  for(int i=0; i<q; i++){
    scanf("%s", str);

    parse_numbers(str, indexes_numbers);
    if(str[0] == 'q'){
      int print_it = st.query(indexes_numbers[0] - 1, indexes_numbers[1] - 1);
      printf("%d\n", print_it);
    }
    else{
      int first_value = A[indexes_numbers[0] - 1];
      for(int i=0; i<indexes_numbers.size() - 1; i++){
        int to_idx = indexes_numbers[i] - 1;
        int from_idx = indexes_numbers[i+1] - 1;
        int value_to_move = A[from_idx];

        A[to_idx] = value_to_move;
        st.update(to_idx, value_to_move);
      }

      int last_idx = indexes_numbers.back() - 1;
      A[last_idx] = first_value;
      st.update(last_idx, first_value);
    }
  }

  return 0;
}
