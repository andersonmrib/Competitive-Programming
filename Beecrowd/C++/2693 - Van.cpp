#include <bits/stdc++.h>
using namespace std;

typedef tuple<string, char, int> tup;

bool comp(tup &A, tup &B){
  auto &[Aa, Sa, Ca] = A;
  auto &[Ab, Sb, Cb] = B;
  if(Ca != Cb) return Ca < Cb;
  if(Sa != Sb) return Sa < Sb;
  return false;
}

int main(){

  int q;

  while(cin >> q){

    vector<tup> vec;
    for(int i=0; i<q; i++){
      string name;
      char s;
      int cost;
      cin >> name >> s >> cost;
      vec.push_back({name, s, cost});
    }

    sort(vec.begin(), vec.end(), comp);

    for(auto &[n, s, c] : vec)
      cout << n << endl;
  }

    return 0;
}

