#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int N;
  while(cin >> N){

    string p; cin >> p;
    unordered_map<string, int> umap;

    string holdThis;
    int numMax = 0;
    for(int i=0; i<p.size()-2; i++){
        umap[p.substr(i, N)]++;
        if(umap[p.substr(i, N)] > numMax){
          numMax =  umap[p.substr(i, N)];
          holdThis = p.substr(i, N);
        }
    }

    cout << holdThis << "\n";
  }

  return 0;
}
