#include <bits/stdc++.h>
using namespace std;

int main(){

  int p;
  string str;
  queue<string> east, west, north, south;

  cin >> p;
  while(p != 0 )
  {
      cin >> str;
      if(str == "-1" || str == "-2" || str == "-3" || str == "-4" || str == "0"){
        p = stoi(str);
        continue;
      }

      if(p == -4) east.push ({str});
      if(p == -3) north.push({str});
      if(p == -2) south.push({str});
      if(p == -1) west.push ({str});
  }

  int maxSize = east.size() + north.size() + south.size() + west.size();

   while (!east.empty() || !west.empty() || !north.empty() || !south.empty())
   {
        if (!west.empty()) {
            cout << west.front();
            west.pop();
            maxSize--;
            if(maxSize > 0) cout << " ";
        }
        if (!north.empty()) {
            cout << north.front();
            north.pop();
            maxSize--;
            if(maxSize > 0) cout << " ";
        }
        if (!south.empty()) {
            cout << south.front();
            south.pop();
            maxSize--;
            if(maxSize > 0) cout << " ";
        }
        if (!east.empty()) {
            cout << east.front();
            east.pop();
            maxSize--;
            if(maxSize > 0) cout << " ";
        }
    }
    cout << endl;

  return 0;
}
