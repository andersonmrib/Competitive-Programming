#include <bits/stdc++.h>
using namespace std;

int main(){

  int h;
  string command;

  cin >> h >> command;

  int index = 1; // currently in root

  for(auto c : command){
    index = index*2;
    if(c == 'R') index++;
  }

  cout << (1<<h+1)-index << endl;

  return 0;
}
