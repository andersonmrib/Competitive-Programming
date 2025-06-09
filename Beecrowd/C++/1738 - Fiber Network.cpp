#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int INF = 1e9;
const int MAX = 201;
int AM[MAX][MAX][26];        // one more dimension for letters

int main(){

  speedBoost;
  int n, u, v;
  while((cin >> n), n){

  for(int u=0; u<n; u++){
    for(int v=0; v<n; v++)
      for(int k=0; k<26; k++)
        AM[u][v][k] = INF;   // simple matrix initialization
    AM[u][u][0] = 0;
  }

  while((cin >> u >> v), (u||v)){
    string str; cin >> str;
    u--, v--;                // remember to decrease indexes
    for(auto c : str)        // marks every letter of the connection as 1
      AM[u][v][c - 'a'] = 1;
  }

  for(int l=0; l<26; l++)
    for(int k=0; k<n; k++)
      for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
          AM[i][j][l]= min(AM[i][j][l], AM[i][k][l] + AM[k][j][l]);
          // O(N^4) algorithm, careful with the time limit...

  while((cin >> u >> v), (u||v)){
    u--, v--;
    bool flag = false;
    for(int i=0; i<26; i++){
      if(AM[u][v][i] < INF){
        cout << (char)(i + 'a');
        flag = true;         // there is at least one company
      }
    }
    if(!flag) cout << '-';
    cout << endl;
  }
  cout << endl;
 }

  return 0;
}
