#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

int main(){

  ll n;
  while(scanf("%lld", &n), n){
    unordered_map<ll, ll> frequency; //Holds the number ans his frequency in the array. No need for ordered map
    ll A;
    for(int i=0; i<n; i++){
        scanf("%lld", &A);
        frequency[A]++;
    }

    ll lonelyNumber;
    for(auto peer: frequency){
        if(peer.second % 2 == 1)
        lonelyNumber = peer.first;
    }

    cout << lonelyNumber << endl;
  }

  return 0;
}
