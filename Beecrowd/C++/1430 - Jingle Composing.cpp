#include <bits/stdc++.h>
using namespace std;

int main(){

  string jingle;
  map<char, float> note;
  note['W'] = 1.0;
  note['H'] = 0.5;
  note['Q'] = 0.25;
  note['E'] = 0.125;
  note['S'] = 0.0625;
  note['T'] = 0.03125;
  note['X'] = 0.015625;
  note['/'] = 0.0;

  while(cin >> jingle && jingle != "*"){
    int valid = 0; double sum = 0.0;

    for(auto x:jingle){
        sum += note[x];

        if(x == '/'){
            if(sum == 1.0) valid++;
                sum = 0.0;
        }
    }
    cout << valid << endl;
  }

  return 0;
}
