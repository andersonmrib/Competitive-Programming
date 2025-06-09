#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string number;
  while(cin >> number){
    if(number == "0") break;

    int mod = 0;
    for(auto x : number)
      mod = (mod * 10 + x - '0') % 9;


    if(mod != 0){
      cout << number << " is not a multiple of 9.\n";
      continue;
    }
        // Now, try to compute how many times we can divide
        // the number using 9.
        int sum = 0, degree = 0;
        for(auto x : number) sum += x - '0';

        while(sum%9 == 0){
          degree++;
          if(sum == 9) break; // Try to avoid infinite loop
          int new_sum = 0;
          while(sum){
            new_sum += sum%10;
            sum /= 10;
          }
          sum = new_sum;
        }
        cout << number << " is a multiple of 9 and has 9-degree " << degree << ".\n";
  }

  return 0;
}
