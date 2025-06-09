#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int INF = 1e9;
const int MAX = 400;
int AM[MAX+1][MAX+1];

int main(){

  speedBoost;
  int n, m, p;
  cin >> n >> m >> p;

  for(int u=1; u<=n; u++){
    for(int v=1; v<=n; v++)
      AM[u][v] = INF;
    AM[u][u] = 0;
  }

  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b;
    AM[a][b] = 1;
    AM[b][a] = 1;
  }

  for(int k=1; k<=n; k++)
    for(int u=1; u<=n; u++)
      for(int v=1; v<=n; v++)
        AM[u][v] = min(AM[u][v], AM[u][k] + AM[k][v]);

  for(int i=0; i<p; i++){
    int k, l; cin >> k >> l;

    if(AM[k][l] < INF) cout << "Lets que lets" << endl;
    else               cout << "Deu ruim" << endl;
  }

  return 0;
}
