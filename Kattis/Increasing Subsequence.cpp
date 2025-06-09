#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int INF = 1e9;
typedef vector<int> vi;
vi A, p;

void print_LIS(int i){
  if(p[i] == -1) { cout << A[i]; return; }
  print_LIS(p[i]);
  cout << " " << A[i];
}

int main(){

  speedBoost;
  int n;
  while((cin >> n), n){

    A.assign(n+1, 0);
    for(int i=0; i<n; i++)
      cin >> A[i];
    A[n] = INF;

    int k = 0, lis_end = 0;
    vi L(n+1, -1), L_id(n+1, 0);
    p.assign(n+1, -1);

    for(int i=0; i<=n; i++){
      int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
      L[pos] = A[i];
      L_id[pos] = i;
      p[i] = pos ? L_id[pos-1] : -1;
      if(pos == k){
        k = pos + 1;
        lis_end = i;
      }
    }

    cout << k-1 << " ";
    print_LIS(p[lis_end]);
    cout << endl;
  }

  return 0;
}
