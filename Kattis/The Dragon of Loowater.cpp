#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;

int main(){

  speedBoost;
  int n, m;
  while((cin >> n >> m), (n || m)){

    vi D(n), H(m);

    for(int i=0; i<n; i++)
      cin >> D[i];
    for(int i=0; i<m; i++)
      cin >> H[i];

    sort(D.begin(), D.end());
    sort(H.begin(), H.end());

    int gold = 0, knight = 0, head = 0;
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
