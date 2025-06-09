#include <bits/stdc++.h>
using namespace std;

int main(){

  int Ai;
  vector<int> num;
  for(int i=0; i<4; i++){
    cin >> Ai; num.push_back(Ai);
  }

  sort(num.begin(), num.end());

  if(num[0]*num[3] == num[1]*num[2])
    cout << "S\n";
  else
    cout << "N\n";

  return 0;
}
