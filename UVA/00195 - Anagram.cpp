#include <bits/stdc++.h>
using namespace std;

bool cmp(const char a, const char b){
  if(tolower(a) < tolower(b)) return true;   // trivial case, alphabetical order
  if(tolower(a) == tolower(b)) return a < b; // increasing order ('A' goes first)
  return false;
}

int main(){

  int n; cin >> n;
  string str;
  while(n--){
    cin >> str;

    sort(str.begin(), str.end(), cmp);
    do{
      cout << str << endl;
    }while(next_permutation(str.begin(), str.end(), cmp));
  }


    return 0;
}
