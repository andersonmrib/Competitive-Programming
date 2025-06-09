#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

void getPostOrder(string &pre, string &in, int inStrt, int inEnd,
                  unordered_map<int, int> &umap, int &preIndex){

  if(inStrt > inEnd)
    return;

  int inIndex = umap[pre[preIndex++]];
  getPostOrder(pre, in, inStrt, inIndex - 1, umap, preIndex);
  getPostOrder(pre, in, inIndex + 1, inEnd, umap, preIndex);
  cout << in[inIndex];
}

int main(){

  speedBoost;
  string preord, inord;
  while(cin >> preord >> inord){

    unordered_map<int, int> umap;
    int preIndex = 0;

    for(int i=0; i<inord.size(); i++)
      umap[inord[i]] = i;

    getPostOrder(preord, inord, 0, inord.size() - 1, umap, preIndex);
    cout << "\n";
  }

  return 0;
}
