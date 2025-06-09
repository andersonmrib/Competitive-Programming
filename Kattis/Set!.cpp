#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tup;

bool check(string a, string b, string c){

  int common = 0;
  int different = 0;

  // at least 1 common type
  // we cannot have 2 common types and 1 different as all must be different
  for(int i=0; i<4; i++){
    if(a[i] == b[i] && b[i] == c[i]) common++;
    if(a[i] != b[i] && b[i] != c[i] && a[i] != c[i]) different++;
  }

  if(common+different == 4) return true;
  return false;
}

int main(){

  vector<string> vec;
  vector<tup> possible;

  for(int i=0; i<12; i++){
    string str;
    cin >> str;
    vec.push_back(str);
  }

  for(int i=0; i<10; i++){
    for(int j=i+1; j<11; j++){
      for(int k=j+1; k<12; k++){
        if(check(vec[i], vec[j], vec[k]))
          possible.push_back({i+1, j+1, k+1});
      }
    }
  }

  for(auto &[n1, n2, n3] : possible)
    cout << n1 << " " << n2 << " " << n3 << endl;

  if(!possible.size())
     cout << "no sets\n";

  return 0;
}
