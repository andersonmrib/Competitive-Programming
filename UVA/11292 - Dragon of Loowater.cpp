#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n, m;

  while((cin >> n >> m), (n || m)){

    vector<int> D(n), H(m);

    for(int i=0; i<n; i++)
      cin >> D[i];

    for(int i=0; i<m; i++)
      cin >> H[i];

      sort(H.begin(), H.end());
      sort(D.begin(), D.end());

      int gold = 0, head = 0, knight = 0;
      while((head < n) && (knight < m)){
        while((knight < m) && (D[head] > H[knight])) knight++;
        if(knight == m) break;
        gold += H[knight];
        head++, knight++;
      }

      if(head == n) cout << gold << "\n";
      else          cout << "Loowater is doomed!\n";
  }

  return 0;
}
