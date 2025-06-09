#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

bitset<10000010> bs;
vll p;
ll _sieve_size;

void sieve(ll upperbound){
  _sieve_size = upperbound+1;
  bs.set();
  bs[0] = bs[1] = 0;
  for(ll i=2; i<_sieve_size; i++) if(bs[i]){
    for(ll j=i*i; j<_sieve_size; j+=i)
      bs[j] = 0;
    p.push_back(i);
  }
}

int main(){

  speedBoost;
  p.push_back(1);
  sieve(1000);

  int n, c;
  while(cin >> n >> c){
    int i = lower_bound(p.begin(), p.end(), n) - p.begin();

    while(i >= p.size() || p[i] > n) i--;

    int listSize = i+1;

    int numToPrint;
    if(listSize&1) numToPrint = 2*c-1;
    else           numToPrint = 2*c;

    int startIdx = (listSize - numToPrint) > 0 ? (listSize-numToPrint)/2 : 0;
    int endIdx = startIdx + numToPrint;
    if(numToPrint > listSize) endIdx = listSize;

    printf("%d %d:", n, c);
    for(int j=startIdx; j<endIdx; j++)
      printf(" %d", p[j]);
    printf("\n\n");
  }

  return 0;
}
