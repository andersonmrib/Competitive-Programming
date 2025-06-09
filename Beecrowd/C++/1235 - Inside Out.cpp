#include <bits/stdc++.h>
using namespace std;

int main (){

  int n; scanf("%d", &n);
  string str;
  cin.ignore(); //Don't creates extra lines for using cin function

  while(n--){
    getline(cin, str);

    reverse(str.begin(), str.begin() + str.length()/2);
    reverse(str.begin() + str.length()/2, str.end());

    cout << str << endl;
  }

  return 0;
}
