#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  while(cin >> n){
    set<string> books;
    string str;

    for(int i=0; i<n; i++){
      cin >> str;
      books.insert(str);
    }

    for(auto s : books)
      cout << s << endl;
  }

  return 0;
}
