#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

#define PERIOD 300
typedef long long ll;
int fib[PERIOD], prefix_fib[PERIOD]; // [0..299]

void build(){
  int a = 0, b = 1, sum = 0;
  for(int i=0; i<PERIOD; i++){
    fib[i] = a;
    sum = sum + a;
    prefix_fib[i] = sum;

    int next = (a + b)%100;
    a = b;
    b = next;
  }
}

ll rangeQuery(ll N){
  ll q = N / PERIOD, r = N % PERIOD;
  return q * prefix_fib[PERIOD-1] + prefix_fib[r];
}

int main(){

  speedBoost;
  build();

  int t; cin >> t;
  while(t--){

    ll n, m; cin >> n >> m;
    cout << rangeQuery(m) - rangeQuery(n-1) << "\n";
  }

  return 0;
}
