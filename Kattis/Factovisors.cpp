#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int vp(int p, int n){
  int ans = 0;
  for(int pi=p; pi<=n; pi*=p)
    ans += n/pi;
  return ans;
}

int main(){

  speedBoost;
  int n, m;
  while(cin >> n >> m){
    bool hasSolution;

    if(m == 0){
      cout << m << " does not divide " << n << "!\n";
      continue;
    }

    else if(m <= n){
      cout << m << " divides " << n << "!\n";
      continue;
    }

    unordered_map<int, int> umap;
    int temp = m;
    ll PF = 2;
    while((temp > 1) && (ll)(PF*PF <= m)){
      int frequency = 0;
      while(temp%PF == 0){
        frequency++;
        temp /= PF;
      }
      if(frequency > 0) umap[PF] = frequency;
      PF++;
    }
    if(temp > 1) umap[temp] = 1;

    hasSolution = true;
    for(auto &[p, e] : umap){
      if(vp(p, n) < e){
        hasSolution = false;
        break;
      }
    }
      if(hasSolution) cout << m << " divides " << n << "!\n";
      else            cout << m << " does not divide " << n << "!\n";
  }

  return 0;
}