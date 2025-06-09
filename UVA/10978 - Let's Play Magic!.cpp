#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  int n;
  while((cin >> n), n){
    vector<string> vec(n, "");

    int index = 0;
    for(int i=0; i<n; i++){

      string card, word; cin >> card >> word;
      int len = word.size();

      int coun = 0;
      while(coun < len){
        if(vec[index] == "")
          coun++;
        if(coun < len)
          index = (index + 1) % n;
      }

      vec[index] = card;
      index = (index + 1) % n;
    }

    for(int i=0; i<n; i++){
      if(i == 0) cout << vec[i];
      else       cout << " " << vec[i];
    }
    cout << "\n";
  }

  return 0;
}
