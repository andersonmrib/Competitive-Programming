#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  int n; cin >> n;
  cin.ignore();
  while(n--){

    set<string> shopList;

    string text, word;
    getline(cin, text);

    stringstream ss(text);
    while(ss >> word){
        shopList.insert(word);
    }

    int size = shopList.size();
    for(auto w : shopList){
        if(size > 1) cout << w << " ";
        else         cout << w;
        size--;
    }
    cout << endl;
  }
  return 0;
}
