#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef pair<int, int> ii;

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<ii, null_type, less<ii>, rb_tree_tag,
             tree_order_statistics_node_update> ost;

int main(){

  speedBoost
  unordered_map<int, int> umap;                   // use a map since we can have duplicated items
  ost tree;


  string str;
  while(cin >> str){

    if(str == "#"){
      int curSize = tree.size();
      ii grabThis = *tree.find_by_order(curSize/2); // always delete the half element
      cout << grabThis.first << endl;               // try to see the 0 indexing pattern
      tree.erase(grabThis);
    }
    else{
      int add = stoi(str);
      tree.insert({add, umap[add]});
      umap[add]++;
    }
  }

  return 0;
}
