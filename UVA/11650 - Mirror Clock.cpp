#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    string time; cin >> time;
    int h, m;
    sscanf(time.c_str(), "%d:%d", &h, &m);

    if(!m){
      h = 12 - h;
      if(!h) h = 12;
    }
    else{
      m = 60 - m;
      h = 11 - h;
      if(h <= 0) h += 12;
    }
    printf("%.02d:%.02d\n", h, m);
  }

  return 0;
}
