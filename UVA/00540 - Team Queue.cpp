#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define F(i, L, R) for(int i=L; i<R; i++)
#define FR(i, R, L) for(int i=R; i>0; i--)
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int main(){

  speedBoost;
  int t;
  int NC = 1;
  while(cin >> t, t){

    cout << "Scenario #" << NC++ << endl;
    vector<queue<int>> team(t);
    unordered_map<int, int> belong;
    for(int i=0; i<t; i++){
      int n; cin >> n;
      for(int j=0; j<n; j++){
        int x; cin >> x;
        belong[x] = i;
      }
    }

    queue<int> teamQueue;
    string op;
    while(cin >> op){

      if(op == "STOP") break;

      else if(op == "ENQUEUE"){

        int x; cin >> x;
        int id = belong[x];

        if(team[id].empty())
          teamQueue.push(id);

        team[id].push(x);
      }

      else{

        int id = teamQueue.front();
        int toRemove = team[id].front();
        team[id].pop();

        cout << toRemove << endl;

        if(team[id].empty())
          teamQueue.pop();
      }
    }
    cout << endl;
  }

  return 0;
}
