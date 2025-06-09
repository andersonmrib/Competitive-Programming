#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int INF = 1e9;

int main(){

  speedBoost;
  int L, U, R;
  int numCases = 0;
  while((cin >> L >> U >> R), (L || U || R)){

    vector<int> buttons(R);
    for(int i=0; i<R; i++) cin >> buttons[i];

    int ans = 0;
    vector<int> dist(10000, INF);
    queue<int> q; q.push(L);
    dist[L] = 0;

    bool hasSolution = false;
    while(!q.empty()){

      int curr = q.front(); q.pop();
      if(curr == U){
        hasSolution = true;
        cout << "Case " << ++numCases << ": " << dist[curr] << "\n";
        break;
      }

      for(auto b : buttons){
        int next = (curr + b)%10000;
        if(dist[next] == INF){
          dist[next] = dist[curr] + 1;
          q.push(next);
        }
      }
    }

    if(!hasSolution) cout << "Case " << ++numCases << ": Permanently Locked\n";
  }

  return 0;
}
