#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

vector<string> validWords;
unordered_map<string, int> umap;

void backtrack(string &cur, char lastChar, int targetLen){

  if((int)cur.size() == targetLen){
    validWords.push_back(cur);
    return;
  }

  for(int c=lastChar + 1; c<='z'; c++){
    cur.push_back(c);
    backtrack(cur, c, targetLen);
    cur.pop_back();
  }
}

int main(){

  speedBoost;

  string cur;
  for(int len=1; len<=5; len++)
    backtrack(cur, 'a' - 1 , len);

  for(int i=0; i<validWords.size(); i++)
    umap[validWords[i]] = i + 1;

  string query;
  while(cin >> query){

    if(umap.find(query) == umap.end())
      cout << 0 << endl;
    else
      cout << umap[query] << endl;
  }

  return 0;
}
