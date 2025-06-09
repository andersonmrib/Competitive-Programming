#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){

  int n, k;
  while(cin >> n >> k){

    vector<int> grades;
    int note;
    for(int i=0; i<n; i++){
      cin >> note;
      grades.push_back(note);
    }

    sort(grades.rbegin(), grades.rend());

    int coun = 0;
    for(auto x : grades){
      if(k == 0) break;
      coun = (coun+x)%MOD;
      k--;
    }
    cout << coun << endl;
  }

  return 0;
}
