#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

void getPreOrder(string &in, string &pre, int inStrt, int inEnd,
                  unordered_map<int, int> &umap, int &preIndex){

  if(inStrt > inEnd)
    return;

  int inIndex = umap[pre[preIndex++]];
  getPreOrder(in, pre, inStrt, inIndex-1, umap, preIndex);
  getPreOrder(in, pre, inIndex+1, inEnd, umap, preIndex);
  cout << in[inIndex];
}

int main(){

  speedBoost;
  int C; cin >> C;
  while(C--){

    int n; cin >> n;
    string preord, inord; cin >> preord >> inord;

    unordered_map<int, int> umap;
    int preIndex = 0;
    for(int i=0; i<inord.size(); i++)
      umap[inord[i]] = i;

    getPreOrder(inord, preord, 0, n-1, umap, preIndex);
    cout << "\n";
  }

  return 0;
}
