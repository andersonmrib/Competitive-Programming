#include <bits/stdc++.h>
using namespace std;

int main(){

 set<string> collection;
 string jewelry;
 while(cin >> jewelry) collection.insert(jewelry);

 cout << collection.size() << endl;

  return 0;
}
