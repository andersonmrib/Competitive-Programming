#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

typedef vector<int> vi;
vector<vi> AL;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int P; cin >> P;
    cin.ignore();

    AL.assign(P, vi());
    vi neigh(P, 0);
    int lowest = 1e9;

    for(int i=0; i<P; i++){
      string line;
      getline(cin, line);
      stringstream ss(line);
      int v;

      int cur_nei = 0;
      while(ss >> v)
        cur_nei++;

      neigh[i] = cur_nei;
      lowest = min(lowest, neigh[i]);
    }

    bool first = true;
    for(int i=0; i<P; i++){
      if(neigh[i] == lowest){
        if(!first)
          cout << " ";

        cout << i + 1;
        first = false;
      }
    }
    cout << endl;
  }

  return 0;
}
