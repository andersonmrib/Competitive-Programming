#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int N = 27;
const int INF = 1e9;
typedef vector<int> vi;

int main(){

  speedBoost;
  string s;
  while(cin >> s){

    vector<vi> g(N, vi(N));
    vi deg(26, 0);
    for(int i=0; i<26; i++){
      for(int j=0; j<26; j++)
        g[i][j] = INF;
      g[i][i] = 0;
    }

    int sum  = 0;
    while(s != "deadend"){
      int u = s[0] - 'a', v = s.back() - 'a', w = s.size();
      g[u][v] = w;
      g[v][u] = w;
      deg[u]++, deg[v]++;
      sum += w;
      cin >> s;
    }

    int checkDeg = 0, start, end;
    for(int i=0; i<26; i++){
      if(deg[i]&1){
        start = end;
        end = i;
        checkDeg++;
      }
    }

    if(checkDeg == 2){ // Must be only 2
      for(int k=0; k<26; k++)
        for(int i=0; i<26; i++)
          for(int j=0; j<26; j++)
            g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

      sum += g[start][end]; // Must add one new road for
      cout << sum << "\n";  // the property of Euler.
    }
    else
      cout << sum << "\n";
  }

  return 0;
}
