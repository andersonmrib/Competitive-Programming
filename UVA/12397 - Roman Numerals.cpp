#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> myPair;

string ArabicToRoman(int a){
  string romanNumber = "";
  vector<myPair> convert({
    {1000,"M"}, {900,"CM"}, {500,"D"}, {400,"CD"}, {100,"C"}, {90,"XC"},
    {50,"L"}, {40,"XL"}, {10,"X"}, {9,"IX"}, {5,"V"}, {4,"IV"}, {1,"I"}
  });
  for(auto &[value, roman] : convert)
    while(a >= value){
    romanNumber += roman;
    a -= value;
   }
   return romanNumber;
}

int value(char letter){
  switch(letter){
    case 'I': return 1;
    case 'V': return 2;
    case 'X': return 2;
    case 'L': return 2;
    case 'C': return 2;
    case 'D': return 3;
    case 'M': return 4;
  }
  return 0;
}

int main(){

  int n;
  while(cin >> n){
        int ans = 0;
    string getRoman = (ArabicToRoman(n));

    for(auto x: getRoman)
    ans += value(x);

    cout << ans << endl;
  }

  return 0;
}
