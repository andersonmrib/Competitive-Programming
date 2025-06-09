#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int INF = 1e9;

vi A, p;
int len;

void print_lis(int i){
  if(p[i] == -1) { cout << A[i] << endl; return; }
  print_lis(p[i]);
  if(A[i] != INF) cout << A[i] << endl;
}

int main(){

  int k = 0, lis_end = 0, num;

  while(cin >> num) A.push_back(num);
  A.push_back(INF);

  len = A.size();
  vi L(len, 0), L_id(len, 0);
  p.assign(len, -1);

  for(int i=0; i<len; i++){
    int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
    if(pos == 0 || L[pos - 1] < A[i]){
      L[pos] = A[i];
      L_id[pos] = i;
      p[i] = (pos > 0) ? L_id[pos-1] : -1;
      if(pos == k){
        k = pos+1;
        lis_end = i;
      }
    }
  }

  cout << k - 1 << endl;
  cout << "-" << endl;
  print_lis(lis_end);

  return 0;
}
