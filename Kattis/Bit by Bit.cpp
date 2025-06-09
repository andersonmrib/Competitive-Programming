#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n;
  while((cin >> n), n){

    cin.ignore();
    string number(32, '?');

    while(n--){
      string op;
      int bit1, bit2;
      cin >> op;

      if(op[0] == 'S'){
        cin >> bit1;
        number[bit1] = '1';
      }
      if(op[0] == 'C'){
        cin >> bit1;
        number[bit1] = '0';
      }
      if(op[0] == 'A'){
        cin >> bit1 >> bit2;
        if(number[bit1] == '0' || number[bit2] == '0') number[bit1] = '0'; // base case
        else if((number[bit1] == '?' || number[bit2] == '?')) number[bit1] = '?';
        else number[bit1] = ((number[bit1] - '0') & (number[bit2] - '0')) + '0';
      }
      if(op[0] == 'O'){
        cin >> bit1 >> bit2;
        if(number[bit1] == '1' || number[bit2] == '1') number[bit1] = '1'; // base case
        else if(number[bit1] == '?' && number[bit2] == '?') number[bit1] = '?';
        else number[bit1] = ((number[bit1] - '0') | (number[bit2] - '0')) + '0';
      }
    }

    reverse(number.begin(), number.end());
    for(auto c : number) cout << c;
    cout << endl;
  }

    return 0;
}
