#include <bits/stdc++.h>
using namespace std;

int main(){

  string str;
  while(getline(cin, str)){

    int len = str.size();
    bool b = false, i = false;

    for(int j=0; j<len; j++){
      if(str[j] == '_'){
        cout << (i ? "</i>" : "<i>");
        i = !i;
      }
      else if(str[j] == '*'){
        cout << (b ? "</b>" : "<b>");
        b = !b;
      }
      else cout << str[j];
    }
    cout << endl;
  }


  return 0;
}
