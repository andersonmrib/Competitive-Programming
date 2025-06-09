#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int SumofDigits(string s){
  int sum = 0;
  for(auto c : s)
    sum += c - '0';
  return sum;
}

int main(){
  speedBoost;
  int N;
  while((cin >> N), N){

    int p = 11; // both n and p must be greater than 10

    string str1 = to_string(N);
    int digitsOfN = SumofDigits(str1);

    while(true){
      string str2 = to_string(p*N);
      int digitsOfProduct = SumofDigits(str2);
      if(digitsOfN == digitsOfProduct) break;
      else p++;
    }
    cout << p << "\n";
  }

  return 0;
}
