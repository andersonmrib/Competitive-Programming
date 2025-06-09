#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n; cin >> n;
  string one = "one";

  while(n--){
    int counter = 0;
    string word; cin >> word;
    if(word.size() == 5) cout << 3 << endl;
    else{
      for(int i=0; i<word.size(); i++)
        if(word[i] == one[i]) counter++;
      if(counter > 1) cout << 1 << endl;
      else            cout << 2 << endl;
    }
  }

  return 0;
}
