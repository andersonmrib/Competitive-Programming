#include <bits/stdc++.h>
using namespace std;

int main(){

  // or... you can simply use this algorithm!
  string str;
  while(cin >> str){

    if(str == "0") break;
    int ans = 0;
    for(auto c : str)
      ans = (ans * 10 + (c - '0')) % 17;

    if(!ans) cout << 1 << endl;
    else     cout << 0 << endl;
  }

  return 0;
}
