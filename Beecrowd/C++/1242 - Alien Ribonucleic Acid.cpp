#include <bits/stdc++.h>
using namespace std;

int main(){

  string str;
  while(cin >> str){
    stack<char> RNA;

    int ans = 0;
    for(int i=0; i<str.size(); i++){
      if(RNA.empty()) RNA.push(str[i]);
      else if(RNA.top() == 'B' && str[i] == 'S' || RNA.top() == 'S' && str[i] == 'B'){
        ans++;
        RNA.pop();
      }
      else if(RNA.top() == 'F' && str[i] == 'C' || RNA.top() == 'C' && str[i] == 'F'){
        ans++;
        RNA.pop();
      }
      else RNA.push(str[i]);
    }
    cout << ans << endl;
  }

  return 0;
}
