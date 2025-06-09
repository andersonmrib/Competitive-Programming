#include <bits/stdc++.h>
using namespace std;

int main(){

  int c; cin >> c;
  cin.ignore();

  while(c--){
    string str; cin >> str;

    int firstPart = 0, secondPart = 0;
    bool f = true, s = false;

    for(int i=0; i<str.size(); i++){
      if(f && str[i] == 'a') firstPart++;
      else if(str[i] == 'k'){
        f = false, s = true;
      }
      else if(s && str[i] == 'a') secondPart++;
    }

    int quantity = firstPart * secondPart;

    cout << "k";
    while(quantity--) cout << 'a';
    cout << endl;
  }

  return 0;
}
