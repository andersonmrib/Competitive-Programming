#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int N, M;
  while((cin >> N >> M), (N || M)){

    int ans = 0;
    unordered_map<int, int> freq;
    for(int i=0; i<N+M; i++){
      int cd; cin >> cd;
      if(++freq[cd] == 2) ans++;
    }

    cout << ans << "\n";
  }

  return 0;
}
