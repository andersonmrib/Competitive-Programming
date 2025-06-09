#include <bits/stdc++.h>
using namespace std;

int main(){

  int grade; cin >> grade;

  if(!grade)                           cout << "E\n";
  else if(grade >= 1  && grade <= 35 ) cout << "D\n";
  else if(grade >= 36 && grade <= 60 ) cout << "C\n";
  else if(grade >= 61 && grade <= 85 ) cout << "B\n";
  else if(grade >= 86 && grade <= 100) cout << "A\n";

  return 0;
}
