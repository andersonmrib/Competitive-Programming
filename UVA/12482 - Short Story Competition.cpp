#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int N, L, C;
  while(cin >> N >> L >> C){

    int pages = 1, lines = 1, curLen = -1; // curLen as we don't have a space
    for(int i=0; i<N; i++){                // in the first word of the story
      string word; cin >> word;
      int len = word.size();

      if(curLen + len + 1 <= C)
        curLen += + len + 1;
      else{
        curLen = len;
        lines++; // we need one extra line
      }
      if(lines > L){
        lines = 1, pages++;
      }
    }

    cout << pages << "\n";
  }

  return 0;
}
