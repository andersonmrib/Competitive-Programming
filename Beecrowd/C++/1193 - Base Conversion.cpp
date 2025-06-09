#include <bits/stdc++.h>
using namespace std;

string decToBin(int n){
  if(!n) return "0";
  string str;
  while(n){

    int remainder = n%2;
    if(!remainder)
      str.push_back('0');
    else
      str.push_back('1');

    n /= 2;
  }

  reverse(str.begin(), str.end());
  return str;
}

string decToHex(int n){
  if(!n) return "0";
  string str;
  while(n){

    int remainder = n%16;

    if(remainder < 10) str.push_back(remainder + '0');
    else               str.push_back(remainder - 10 + 'a');

    n /= 16;
  }
  reverse(str.begin(), str.end());
  return str;
}

int main(){

  int TC; cin >> TC; cin.ignore();
  int numC = 0;
  while(TC--){

    printf("Case %d:\n", ++numC);
    string toConvert; getline(cin, toConvert);
    stringstream ss(toConvert);

    string number, base;
    ss >> number >> base;

    if(base[0] == 'b'){
      printf("%d dec\n", stoi(number, nullptr, 2));
      printf("%s hex\n\n", decToHex(stoi(number, nullptr, 2)).c_str());
    }
    else if(base[0] == 'd'){
      printf("%s hex\n", decToHex(stoi(number)).c_str());
      printf("%s bin\n\n", decToBin(stoi(number)).c_str());
    }
    else if(base[0] == 'h'){
      printf("%d dec\n", stoi(number, nullptr, 16));
      printf("%s bin\n\n", decToBin(stoi(number, nullptr, 16)).c_str());
    }
  }

    return 0;
}
