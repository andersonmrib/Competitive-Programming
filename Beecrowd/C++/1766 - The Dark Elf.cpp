#include <bits/stdc++.h>
using namespace std;
// weight descending - age and height ascending - name order
typedef tuple<int, int, float, string> tup;

bool comp(tup& A, tup& B){       // KISS - keep it short and simple... and elegant!
  auto &[Wa, Aa, Ha, namea] = A;
  auto &[Wb, Ab, Hb, nameb] = B;
  if(Wa != Wb) return Wa > Wb;   // descending weight
  if(Aa != Ab) return Aa < Ab;   // ascending age and...
  if(Ha != Hb) return Ha < Hb;   // ... height
  return (namea < nameb);        // alphabetical order
}

int main(){

  int numCases = 0;
  int t; cin >> t;
  while(t--){
    int n, m; cin >> n >> m;
    vector<tup> vec;
    for(int i=0; i<n; i++){

      int w, a;
      float h;
      string name;

      cin >> name >> w >> a >> h;
      vec.push_back({w, a, h, name});
    }

    sort(vec.begin(), vec.end(), comp);

    int inc = 0;
    cout << "CENARIO {" << ++numCases << "}\n";
    for(auto &[w, a, h, n] : vec){
      if(!m) break;
      cout << ++inc << " - " << n << endl;
      m--;
    }
  }

  return 0;
}
