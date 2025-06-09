#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int getVal(string name){
  int sum = 0;
  for(auto c : name)
    if(isalpha(c)) sum += tolower(c) - 'a' + 1;
  while(sum >= 10){
    int newSum = 0;
    while(sum){
      newSum += sum % 10;
      sum /= 10;
    }
    sum = newSum;
  }
  return sum;
}

int main(){

  speedBoost;
  string name1, name2;

  while(getline(cin, name1) && getline(cin, name2)){

    int sum1 = getVal(name1);
    int sum2 = getVal(name2);

    double a = max(sum1, sum2), b = min(sum1, sum2);
    cout << fixed << setprecision(2);
    cout << 100 * b / a << " %\n";
  }

  return 0;
}
