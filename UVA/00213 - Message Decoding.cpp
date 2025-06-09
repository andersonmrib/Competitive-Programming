#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string header;
  while(getline(cin, header)){

    unordered_map<string, char> umap;
    for(int i=1, idx=0; i<=7; i++){
      for(int j=0; idx<header.size() && j<(1<<i)-1; j++){
        bitset<32> bs(j);
        umap[bs.to_string().substr(32-i)] = header[idx++];
      }
    }

    while(true){

      char c;
      string str;
      for(int i=0; i<3; i++)
        cin >> c, str += c;

      if(str == "000") break;
      int len = stoi(str, nullptr, 2);

      while(true){
        string message;
        for(int i=0; i<len; i++)
          cin >> c, message += c;
        if(message == string(len, '1')) break;
        cout << umap[message];
      }
    }
    cout << "\n";
    cin.ignore();
  }

  return 0;
}
