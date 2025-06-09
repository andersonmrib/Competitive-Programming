#include <bits/stdc++.h>
using namespace std;

typedef pair<string, int> si;

bool comp(si& A, si& B){
  auto &[meatA, na] = A;
  auto &[meatB, nb] = B;
  if(na != nb) return na < nb;
  return meatA > meatB;
}

int main(){

  int n;
  while(cin >> n){
    string str;
    int expirationDate;
    vector<si> vec;
    for(int i=0; i<n; i++){
      cin >> str >> expirationDate;
      vec.push_back({str, expirationDate});
    }
    sort(vec.begin(), vec.end(), comp);

  int len = vec.size();
  for(auto &[meat, num] : vec){
    if(len == 1) cout << meat << endl;
    else{
      cout << meat << " ";
      len--;
    }
   }
  }
    return 0;
}
