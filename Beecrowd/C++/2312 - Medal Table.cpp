#include <bits/stdc++.h>
using namespace std;

typedef tuple<string, int, int, int> tup;

bool comp(tup &A, tup &B){
  auto &[countryA, goldA, silverA, bronzeA] = A;
  auto &[countryB, goldB, silverB, bronzeB] = B;
  if(goldA != goldB)     return goldA > goldB;
  if(silverA != silverB) return silverA > silverB;
  if(bronzeA != bronzeB) return bronzeA > bronzeB;
  return countryA < countryB;
}

int main(){

  int n; cin >> n;

  vector<tup> vec;
  for(int i=0; i<n; i++){
    string name;
    int g, s, b;
    cin >> name >> g >> s >> b;
    vec.push_back({name, g, s, b});
  }

  sort(vec.begin(), vec.end(), comp);

  for(auto &[coun, gold, silver, bronze] : vec)
    cout << coun << " " << gold << " " << silver << " " << bronze << endl;

  return 0;
}
