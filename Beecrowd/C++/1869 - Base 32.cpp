#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main(){

  ull n;
  while((cin >> n)){

  if(!n){
    cout << "0" << endl;
    break;
  }

  string str;
  while(n){
    int remainder = n%32;

    if(remainder < 10) str.push_back(remainder + '0');
    else               str.push_back(remainder - 10 + 'A');

    n /= 32;
  }
  reverse(str.begin(), str.end());
  cout << str << endl;
 }

  return 0;
}
