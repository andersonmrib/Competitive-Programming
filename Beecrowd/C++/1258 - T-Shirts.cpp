#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef struct{
  string color;
  string size;
  string name;
}shirt;

bool compareShirts(shirt a, shirt b){ // going to help us ordering the vector of structures
  if(a.color == b.color){
    if(a.size == b.size){
        return a.name < b.name;
    }
    return a.size > b.size;
  }
  return a.color < b.color;
}

int main(){

  int n;
  bool first = true;
  while(cin >> n, n){
    cin.ignore();       // ! - important - !

    if(first) first = false;
    else cout << endl;

    vector<shirt> shirts;
    shirts.assign(n, shirt());
    for(int i=0; i<n; i++){
        getline(cin, shirts[i].name);
        cin >> shirts[i].color >> shirts[i].size;
        cin.ignore();   // ! - important - !
    }
    sort(shirts.begin(), shirts.end(), compareShirts);

    for(int i=0; i<n; i++)
        cout << shirts[i].color << " " << shirts[i].size << " " << shirts[i].name << endl;
  }

  return 0;
}
