#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
vi p, A;

void print_LIS(int i){
  if(p[i] == -1) { cout << A[i]; return; }
  print_LIS(p[i]);
  cout << " " << A[i];
}

int main(){

  speedBoost;
  int n;
  while(cin >> n){

    A.assign(n, 0);
    for(int i=0; i<n; i++){
      int num; cin >> num;
      A[i] = num;
    }

    int k = 0, lis_end = 0;
    vi L(n, 0), L_id(n, 0);
    p.assign(n, -1);

    for(int i=0; i<n; i++){
      int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
      L[pos] = A[i];
      L_id[pos] = i;
      p[i] = pos ? L_id[pos-1] : -1;
      if(pos == k){
        k = pos + 1;
        lis_end = i;
      }
    }

    vi indexes;
    for(int i=lis_end; i != -1; i=p[i]) // here lies the hardest
      indexes.push_back(i);             // part of the exercise :)

    reverse(indexes.begin(), indexes.end());

    cout << k << endl;

    bool first = true;
    for(auto idx : indexes){
      if(first) cout << idx;
      else      cout << " " << idx;
      first = false;
    }
    cout << endl;
  }

  return 0;
}
