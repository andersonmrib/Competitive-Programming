#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  int n; cin >> n;
  while(n--){
    int num1, num2, result, realResult;
    string op, equals;
    cin >> num1 >> op >> num2 >> equals >> result;

    if(op == "+")      realResult = num1 + num2;
    else if(op == "x") realResult = num1 * num2;
    else if(op == "-") realResult = num1 - num2;

    realResult = realResult - result;
    if(realResult < 0) realResult = abs(realResult);

    cout << "E";
    while(realResult--) cout << 'r';
    cout << "ou!" << endl;
  }

  return 0;
}
