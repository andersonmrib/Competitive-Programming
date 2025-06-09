#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  map<string,int> mapper;
  int m, n, value;
  string str;

  while(cin >> m >> n){
    for(int i=0; i<m; i++){
        cin >> str >> value;
        mapper[str] = value; //Going to simply associate every job to it's salary
    }
    for(int i=0; i<n; i++){
    int ans = 0;
        while(cin >> str && str.compare(".") != 0)
            ans += mapper[str];
    cout << ans << endl;
    }
  }

  return 0;
}
