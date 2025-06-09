#include <bits/stdc++.h>
using namespace std;

int main(){

  string str; cin >> str;
  if(str.find("13") != string::npos)
    cout << str << " es de Mala Suerte\n";
  else
    cout << str << " NO es de Mala Suerte\n";

  return 0;
}
