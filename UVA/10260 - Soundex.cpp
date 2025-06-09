#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string code;
  while(getline(cin, code)){

    char last = '0';
    for(auto c : code){

      char current = '0';
      if(c == 'B' || c == 'F' || c == 'P' || c == 'V')
        current = '1';
      else if(c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' ||
              c == 'S' || c == 'X' || c == 'Z')
        current = '2';
      else if(c == 'D' || c == 'T')
        current = '3';
      else if(c == 'L')
        current = '4';
      else if(c == 'M' || c == 'N')
        current = '5';
      else if(c == 'R')
        current = '6';

      if(current != '0' && current != last)
        cout << current;
      last = current;
    }
    cout << "\n";
  }

  return 0;
}
